#ifndef POKECARDS_H__
#define POKECARDS_H__
#include <stdio.h>
#include <stdint.h>
#include "pokemon_tables.h"

typedef uint16_t pokecard_uid;

char *pokecard_repr_simplestr_salloc(uint16_t uid);
char *pokecard_repr_simplestr_salloc_aligned(uint16_t uid, size_t namelen, size_t grace);

#endif // POKECARDS_H__
