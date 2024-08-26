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
    if (pokemon_stats[i].legendary) {
      pokes = stack_push(pokes, i);
    }
  }

  // hell yeah
  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = random_take_n(pokes, s);
  return pokes;
}

int player_driver(int pid) {
  printf("Tua vez! teu pokemon é:\n\t%s\n"
      "Qual tua escolha? "
      "(1 - HP; 2 - ATK; 3 - DEF; 4 - SP. ATK; 5 - SP. DEF)\n",
      pokecard_repr_simplestr_salloc(pid));
  int choice = -1;
  char buf[8] = {0};
  while (fgets(buf, 8, stdin) != NULL) {
    choice = atoi(buf);
    if (choice < 1 && choice > 5) {
      printf("Valor inválido, tente novamente!");
    } else { break; }
  }
  return choice;
}

int computer_driver(int pid) {
  int choice = 0;
  pokemon_stats_t ps = pokemon_stats[pid];
  int biggest = 0;
  if (ps.hp > biggest)         { biggest = ps.hp; choice = 1; }
  if (ps.attack > biggest)     { biggest = ps.attack; choice = 2; }
  if (ps.defense > biggest)    { biggest = ps.defense; choice = 3; }
  if (ps.sp_attack > biggest)  { biggest = ps.sp_attack; choice = 4; }
  if (ps.sp_defense > biggest) { biggest = ps.sp_defense; choice = 5; }
  return choice;
}

void pokedex() {
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
}

int main(int argc, char **argv) {
  // player count, and cards per player
  int pc = 4, cpp = 8;
  long seed = time(NULL);
  int menu_stage = 0;
  if (argc >= 2) {
    if (argv[1][0] == 'p' || argv[1][0] == 'P') {
      menu_stage = -1;
    } else {
      pc = atoi(argv[1]);
      menu_stage = 2;
    }
  }
  if (argc >= 3) {
    cpp = atoi(argv[2]);
    menu_stage = 3;
  }
  if (argc >= 4) {
    seed = atoi(argv[3]);
    menu_stage = 4;
  }

  player_driver_fptr drivers[MAX_PLAYERS] = {0};
  char buf[32] = {0};
  while(menu_stage < 5 && menu_stage >= 0) {
    const char *questions[] = {
      "Jogo ou pokedex? ([J]ogo | [p]okedex) ",
      "Quantos jogadores? [0.." M2STR(MAX_PLAYERS) "] (4) ",
      "Quantas cartas por pessoa? (8) ",
      "Seed específica? (derivada do [T]empo | <valor>) ",
      "Configuração de jogadores:\n"
    };
    printf("%s", questions[menu_stage]);
    if (menu_stage != 4 && fgets(buf, 32, stdin) == NULL) break;
    size_t buflen = strlen(buf);
    if (buflen && buf[buflen-1] == '\n') buf[--buflen] = '\0';
    int v = atoi(buf);
    switch (menu_stage) {
      case 0:
        if (buflen == 0) menu_stage = 1;
        switch(buf[0]) {
          case 'J':
          case 'j':
            menu_stage = 1;
            break;
          case 'P':
          case 'p':
            menu_stage = -1;
            break;
        }
        break;
      case 1: {
        if (buflen != 0) {
          pc = v;
        }
        menu_stage = 2;
        break;
      case 2: if (buflen != 0) cpp = v; menu_stage = 3; break;
      case 3: if (buflen != 0) seed = v; menu_stage = 4; break;
      case 4:
        for (int i = 0; i < pc; i++) {
          driver_choice: printf("Jogador #%d real ou computador? (r/C) ", i);
          if (fgets(buf, 32, stdin) == NULL) goto loop_break;
          switch (buf[0]) {
            case 'r':
            case 'R':
              drivers[i] = player_driver;
              break;
            case '\n':
            case 'c':
            case 'C':
              drivers[i] = computer_driver;
              break;
          }
        }
        menu_stage = 5;
      } break;
    }
    continue;
loop_break: break;
  }

  if (menu_stage == -1) {
    pokedex();
  } else {
    game_t g = game_new(random_pile, drivers, pc, cpp, seed);

    while (g.state != GAME_STOP) {
      DPRINTF("%s\n", game_repr_sall(&g));
      game_next_round(&g);
    }
    
    puts(game_repr_sall(&g));
    game_free(&g);
  }

  return 0;
}

