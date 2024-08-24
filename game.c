#include "game.h"

player_t
player_alloc(stack_t *take_pile, size_t card_cnt, player_driver_fptr driver) {
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

// Returns how big the new hand is
int player_extrahand(player_t* p) {
  if (!p->winnings) return 0;
  int total = 0;
  for (queue_value_t pid = -1; queue_remove(p->winnings, &pid); total++) {
    p->hand = stack_push(p->hand, pid);
  }
  p->card_cnt = total;
  queue_free(p->winnings);
  p->winnings = NULL;
  return total;
}

char *player_repr_sall(player_t* p) {
#define PRMAX 128
  static char buf[PRMAX] = {0};
  int tcpid = 0;
  int has_cards = stack_peek(p->hand, &tcpid);
  size_t off = 0;
  off += snprintf(buf+off, PRMAX-off,
      "carta topo %s%s, com %zu+%zu cartas na mão.",
      has_cards? "é " : "não existe",
      has_cards? pokecard_repr_simplestr_salloc(tcpid) : "",
      p->card_cnt, p->winnings? queue_size(p->winnings) : 0
    );
  return buf;
#undef PRMAX
}

char *
game_repr_sall(game_t* g) {
#define GRMAX 4096
  static char buf[GRMAX] = {0};
  size_t off = 0;
  off += snprintf(buf+off, GRMAX-off, "jogo com %d jogadores (%s):\n",
      g->player_cnt, 
      g->state == GAME_RUN? "rodando"
      : g->state == GAME_RUN_DRAW? "rodando (desempate)"
      : g->state == GAME_STOP? "parado"
      : "estado desconhecido");
  for (int i = 0; i < g->player_cnt; i++) {
    assert(off < GRMAX);
    off += snprintf(buf+off, GRMAX-off,
        "  jogador %d: %s\n",
        i, player_repr_sall(g->players + i)
      );
  }
  assert(off < GRMAX);
  snprintf(buf+off, GRMAX-off, "próximo a jogar é o jogador %d.\n", g->player_active);

  return buf;
#undef GRMAX
}

// Side effect: pushes winnings to hand if needed
void game_check_wincond(game_t *g) {
  int handless = -1;
  for (int i = 0; i < g->player_cnt; i++) {
    player_t *p = g->players + i;
    if (!p->hand) {
      if (player_extrahand(p) == 0) {
        handless = i;
      }
      break;
    }
  }

  if (handless != -1) {
    printf("O jogador %d perdeu todas as cartas, sinal que alguém ganhou. Procurando vencedor...\n", handless);

    for (int i = 0; i < g->player_cnt; i++) {
      player_t *p = g->players + i;
      if (p->hand) {
        // make sure no cards were lost
        assert(p->card_cnt + (p->winnings? queue_size(p->winnings) : 0) == g->total_cards);
        printf("O jogador %d ganhou esse jogo! Parabéns.\n", i);
        g->state = GAME_STOP;
        return;
      }
    }
    printf("Ninguém ganhou! (??)\n");
    g->state = GAME_STOP;
  }
}

typedef struct {
  int winner_player;
  int winner_value;
  int winner_pokemon;
  int choice;
  const char *stat_name;
  queue_t *winnings;
} round_result_t;

round_result_t
game_calc_round(game_t *g, int players_bitmask, queue_t *winnings) {
  // Make sure the active player is part of the round
  assert((players_bitmask >> g->player_active) & 0b1);

  round_result_t r = {0};

  player_t *p2play = g->players + g->player_active;
  // The player takes his pick of stat
  int cpid = 0;
  // What if no hand? FIXME
  stack_peek(p2play->hand, &cpid);
  r.choice = p2play->driver(cpid);
  if (!r.choice) {
    fprintf(stderr,
        "Erro ao interpretar escolha do jogador #%d, cancelando round.\n",
        g->player_active);
    g->state = GAME_CANCEL_ROUND;
    return r;
  } else if (r.choice < 0) {
    fprintf(stderr,
        "Jogador #%d saiu, encerrando jogo.\n",
        g->player_active);
    g->state = GAME_STOP;
    return r;
  }
  r.stat_name =
      r.choice == 1? "TOTAL"
    : r.choice == 2? "HP"
    : r.choice == 3? "ATK"
    : r.choice == 4? "DEF" : "UNK STAT";

  printf("Jogador #%d selecionou a estatística %s!\n", g->player_active, r.stat_name);

  puts(" -INICIO- ");
  // And the round winner is decided
  // checking for possible draws
  r.winner_player = -1;
  r.winner_value = -1;
  r.winner_pokemon = -1;
  g->draw_bitmask = 0;
  
  for (int i = 0; i < g->player_cnt; i++) {
    if (!((players_bitmask >> i) & 0b1)) continue;
    int pid = 0;
    player_t *p = g->players + i;
    p->hand = stack_pop(p->hand, &pid);
    p->card_cnt--;
    winnings = queue_insert(winnings, pid);
    pokemon_stats_t ps = pokemon_stats[pid];
    
    int val =
        r.choice == 1? ps.total
      : r.choice == 2? ps.hp
      : r.choice == 3? ps.attack
      : r.choice == 4? ps.defense : -1;

    printf("Carta do jogador #%d%s: %s (%s %d)\n",
      i,
      (i == g->player_active)? " (jogando)" : "",
      pokecard_repr_simplestr_salloc(pid),
      r.stat_name,
      val);
    
    if (val > r.winner_value) {
      r.winner_player = i;
      r.winner_value = val;
      r.winner_pokemon = pid;
    } else if (val == r.winner_value) {
      g->draw_bitmask |= (1 << i) | (1 << r.winner_player);
    }
  }
  puts(" -FIM- ");
  
  if (g->draw_bitmask) {
    g->draw_winnings = winnings;
    g->state = GAME_RUN_DRAW;
  } else {
    g->state = GAME_RUN; // bring it back to normal if the prev
                         // round was a draw
    player_t *winner = g->players + r.winner_player;
    queue_t *old_q = winner->winnings;
    winner->winnings = winnings;

    // Combine winnings queues
    if (old_q) {
      queue_value_t pid = -1;
      while (queue_remove(old_q, &pid)) {
        queue_insert(winner->winnings, pid);
      }
      queue_free(old_q);
    }
  }
  return r;
}

round_result_t
game_resolve_draw(game_t *g) {
  pokemon_stats_t pstats[MAX_PLAYERS] = {0};
  
  // which player should choose?
  int active_bak = g->player_active;
  int effective_active = g->player_active;
  for (int i = 0; i < g->player_cnt; i++) {
    if ((g->draw_bitmask >> i) & 0b1) break;
    effective_active = (effective_active + 1) % g->player_cnt;
  }

  // effective_active now is the correct "next chooser"
  g->player_active = effective_active;
  round_result_t r = game_calc_round(g, g->draw_bitmask, g->draw_winnings);
  g->player_active = active_bak;

  return r;
}

void
game_next_round(game_t *g) {
  round_result_t r = {0};


  if (g->state == GAME_RUN_DRAW) {
    r = game_resolve_draw(g);
  } else {
    // magic size queue since they don't resize yet, FIXME
    queue_t *winnings = queue_alloc(g->player_cnt * g->total_cards);
    r = game_calc_round(g, ~0, winnings); // takes ownership of `winnings`
  }
  
  if (g->state == GAME_CANCEL_ROUND) {
    g->state = GAME_RUN;
    return;
  }
  if (g->state == GAME_RUN_DRAW) {
    printf("\tEmpate entre os jogadores");
    for (int i = 0; i < MAX_PLAYERS; i++) {
      if ((g->draw_bitmask >> i) & 0b1) printf(" #%d", i);
    }
    printf("! Próximo round será entre eles.\n");
  } else {
    printf("\tO vencedor dessa rodada é o jogador #%d,\n"
        "com o pokemon %s\n",
        r.winner_player,
        pokecard_repr_simplestr_salloc(r.winner_pokemon)
      );
    g->player_active = (g->player_active + 1) % g->player_cnt;
  }

  for (int i = 0; i < g->player_cnt; i++) {
    player_t *p = g->players + i;
    if (!p->hand) {
      if (!player_extrahand(p)) {
        printf("O jogador #%d está sem cartas!\n", i);
      }
    }
  }
  game_check_wincond(g);
}


