#include "pokemon_dyntables.h"
#include <string.h>
#include <assert.h>
#include <ctype.h>

uint64_t pokemon_hash_name(const char *name) {
  const char *og_name = name;
  const ssize_t l = 11;
  const ssize_t namelen = strlen(og_name);
  // magic constants since no name is longer than 25 chars
  static uint8_t trim[32] = {0};
  ssize_t trimlen = 0;
  for (size_t i = 0; i < namelen; i++) {
    char x = tolower(og_name[i]);
    if ((x <= 'z' && x >= 'a') || x == ' ') {
      trim[trimlen] = (x == ' ')? 0 : x - 'a' + 1;
      //printf("trim[%zd] = ('%c' == ' ')? 0 : '%c' - 'a' + 1 = %hhu\n",
      //    trimlen, x, x, trim[trimlen]);
      trimlen++;
    }
  }

  uint64_t acc = 0;
  for (uint64_t i = 0; i < trimlen; i++) {
    uint64_t c = trim[i];
    int8_t exp = l - 1 - i;
    exp = (exp > 0)? exp : 0;
    // a..z = 26; +1 for the space
    //printf("acc = %lu; acc += powil(27, %hhu) * %lu\n", acc, exp, c);
    acc += powil(27, exp) * c;
  }
  uint64_t loff = l - namelen;
  //printf("acc = %lu; acc += %lu\n", acc, loff);
  acc += loff;
  //printf("acc = %lu\n", acc);
  assert(acc < (uint64_t)1<<54); // bounds check
  return acc;
}

int hash_tuple_cmp(const void *lhs, const void *rhs) {
  uint64_t a = *(uint64_t*)lhs >> 10;
  uint64_t b = *(uint64_t*)rhs >> 10;
  return (a > b) - (a < b);
}


