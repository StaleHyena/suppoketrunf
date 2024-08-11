#ifndef BTREE_FUZZY_SEARCH_H__
#define BTREE_FUZZY_SEARCH_H__

#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "btree.h"
#include "pokemon_tables.h"
#include "pokemon_dyntables.h"

typedef struct {
  btree *r;
  size_t depth;
  uint8_t match_score;
} btree_fuzzy_ret;

btree_fuzzy_ret
btree_fuzzy_search(btree *bt, size_t bt_depth, const char *buf, ssize_t buf_len, uint64_t hash);

#endif // BTREE_FUZZY_SEARCH_H__
