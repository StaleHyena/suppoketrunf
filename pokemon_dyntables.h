#ifndef POKEDYNTABLES_H__
#define POKEDYNTABLES_H__
#include <stdint.h>
#include "btree.h"
#include "pokemon_tables.h"
#include "utils.h"

extern btree *pokemon_hashed_names_btree;
extern size_t pokemon_hashed_names_btree_depth;

uint64_t pokemon_hash_name(const char *name);
void pokemon_hashed_names_init();

void dyn_tables_init();
void dyn_tables_fini();

#endif // POKEDYNTABLES_H__
