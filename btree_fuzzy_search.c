#include "btree_fuzzy_search.h"
#ifndef DEBUG
#define DEBUG_PRINT 0
#else
#define DEBUG_PRINT 1
#endif
#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#define EXPAND(x) x
#define IIF(cond) CAT(IIF_, cond)
#define IIF_0(t,f) f
#define IIF_1(t,f) t
#define DPRINTF(fmt, ...) IIF(DEBUG_PRINT)(printf(fmt, __VA_ARGS__),)

void
btree_fuzzy_search_inner(btree *bt, size_t bt_depth, const char *buf, ssize_t buf_len, uint64_t hash, queue_t **out) {
  if (!bt) return;
  //if (bt_depth == 0) return r; // dove in too deep (think about the implications)
  
  ssize_t needle = 0;
  uint32_t id = bt->val & 0x3FF;

  // And here's where the facade of modularity breaks for real
  const char *n = pokemon_names[id];
  size_t nlen = pokemon_name_lengths[id];
  
  size_t cmn_len = (nlen < buf_len)? nlen : buf_len;
  size_t score = 0;

  for (needle = 0; needle < cmn_len; needle++) {
    char bufc = tolower(buf[needle]);
    char c = tolower(n[needle]);
    if (c == bufc) { score++; }
    else break;
  }
  
  DPRINTF("%s call: %p (%zu), \"%s\" (%zu), %lu, \"%s\" gets score %hhu\n",
          __func__, bt, bt_depth, buf, buf_len, hash, n, score);

  btree *next = (hash > (bt->val >> 10))? bt->r : bt->l;

  if (score) {
    if (!*out) { *out = queue_alloc((1<<bt_depth)-1); }
    if (bt->l != next) btree_fuzzy_search_inner(bt->l, bt_depth - 1, buf, buf_len, hash, out);
  }
  btree_fuzzy_search_inner(next, bt_depth - 1, buf, buf_len, hash, out);
  if (score && bt->r != next) btree_fuzzy_search_inner(bt->r, bt_depth - 1, buf, buf_len, hash, out);
  if (score == buf_len) { // We are already on the money
    queue_insert(*out, bt->val);
  }
}

void print_hash_tuple(btree *e) {
  uint64_t hash = e->val >> 10;
  uint32_t id = e->val & 0x3FF;

  printf("hash %lu, id %u, name %s", hash, id, pokemon_names[id]);
}

queue_t *
btree_fuzzy_search(btree *bt, size_t bt_depth, const char *buf, ssize_t buf_len, uint64_t hash) {
  queue_t *out = NULL;
  btree_fuzzy_search_inner(
      bt, bt_depth,
      buf, buf_len, hash, &out
  );
  //IIF(DEBUG_PRINT)(btree_print(r.r, print_hash_tuple),);
  return out;
}
