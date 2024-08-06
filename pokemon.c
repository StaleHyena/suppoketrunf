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

#define HITLINEQ printf("hit line %d!\n", __LINE__)

btree *btree_partial_search_inner(btree *bt, size_t btdepth, const char *buf, ssize_t buflen, size_t depth, uint64_t hash, size_t *cut_depth_out) {
  if (!bt) return NULL;
  if (depth >= btdepth) return NULL; // dove in too deep (think about the implications)

  btree *next = (hash > (bt->val >> 10))? bt->r : bt->l;
  btree *result = btree_partial_search_inner(next, btdepth, buf, buflen, depth + 1, hash, cut_depth_out);
  if (!result) return bt;

  // Now, on the deepest call frame, we have a leaf.
  // The path leading to this leaf can be unwound, looking
  // for the longest match to our query. It'll be propagated
  // through the return values.

  const char *resname = pokemon_names[result->val & 0x3FF];
  size_t resnamelen = strlen(resname);
  const char *ourname = pokemon_names[bt->val & 0x3FF];
  size_t ournamelen = strlen(ourname);
  
  if (resnamelen < buflen) { HITLINEQ; *cut_depth_out = depth; return bt; }
  if (ournamelen < buflen) { HITLINEQ; return result; }

  ssize_t needle = 0;
  for (needle = 0; needle < buflen; needle++) {
    char bufc = tolower(buf[needle]);
    char res_matches = tolower(resname[needle]) == bufc;
    char our_matches = tolower(ourname[needle]) == bufc;
    if (!our_matches) return result;
    else if (our_matches && !res_matches) {
      *cut_depth_out = depth;
      return bt; // ours is the bigger match
    }
  }
  return result;
}

btree *btree_partial_search(btree *bt, const char *buf, ssize_t buflen, size_t *depth_out) {
  size_t pokemon_count_log2 = 0;
  size_t acc = pokemon_count;
  do {
    acc /= 2;
    pokemon_count_log2++;
  } while(acc > 1);
  size_t cut_depth = 0;
  btree *r = btree_partial_search_inner(bt, pokemon_count_log2, buf, buflen, 0, pokemon_hash_name(buf), &cut_depth);
  *depth_out = pokemon_count_log2 - cut_depth + 1;
  return r;
}

typedef struct { int take; uint64_t val; } visitor_result_t;
void queue_from_btree_inner(btree *bt, visitor_result_t (*visitor)(uint64_t, void *), void *visitor_args, queue_t *out, size_t depth) {
  printf("%s call: %p , depth %zu\n", __func__, bt, depth);
  if (!bt) return;
  
  queue_from_btree_inner(bt->l, visitor, visitor_args, out, depth + 1);

  visitor_result_t this_visit = visitor(bt->val, visitor_args);
  if (this_visit.take) {
    *out = queue_insert(*out, this_visit.val);
    printf("inserted %lu on queue\n", this_visit.val);
  }

  queue_from_btree_inner(bt->r, visitor, visitor_args, out, depth + 1);
}

queue_t queue_from_btree(btree *bt, size_t bt_depth, visitor_result_t (*visitor)(uint64_t, void *), void *visitor_args) {
  queue_t q = queue_alloc(powil(2, bt_depth) - 1);
  printf("allocated queue of size %zu\n", (size_t)powil(2, bt_depth) - 1);
  queue_from_btree_inner(bt, visitor, visitor_args, &q, 0);
  return q;
}

typedef struct { const char *buf; size_t buflen; } visitor_poke_starts_with_args_t;
visitor_result_t visitor_poke_starts_with(uint64_t val, void *arg) {
  visitor_poke_starts_with_args_t *s = (visitor_poke_starts_with_args_t*)arg;
  visitor_result_t r = {.take = 0, .val = val};
  uint16_t id = val & 0x3FF;
  const char *pokename = pokemon_names[id];
  size_t pokenamelen = strlen(pokename);
  if (pokenamelen < s->buflen) return r;
  r.take = strncasecmp(s->buf, pokename, s->buflen) == 0;
  return r;
}

int main(void) {
  dyn_tables_init();
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

  btree_print(pokemon_hashed_names_btree, print_hash_tuple);

  char buf[32] = {0};
  do {
    if(fgets(buf, 32, stdin) == NULL) break;
    size_t buflen = strlen(buf);
    
    // remove newline
    if (buf[buflen-1] == '\n') buf[--buflen] = '\0';

    size_t result_depth = 0;
    btree *result = btree_partial_search(pokemon_hashed_names_btree, buf, buflen, &result_depth);
    visitor_poke_starts_with_args_t va = {buf, 1};
    queue_t res_q = queue_from_btree(result, result_depth, visitor_poke_starts_with, &va);

    uint64_t hashmix;
    while (queue_remove(res_q, &hashmix)) {
      uint16_t id = hashmix & 0x3FF;
      printf("%s\n", pokecard_repr_simplestr_salloc(id));
    }

    queue_free(res_q);
  } while(strncmp(buf, "quit", 32) != 0);

  dyn_tables_fini();

  return 0;
}

