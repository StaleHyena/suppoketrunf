#include "game.h"

player_t
player_alloc(stack_t *take_pile, size_t card_cnt, player_driver_fptr driver) {
  player_t r = {0};
  for (r.card_cnt = 0; r.card_cnt < card_cnt; r.card_cnt++) {
    int pid;
    *take_pile = stack_pop(*take_pile, &pid);
    r.hand = stack_push(r.hand, pid);
  }
  // gigantic queue since they don't resize yet, FIXME
  r.winnings = queue_alloc(MAX_PLAYERS * card_cnt);
  r.driver = driver;
  return r;
}


char *player_repr_sall(player_t* p) {
#define PRMAX 128
  static char buf[PRMAX] = {0};
  int tcpid;
  int has_cards = stack_peek(p->hand, &tcpid);
  size_t off = snprintf(buf+off, PRMAX-off,
      "carta topo é %s, com %zu cartas na mão.",
      pokecard_repr_simplestr_salloc(tcpid), p->card_cnt
    );
  return buf;
#undef PRMAX
}

char *
game_repr_sall(game_t* g) {
#define GRMAX 512
  static char buf[GRMAX] = {0};
  size_t off = 0;
  off += snprintf(buf+off, GRMAX-off, "jogo com %d jogadores (%s):\n",
      g->player_cnt, 
      g->state == GAME_RUN? "rodando"
      : (g->state == GAME_STOP? "parado"
        : "estado desconhecido"
      ));
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

void
game_next_round(game_t *g) {
  player_t *p2play = g->players + g->player_active;

  // The player takes his pick of stat
  int cpid = 0;
  // What if no hand? FIXME
  stack_peek(p2play->hand, &cpid);
  int choice = p2play->driver(cpid);
  const char *stat_name =
      choice == 1? "TOTAL"
    : choice == 2? "HP"
    : choice == 3? "ATK"
    : choice == 4? "DEF" : "UNK STAT";

  printf("O jogador %d selecionou a estatística %s!\n", g->player_active, stat_name);

  puts(" -@- ");
  // And the round winner is decided
  int winner = 0;
  int winner_val = 0;
  int winner_pid = -1;
  for (int i = 0; i < g->player_cnt; i++) {
    int pid = 0;
    player_t *p = g->players + i;
    p->hand = stack_pop(p->hand, &pid);
    pokemon_stats_t ps = pokemon_stats[pid];
    
    int val =
        choice == 1? ps.total
      : choice == 2? ps.hp
      : choice == 3? ps.attack
      : choice == 4? ps.defense : -1;

    printf("Carta do %d%s: %s (%s = %d)\n",
      i,
      (i == g->player_active)? " (jogando)" : "",
      pokecard_repr_simplestr_salloc(pid),
      stat_name,
      val);
    
    if (val > winner_val) {
      winner = i;
      winner_val = val;
      winner_pid = pid;
    }
  }
  puts(" -X- ");
  printf("O vencedor dessa rodada é o jogador %d, "
      "com o pokemon %s\n", winner, pokecard_repr_simplestr_salloc(winner_pid));
  
  int handless = -1;
  for (int i = 0; i < g->player_cnt; i++) {
    player_t *p = g->players + i;
    if (!p->hand) {
      handless = i;
      break;
    }
  }

  if (handless != -1) {
    printf("O jogador %d perdeu todas as cartas, sinal que alguém ganhou. Procurando vencedor...\n", handless);

    for (int i = 0; i < g->player_cnt; i++) {
      player_t *p = g->players + i;
      if (p->hand) {
        printf("O jogador %d ganhou esse jogo! Parabéns.\n", i);
        g->state = GAME_STOP;
        break;
      }
    }
  }
}


