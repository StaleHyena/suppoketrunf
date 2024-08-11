#include "btree_fuzzy_search.h"

btree_fuzzy_ret
btree_fuzzy_search_inner(btree *bt, size_t bt_depth, const char *buf, ssize_t buf_len, uint64_t hash, uint8_t prev_score) {
  btree_fuzzy_ret r = {0};

  if (!bt) return r;
  if (bt_depth == 0) return r; // dove in too deep (think about the implications)
  
  ssize_t needle = 0;
  uint32_t id = bt->val & 0x3FF;

  // And here's where the facade of modularity breaks for real
  const char *n = pokemon_names[id];
  size_t nlen = strlen(n);
  
  if (nlen < buf_len) { return r; }

  for (needle = 0; needle < buf_len; needle++) {
    char bufc = tolower(buf[needle]);
    char c = tolower(n[needle]);
    if (c == bufc) { r.match_score++; }
  }
  
  //printf("%s call: %p (%zu), \"%s\" (%zu), %lu, %hhu, \"%s\" gets score %hhu\n",
  //       __func__, bt, bt_depth, buf, buf_len, hash, prev_score, n, r.match_score);
  if (prev_score && r.match_score <= prev_score) {
    //printf("%s scored lower than or equal to the previous match! (%d <= %d)\n", n, r.match_score, prev_score);
    return r;
  }

  btree *next = (hash > (bt->val >> 10))? bt->r : bt->l;
  btree_fuzzy_ret nres = btree_fuzzy_search_inner(next, bt_depth - 1, buf, buf_len, hash, r.match_score);
  
  r.r = bt;
  r.depth = bt_depth;
  if (nres.r) {
    assert(nres.match_score >= r.match_score);
    return nres;
  }
  return r;
}

btree_fuzzy_ret
btree_fuzzy_search(btree *bt, size_t bt_depth, const char *buf, ssize_t buf_len, uint64_t hash) {
  btree_fuzzy_ret r = btree_fuzzy_search_inner(
      bt, bt_depth,
      buf, buf_len, hash, 0
  );

  return r;
}
