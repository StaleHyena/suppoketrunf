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
#include "pokecards.h"
#include "utils.h"

void print_bt_pokemon(btree *e) {
  uint64_t id = e->val & 0x7FF;
  printf("%s", pokecard_repr_simplestr_salloc(id));
}

int main(int argc, char **argv) {
  char buf[32] = {0};

  btree_print(pokemon_hashed_names_btree, print_bt_pokemon);

  while(fgets(buf, 32, stdin) != NULL && strncmp(buf, "quit", 32)) {
    int8_t hits[4096] = {0};
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
      uint16_t bt_id = hashmix_bt & 0x7FF;
      hits[bt_id] += 2;
    }
    for (size_t i = 0; i < pokemon_count; i++) {
      if (hits[i] != 0) {
        fprintf(stderr, "searching for %s: btree %s %s!\n", buf,
            (hits[i] > 0)?
              ((hits[i] > 1)? "caught (erroneously)" : "caught")
            : "missed",
            pokemon_names[i]
          );
      }
    }

    queue_free(result);
  }

  return 0;
}

