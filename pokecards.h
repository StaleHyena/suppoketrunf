#ifndef POKECARDS_H__
#define POKECARDS_H__
#include <stdio.h>
#include <stdint.h>
#include "pokemon_tables.h"

typedef uint16_t pokecard_uid;

typedef enum {
  GROUP_UNDEF = 0,
  GROUP_A = 1,
  GROUP_B = 2,
  GROUP_C = 3,
  GROUP_D = 4,
} card_group_t;

char card_group_char(card_group_t cg);

char *pokecard_repr_simplestr_salloc(uint16_t uid);
char *pokecard_repr_simplestr_salloc_aligned(uint16_t uid, size_t namelen, size_t grace);
card_group_t pokecard_group_of(uint16_t uid);

#endif // POKECARDS_H__
