#include "pokemon_dyntables.h"
#include <string.h>
#include <assert.h>
#include <ctype.h>

btree *pokemon_hashed_names_btree;

//uint32_t pokemon_hash_name(int uid) {
//  const uint32_t hashlut[8] = {17,  13, 373, 197, 421, 179, 947, 509}; 
//  const char *name = pokemon_names[uid];
//
//  uint32_t acc = 0;
//  for (size_t i = 0; i < strlen(name); i++) {
//    acc += name[i] * hashlut[name[i] & 7];
//  }
//  return acc;
//}

uint64_t powil(uint8_t base, uint8_t exp) {
  uint64_t acc = 1;
  while(exp) {
    acc *= base;
    exp--;
  }
  return acc;
}

uint32_t pokemon_hash_name(int uid) {
  const char *og_name = pokemon_names[uid];
  const ssize_t l = 11;
  const ssize_t namelen = strlen(og_name);
  // magic constants since no name is longer than 25 chars
  static char trim[32] = {0};
  ssize_t trimlen = 0;
  for (size_t i = 0; i < namelen; i++) {
    char x = og_name[i];
    if ((x <= 'z' && x >= 'a') || x == ' ') {
      trim[trimlen] = (x == ' ')? 0 : tolower(og_name[i]) - 'a' + 1;
      trimlen++;
    }
  }

  uint64_t acc = 0;
  for (uint64_t i = 0; i < trimlen; i++) {
    uint64_t c = trim[i];
    int8_t exp = l - 1 - i;
    exp = (exp > 0)? exp : 0;
    // a..z = 26; +1 for the space
    acc += powil(27, exp) * c;
  }
  uint64_t loff = l - namelen;
  acc += loff;
  assert(acc < (uint64_t)1<<54); // bounds check
  return acc;
}

int hash_tuple_cmp(const void *lhs, const void *rhs) {
  uint64_t a = *(uint64_t*)lhs >> 10;
  uint64_t b = *(uint64_t*)rhs >> 10;
  return (a > b) - (a < b);
}

void dyn_tables_init() {
  uint64_t *hashed_names = malloc(pokemon_count * sizeof(uint64_t));

  for (size_t i = 0; i < pokemon_count; i++) {
    hashed_names[i + 0] = pokemon_hash_name(i) << 10 | i;
  }

  qsort(
      hashed_names,
      pokemon_count,
      sizeof(uint64_t),
      hash_tuple_cmp
    );

  for (int i = 0; i < pokemon_count; i++) {
    uint64_t hash = hashed_names[i] >> 10;
    uint32_t id = hashed_names[i] & 0x3FF;
    printf("hash %lu, id %d, name %s\n", hash, id, pokemon_names[id]);
  }
  pokemon_hashed_names_btree = btree_from_ordered_vec(
      hashed_names,
      2*sizeof(uint32_t),
      pokemon_count
    );
  free(hashed_names);
}

void dyn_tables_fini() {
  btree_free(pokemon_hashed_names_btree);
}

