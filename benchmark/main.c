#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "pokemon_tables.h"
#include "pokemon_dyntables.h"
#include "queue.h"
#include "utils.h"

typedef struct {
  btree *r;
  size_t depth;
  size_t match_score;
} btree_partial_search_result;

btree_partial_search_result
btree_partial_search_inner(btree *bt, size_t bt_depth, const char *buf, ssize_t buflen, size_t depth, uint64_t hash) {
  btree_partial_search_result r = {0};

  if (!bt) return r;
  if (bt_depth == 0) return r; // dove in too deep (think about the implications)
  
  // On the deepest call frame, we have a leaf.
  // The path leading to this leaf can be unwound, looking
  // for the longest match to our query. It'll be propagated
  // through the return values.

  ssize_t needle = 0;
  volatile int32_t next_score = 0;
  uint32_t id = bt->val & 0x3FF;

  const char *n = pokemon_names[id];
  size_t nlen = strlen(n);
  
  if (nlen < buflen) { return r; }

  for (needle = 0; needle < buflen; needle++) {
    char bufc = tolower(buf[needle]);
    char c = tolower(n[needle]);
    if (c == bufc) { r.match_score++; }
  }

  btree *next = (hash > (bt->val >> 10))? bt->r : bt->l;
  btree_partial_search_result nres = btree_partial_search_inner(next, bt_depth - 1, buf, buflen, depth + 1, hash);
  
  r.r = bt;
  r.depth = bt_depth;
  if (nres.r) {
    if (r.match_score >= nres.match_score) {
    } else {
      r = nres;
    }
  }
  return r;
}

btree_partial_search_result
btree_partial_search(btree *bt, size_t bt_depth, const char *buf, ssize_t buflen) {
  btree_partial_search_result r = btree_partial_search_inner(
      bt, bt_depth,
      buf, buflen, 0, pokemon_hash_name(buf)
  );

  return r;
}

typedef struct { int take; uint64_t val; } visitor_result_t;
void queue_from_btree_inner(btree *bt, visitor_result_t (*visitor)(uint64_t, void *), void *visitor_args, queue_t **out, size_t depth) {
  if (!bt) return;
  
  queue_from_btree_inner(bt->l, visitor, visitor_args, out, depth + 1);

  visitor_result_t this_visit = visitor(bt->val, visitor_args);
  if (this_visit.take) {
    *out = queue_insert(*out, this_visit.val);
    if (0) printf("inserted %lu on queue\n", this_visit.val);
  }

  queue_from_btree_inner(bt->r, visitor, visitor_args, out, depth + 1);
}

queue_t *queue_from_btree(btree *bt, size_t bt_depth, visitor_result_t (*visitor)(uint64_t, void *), void *visitor_args) {
  queue_t *q = queue_alloc(powil(2, bt_depth) - 1);
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

void bench_btree() {
  char buf[32] = {0};
  while(fgets(buf, 32, stdin) != NULL && strncmp(buf, "quit", 32)) {
    size_t buflen = strlen(buf);
    
    // remove newline
    if (buf[buflen-1] == '\n') buf[--buflen] = '\0';

    btree_partial_search_result result = btree_partial_search(
        pokemon_hashed_names_btree,
        pokemon_hashed_names_btree_depth,
        buf, buflen
      );

    visitor_poke_starts_with_args_t va = {buf, buflen};
    queue_t *res_q = queue_from_btree(result.r, result.depth, visitor_poke_starts_with, &va);

    queue_free(res_q);
  }
}

void bench_linear() {
  char buf[32] = {0};
  while(fgets(buf, 32, stdin) != NULL && strncmp(buf, "quit", 32)) {
    size_t buflen = strlen(buf);
    
    // remove newline
    if (buf[buflen-1] == '\n') buf[--buflen] = '\0';

    queue_t *res_q = queue_alloc(pokemon_count);

    for (size_t i = 0; i < pokemon_count; i++) {
      const char *pn = pokemon_names[i];
      if (strncmp(buf, pn, buflen) == 0) {
        queue_insert(res_q, i);
      }
    }

    queue_free(res_q);
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "provide an algorithm\n");
    return 1;
  }

  switch(argv[1][0]) {
    case 'l':
    case 'L':
      bench_linear();
      break;
    case 'b':
    case 'B':
      bench_btree();
      break;
    default:
      fprintf(stderr, "unknown algorithm\n");
      return 1;
      break;
  }

  return 0;
}

