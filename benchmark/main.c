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

void bench_btree() {
  char buf[32] = {0};
  while(fgets(buf, 32, stdin) != NULL && strncmp(buf, "quit", 32)) {
    size_t buflen = strlen(buf);
    
    // remove newline
    if (buf[buflen-1] == '\n') buf[--buflen] = '\0';

    queue_t *result = btree_fuzzy_search(
        pokemon_hashed_names_btree,
        pokemon_hashed_names_btree_depth,
        buf, buflen, pokemon_hash_name(buf)
      );

    queue_free(result);
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

