#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#include "pokemon_tables.h"
#include "pokemon_dyntables.h"
#include "pokecards.h"
#include "pokemon_ascii.h"
#include "queue.h"
#include "btree.h"
#include "btree_fuzzy_search.h"
#include "utils.h"
#include "game.h"

// likes to leave a small unsorted section in the top, call it multiple times to "fix" it
stack_t very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(stack_t a, size_t sizehint) {
  size_t depth = 0;
  stack_t b = NULL;
  for (; a && depth < sizehint/2; depth++) {
    int val;
    a = stack_pop(a, &val);
    b = stack_push(b, val);
  }

  uint32_t choice;
  size_t needle = 0;
  stack_t result = NULL;
  while (a && b) {
    if (needle % 32 == 0) {
      choice = random();
    }
    if (0) printf("needle %d: %s%s\n" "%s\n" "%s\n" "%s\n",
        needle,
        (needle % 32 == 0)? "random call! ":"",
        (choice & 0b1)? "right" : "left",
        stack_debug_str_sall4(a),
        stack_debug_str_sall4(b),
        stack_debug_str_sall4(result)
      );
    int selv;
    if (choice & 0b1) {
      b = stack_pop(b, &selv);
    } else {
      a = stack_pop(a, &selv);
    }
    choice >>= 1;
    result = stack_push(result, selv);
    needle++;
  }
  // get any leftovers
  while (a) {
    int val;
    a = stack_pop(a, &val);
    result = stack_push(result, val);
  }
  while (b) {
    int val;
    b = stack_pop(b, &val);
    result = stack_push(result, val);
  }
  return result;
}

stack_t random_take_n(stack_t s, size_t num) {
  stack_t acc = NULL;
  stack_t discard = NULL;

  uint32_t choice;
  size_t needle = 0;
  while (num) {
    if (!s) {
      if (!discard) return acc; // num was more than the input stack length
      s = discard;
      discard = NULL;
    }
    if (needle % 32 == 0) {
      choice = random();
    }
    int selv;
    s = stack_pop(s, &selv);
    if (0) printf("needle %d: selv %d choice %d\n", needle, selv, choice & 0b1);
    if (choice & 0b1) {
      acc = stack_push(acc, selv);
      num--;
    } else {
      discard = stack_push(discard, selv);
    }
    choice >>= 1;
    needle++;
  }
  int _;
  while (s) s = stack_pop(s, &_);
  while (discard) discard = stack_pop(discard, &_);
  return acc;
}

void print_bt_pokemon(btree *e) {
  uint64_t id = e->val & 0x7FF;
  printf("%s\n", pokecard_repr_simplestr_salloc(id));
}

stack_t random_pile(size_t s) {
  stack_t pokes = NULL;
  
  for (int i = 0; i < pokemon_count; i++) {
    pokes = stack_push(pokes, i);
  }

  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = random_take_n(pokes, s);
  return pokes;
}

int player_driver(int pid) {
  printf("Tua vez! teu pokemon é:\n\t%s\n"
      "Qual tua escolha? "
      "(1 - TOTAL; 2 - HP; 3 - ATK; 4 - DEF)\n",
      pokecard_repr_simplestr_salloc(pid));
  int choice = -1;
  char buf[8] = {0};
  while (fgets(buf, 8, stdin) != NULL) {
    choice = atoi(buf);
    if (choice < 1 && choice > 4) {
      printf("Valor inválido, tente novamente!");
    } else { break; }
  }
  return choice;
}

int computer_driver(int pid) {
  int choice = 0;
  pokemon_stats_t ps = pokemon_stats[pid];
  int biggest = 0;
  if (ps.total > biggest) { biggest = ps.total; choice = 1; }
  if (ps.hp > biggest) { biggest = ps.hp; choice = 2; }
  if (ps.attack > biggest) { biggest = ps.attack; choice = 3; }
  if (ps.defense > biggest) { biggest = ps.defense; choice = 4; }
  return choice;
}

int main(int argc, char **argv) {
  time_t t = time(NULL);

  game_t g = {0};
  g.total_cards = 32;
  g.player_cnt = 2;
  g.playing_bitmask = ~0;
  if (argc >= 2) {
    g.player_cnt = atoi(argv[1]);
  }
  if (argc >= 3) {
    g.total_cards = atoi(argv[2]);
  }
  if (argc >= 4) {
    t = atoi(argv[3]);
  }
  srand(t);
  printf("seed do prng é %ld\n", t);
  printf("número de jogadores é %d.\n", g.player_cnt);
  printf("número de cartas em jogo é %d.\n", g.total_cards);
  stack_t pokes = random_pile(g.total_cards);

  for (int i = 0; i < g.player_cnt; i++) {
    g.players[i] = player_alloc(&pokes, g.total_cards/g.player_cnt,
        (i > 0)? computer_driver : player_driver);
  }

  while (g.state != GAME_STOP) {
    DPRINTF("%s\n", game_repr_sall(&g));
    game_next_round(&g);
  }
  
  puts(game_repr_sall(&g));

  char buf[32] = {0};
  while(fgets(buf, 32, stdin) != NULL
     && strncmp(buf, "quit\n", 32) != 0)
  {
    size_t buflen = strlen(buf);
    
    // remove newline
    if (buf[buflen-1] == '\n') buf[--buflen] = '\0';

    queue_t *result = btree_fuzzy_search(
        pokemon_hashed_names_btree,
        pokemon_hashed_names_btree_depth,
        buf, buflen, pokemon_hash_name(buf)
      );

    uint64_t hashmix;
    while (queue_remove(result, &hashmix)) {
      uint16_t id = hashmix & 0x7FF;
      printf("%s\n", pokecard_repr_simplestr_salloc(id));
    }

    queue_free(result);
  }

  return 0;
}

