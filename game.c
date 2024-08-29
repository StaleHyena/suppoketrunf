#include "game.h"

player_t player_alloc(stack_t *take_pile, size_t card_cnt, player_driver_fptr driver) {
  player_t r = {0};
  for (r.card_cnt = 0; r.card_cnt < card_cnt; r.card_cnt++) {
    int pid;
    *take_pile = stack_pop(*take_pile, &pid);
    r.hand = stack_push(r.hand, pid);
  }
  r.winnings = NULL;
  r.driver = driver;
  return r;
}

void player_free(player_t *p) {
  if (p->winnings) stack_free(p->winnings);
  if (p->hand) stack_free(p->hand);
}

// Returns how big the new hand is
int player_extrahand(player_t* p) {
  if (!p->winnings) return 0;
  int total = 0;
  stack_value_t pid = -1;
  do {
    p->winnings = stack_pop(p->winnings, &pid);
    p->hand = stack_push(p->hand, pid);
    total++;
  } while (p->winnings);
  p->card_cnt = total;
  p->winnings = NULL;
  return total;
}

char *player_repr_sall(player_t* p) {
#define PRMAX 256
  static char buf[PRMAX] = {0};
  int tcpid = 0;
  int has_cards = stack_peek(p->hand, &tcpid);
  size_t off = 0;
  off += snprintf(buf+off, PRMAX-off,
      "carta topo %s%s, com %zu+%zu cartas na mão.",
      has_cards? "é " : "não existe",
      has_cards? pokecard_repr_simplestr_salloc(tcpid) : "",
      p->card_cnt, p->winnings? stack_size(p->winnings) : 0
    );
  return buf;
#undef PRMAX
}

char * game_repr_sall(game_t* g) {
#define GRMAX 8192
  static char buf[GRMAX] = {0};
  size_t cards_with_players = 0;
  size_t cards_on_table = stack_size(g->draw_winnings);
  for (int i = 0; i < g->player_cnt; i++) {
    player_t *p = g->players + i;
    cards_with_players += stack_size(p->hand);
    cards_with_players += stack_size(p->winnings);
  }
  size_t off = 0;
  off += snprintf(buf+off, GRMAX-off, "jogo com %d jogadores, (%d+%d) cartas em jogo (%s):\n",
      g->player_cnt,
      cards_with_players,
      cards_on_table,
      g->state == GAME_RUN? "rodando"
      : g->state == GAME_RUN_DRAW? "rodando (desempate)"
      : g->state == GAME_STOP? "parado"
      : "estado desconhecido");
  for (int i = 0; i < g->player_cnt; i++) {
    assert(off < GRMAX);
    off += snprintf(buf+off, GRMAX-off,
        "  jogador %d%s: %s\n",
        i, 
        BIT_GET(g->playing_bitmask, i)?
          BIT_GET(g->draw_bitmask, i)?
            " (empatado)"
          : "           "
        : "     (fora)",
        player_repr_sall(g->players + i)
      );
  }
  assert(off < GRMAX);
  snprintf(buf+off, GRMAX-off, "próximo a jogar pode ser o jogador %d.\n", g->player_active);

  return buf;
#undef GRMAX
}

void game_check_wincond(game_t *g) {
  int players_left = 0;
  int last_player_found = -1;
  for (int i = 0; i < g->player_cnt; i++) {
    if (BIT_GET(g->playing_bitmask, i)) {
      players_left++;
      last_player_found = i;
    }
  }

  if (players_left == 1) {
    if (last_player_found < 0) {
      printf("Ninguém ganhou! (?)\n");
      g->state = GAME_STOP;
    }
    player_t *p = g->players + last_player_found;
    assert(p->card_cnt + stack_size(p->winnings) == g->total_cards);
    printf("O jogador #%d ganhou esse jogo! Parabéns.\n", last_player_found);
    g->state = GAME_STOP;
  }
}

typedef struct {
  int winner_player;
  int winner_pokemon;
  int choice;
  const char *stat_name;
  stack_t winnings;
} round_result_t;

round_result_t game_calc_round(game_t *g, int players_bitmask, stack_t winnings) {
  // Make sure the active player is part of the round
  
  round_result_t r = {0};
  if(!BIT_GET(players_bitmask, g->player_active)){
    printf("Todo mundo perdeu (descartes maligno)\n");
    exit(EXIT_FAILURE);
  }

  player_t *p2play = g->players + g->player_active;
  // The player takes his pick of stat
  int cpid = 0;
  // always will have a card, since it's guaranteed to be an active player
  stack_peek(p2play->hand, &cpid);
  r.choice = p2play->driver(cpid);
  if (!r.choice) {
    printf("Erro ao interpretar escolha do jogador #%d, cancelando round.\n",
        g->player_active);
    g->state = GAME_CANCEL_ROUND;
    return r;
  } else if (r.choice < 0) {
    printf("Jogador #%d saiu, encerrando jogo.\n",
      g->player_active);
    g->state = GAME_STOP;
    return r;
  }
  r.stat_name =
      r.choice == 1? "HP"
    : r.choice == 2? "ATK"
    : r.choice == 3? "DEF"
    : r.choice == 4? "SP. ATK"
    : r.choice == 5? "SP. DEF"
    : "UNK STAT";

  printf("Jogador #%d selecionou a estatística %s!\n", g->player_active, r.stat_name);

  // And the round winner is decided,
  // while checking for possible draws
  r.winner_player = -1;
  g->draw_bitmask = 0;

  uint16_t best_bitmask = 0;
  int best = -1;
  uint16_t legendary_bitmask = 0;
  
  int pid_store[MAX_PLAYERS] = {-1};
  int val_store[MAX_PLAYERS] = {-1};
  int max_name_len = 0;
  for (int i = 0; i < g->player_cnt; i++) {
    if (!BIT_GET(players_bitmask, i)) continue;
    player_t *p = g->players + i;
    p->hand = stack_pop(p->hand, &pid_store[i]);
    p->card_cnt--;
    winnings = stack_push(winnings, pid_store[i]);
    pokemon_stats_t ps = pokemon_stats[pid_store[i]];

    // modular momento
    int val =
      (r.choice < sizeof(ps.stats)/sizeof(ps.stats[0]) && r.choice >= 0) ? ps.stats[r.choice-1] : -1;

    val_store[i] = val;

    int nlen = strlen(pokemon_names[pid_store[i]]);
    max_name_len = (nlen > max_name_len)? nlen : max_name_len;

    int is_best = 0;
    int is_draw = 0;
    
    int diff = val - best;
    
    if (ps.legendary) {
      legendary_bitmask = BIT_SET(legendary_bitmask, i);
    }

    int leg_found = legendary_bitmask > 0;
    int best_is_leg = BIT_GET(legendary_bitmask, r.winner_player);
    is_best = 0
      || (ps.legendary && !best_is_leg) // legendary beats lower rarities
      || (diff > 0 && ps.legendary == leg_found); // higher score
    is_draw = 1
      && (best_is_leg == ps.legendary) // rarity must match
      && diff == 0; // score must match

    if (is_best) {
      r.winner_player = i;
      r.winner_pokemon = pid_store[i];
      best = val;
      g->draw_bitmask = 0; // any previous draw is no more
    } else if (is_draw) {
      // place both pokemons on the draw list
      g->draw_bitmask = 0
        | BIT_SET(g->draw_bitmask, i)
        | BIT_SET(g->draw_bitmask, r.winner_player);
    }
  }

  // Display results
  DPRINTF("max name len is %d\n", max_name_len);
  puts(" - COMPARANDO - ");
  for (int i = 0; i < g->player_cnt; i++) {
    if (!BIT_GET(players_bitmask, i)) continue;

    printf("%s#%d: %s (%s %d)%s\n",
      (i == g->player_active)? "> " : "  ",
      i,
      pokecard_repr_simplestr_salloc_aligned(pid_store[i], max_name_len, 20),
      r.stat_name,
      val_store[i],
      g->draw_bitmask?
        (i & g->draw_bitmask)? " ^" : ""
      : (i == r.winner_player)? " @" : "");

  }
  puts("");
  
  int round_drawn = g->draw_bitmask > 0;
  if (round_drawn) {
    g->draw_winnings = winnings; // no payout! save it for the next round
    g->state = GAME_RUN_DRAW;
  } else {
    g->state = GAME_RUN; // bring it back to normal if the prev
                         // round was a draw
    // process the payout
    player_t *winner = g->players + r.winner_player;
    stack_t old_q = winner->winnings;
    winner->winnings = winnings;

    // Combine winnings
    if (old_q) {
      stack_value_t pid = -1;
      do {
        old_q = stack_pop(old_q, &pid);
        winner->winnings = stack_push(winner->winnings, pid);
      } while (old_q);
      // and there'll be a leftover
    }
  }
  return r;
}

round_result_t game_resolve_draw(game_t *g) {
  // which player should choose?
  int active_bak = g->player_active;
  int effective_active = g->player_active;
  for (int i = 0; i < g->player_cnt; i++) {
    if (BIT_GET(g->draw_bitmask, effective_active)) break;
    effective_active = (effective_active + 1) % g->player_cnt;
  }

  // effective_active now is the correct "next chooser"
  g->player_active = effective_active;
  DPRINTF("effective_active is %d\n", effective_active);
  round_result_t r = game_calc_round(g, g->draw_bitmask & g->playing_bitmask, g->draw_winnings);
  g->draw_winnings = NULL; // since game_calc_round takes ownership of it
                           // (segfault during cleanup otherwise!)
  g->player_active = active_bak;

  return r;
}

game_t game_new(stack_t (*gen_cards_f)(size_t size), player_driver_fptr *player_drivers, int player_cnt, int cards_per_player, long prng_seed) {
  game_t g = {0};
  g.total_cards = player_cnt * cards_per_player;
  g.player_cnt = player_cnt;
  g.playing_bitmask = ~0;
  
  srand(prng_seed);
  printf("seed do prng é %ld\n", prng_seed);
  printf("número de jogadores é %d.\n", g.player_cnt);
  printf("número de cartas em jogo é %d.\n", g.total_cards);
  stack_t pokes = gen_cards_f(g.total_cards);

  for (int i = 0; i < g.player_cnt; i++) {
    g.players[i] = player_alloc(
        &pokes,
        cards_per_player,
        player_drivers[i]);
  }
  return g;
}

void game_next_round(game_t *g) {
  round_result_t r = {0};
  
  if (!g->player_cnt) {
    printf("Jogo sem jogadores!\n");
    g->state = GAME_STOP;
    return;
  }
  if (g->state == GAME_RUN_DRAW) {
    r = game_resolve_draw(g);
  } else {
    r = game_calc_round(g, g->playing_bitmask, NULL); // takes ownership of `winnings`
  }
  
  if (g->state == GAME_CANCEL_ROUND) {
    g->state = GAME_RUN;
    return;
  }
  if (g->state == GAME_RUN_DRAW) {
    printf("\tEmpate entre os jogadores");
    for (int i = 0; i < MAX_PLAYERS; i++) {
      if (BIT_GET(g->draw_bitmask, i)) printf(" #%d", i);
    }
    printf("! Próximo round será entre eles.\n");
  } else {
    printf("\tO vencedor dessa rodada é"
        " o jogador #%d, com o pokemon %s\n",
        r.winner_player,
        pokemon_names[r.winner_pokemon]
      );
    
  }
  
  for (int i = 0; i < g->player_cnt; i++) {
    player_t *p = g->players + i;
    if (!p->hand) {
      if (!player_extrahand(p)) {
        printf("O jogador #%d está sem cartas!\n", i);
        g->playing_bitmask &= ~(1 << i);
      }
    }
  }

  game_check_wincond(g);

  if (g->state == GAME_RUN) {
    // Pass the ball to the next one over
    do {
      g->player_active = (g->player_active + 1) % g->player_cnt;
    } while (!BIT_GET(g->playing_bitmask, g->player_active));
  }
}

void game_free(game_t *g) {
  if (g->draw_winnings) stack_free(g->draw_winnings);

  for (int i = 0; i < g->player_cnt; i++) {
    player_free(g->players + i);
  }
}

