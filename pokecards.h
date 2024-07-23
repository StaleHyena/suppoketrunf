#ifndef POKECARDS_H__
#define POKECARDS_H__
#include <stdio.h>
#include <stdint.h>

typedef pokecard_uid uint16_t;

char *pokecard_repr_str_salloc(uint16_t uid);

#endif // POKECARDS_H__
