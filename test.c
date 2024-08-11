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
#include "btree_fuzzy_search.h"
#include "utils.h"

void
queue_compile_res_inner(btree *bt, const char *buf, size_t buf_len, queue_t **out, size_t depth) {
  if (!bt) return;
  
  queue_compile_res_inner(bt->l, buf, buf_len, out, depth + 1);

  int16_t id = bt->val & 0x3FF;
  if (pokemon_name_lengths[id] >= buf_len) { 
    const char *pokename = pokemon_names[id];
  
    int take = 1;
    for (uint8_t needle = 0; needle < buf_len; needle++) {
      if (pokename[needle] != buf[needle]) {
        take = 0;
        break;
      }
    }
    if (take) {
      *out = queue_insert(*out, bt->val);
    }
  }

  queue_compile_res_inner(bt->r, buf, buf_len, out, depth + 1);
}

queue_t *
queue_compile_res(btree *bt, size_t bt_depth, const char *buf, size_t buf_len) {
  queue_t *q = queue_alloc((1 << bt_depth) - 1);
  queue_compile_res_inner(bt, buf, buf_len, &q, 0);
  return q;
}

int main(int argc, char **argv) {
  char buf[32] = {0};


  while(fgets(buf, 32, stdin) != NULL && strncmp(buf, "quit", 32)) {
    int8_t hits[1024] = {0};
    size_t buflen = strlen(buf);
    
    // remove newline
    if (buf[buflen-1] == '\n') buf[--buflen] = '\0';

    queue_t *result = btree_fuzzy_search(
        pokemon_hashed_names_btree,
        pokemon_hashed_names_btree_depth,
        buf, buflen, pokemon_hash_name(buf)
      );

    for (size_t i = 0; i < pokemon_count; i++) {
      const char *pn = pokemon_names[i];
      if (strncmp(buf, pn, buflen) == 0) {
        hits[i]--;
      }
    }

    uint64_t hashmix_bt;
    while (queue_remove(result, &hashmix_bt)) {
      uint16_t bt_id = hashmix_bt & 0x3FF;
      hits[bt_id]++;
    }
    for (size_t i = 0; i < pokemon_count; i++) {
      if (hits[i] != 0) {
        fprintf(stderr, "searching for %s: btree %s %s!\n", buf, (hits[i] > 0)? "caught" : "missed", pokemon_names[i]);
      }
    }

    queue_free(result);
  }

  return 0;
}

