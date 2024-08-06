#ifndef POKEDYNTABLES_H__
#define POKEDYNTABLES_H__
#include <stdint.h>
#include "btree.h"
#include "pokemon_tables.h"

extern btree *pokemon_hashed_names_btree;

uint64_t pokemon_hash_name(int uid);

void dyn_tables_init();
void dyn_tables_fini();

#endif // POKEDYNTABLES_H__
