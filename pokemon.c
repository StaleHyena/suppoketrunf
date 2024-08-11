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

void print_hash_tuple(btree *e) {
  uint64_t hash = e->val >> 10;
  uint32_t id = e->val & 0x3FF;

  printf("hash %lu, id %u, name %s", hash, id, pokemon_names[id]);
}

void print_bt_pokemon(btree *e) {
  uint64_t id = e->val & 0x3FF;
  printf("%s\n", pokecard_repr_simplestr_salloc(id));
}

int main(void) {
  srand(time(NULL));
  stack_t pokes = NULL;
  
  for (int i = 0; i < pokemon_count; i++) {
    pokes = stack_push(pokes, i);
  }

  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(pokes, pokemon_count);
  pokes = random_take_n(pokes, 4);

  int c;
  assert(stack_peek(pokes, &c)); // make sure there's at least one
  do {
    pokes = stack_pop(pokes, &c);
    print_pokemon(pokemon_ids[c]);
    printf("%s\n", pokecard_repr_simplestr_salloc(c));
  } while (pokes);

  //btree_print(pokemon_hashed_names_btree, print_hash_tuple);

  char buf[32] = {0};
  do {
    if(fgets(buf, 32, stdin) == NULL) break;
    size_t buflen = strlen(buf);
    
    // remove newline
    if (buf[buflen-1] == '\n') buf[--buflen] = '\0';

    btree_fuzzy_ret result = btree_fuzzy_search(
        pokemon_hashed_names_btree,
        pokemon_hashed_names_btree_depth,
        buf, buflen, pokemon_hash_name(buf)
      );

    visitor_poke_starts_with_args_t va = {buf, buflen};
    queue_t *res_q = queue_from_btree(result.r, result.depth, visitor_poke_starts_with, &va);

    uint64_t hashmix;
    while (queue_remove(res_q, &hashmix)) {
      uint16_t id = hashmix & 0x3FF;
      printf("%s\n", pokecard_repr_simplestr_salloc(id));
    }

    queue_free(res_q);
  } while(strncmp(buf, "quit", 32) != 0);

  return 0;
}

