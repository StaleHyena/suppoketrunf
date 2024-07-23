#ifndef POKETABLES_H__
#define POKETABLES_H__
#include <stdint.h>
#define True 1
#define False 0

// https://stackoverflow.com/a/72143776
#define EXPAND(x) x
#define ARGS_dummy(...) dummy,##__VA_ARGS__
#define SELECT_from5(_1,_2,_3,_4,_5,num,...) num
#define IS_EMPTY_impl(...) EXPAND(SELECT_from5(__VA_ARGS__,0,0,0,0,1))
#define IS_EMPTY(...) EXPAND(IS_EMPTY_impl(ARGS_dummy(__VA_ARGS__)))

// https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms
#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#define IIF(c) PRIMITIVE_CAT(IIF_, c)
#define IIF_0(t, ...) __VA_ARGS__
#define IIF_1(t, ...) t

#define OR_UNDEF(TYPE) IIF(IS_EMPTY(TYPE))(Undef, TYPE)

#define X(ID, NAME, T1, T2, TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY) \
  [__LINE__ - 1] = NAME,

const char *pokemon_names[] = {
#include "pokemon.h"
};

#undef X

#define POKETYPES_LIST \
  X(Normal, 0) \
  X(Fighting, 1) \
  X(Flying, 2) \
  X(Poison, 3) \
  X(Ground, 4) \
  X(Rock, 5) \
  X(Bug, 6) \
  X(Ghost, 7) \
  X(Steel, 8) \
  X(Fire, 9) \
  X(Water, 10) \
  X(Grass, 11) \
  X(Electric, 12) \
  X(Psychic, 13) \
  X(Ice, 14) \
  X(Dragon, 15) \
  X(Dark, 16) \
  X(Fairy, 17) \
  X(Stellar, 19) \
  X(Bird, 42) \
  X(Undef, 255) \

#define X(NAME, TID) \
  NAME = TID,

enum pokemon_types_t {
  POKETYPES_LIST
};

#undef X

const char *pokemon_type_repr_str(int type_id);

#define X(ID, NAME, T1, T2, TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY) \
  [__LINE__ - 1] = { T1, OR_UNDEF(T2) },

enum pokemon_types_t pokemon_types[][2] = {
  #include "pokemon.h"
};

#undef X

typedef struct {
  int total, hp, attack, defense, sp_attack, sp_defense, speed, generation, legendary;
} pokemon_stats_t;

#define X(ID, NAME, T1, T2, TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY) \
  [__LINE__ - 1] = (pokemon_stats_t) {TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY},

pokemon_stats_t pokemon_stats[] = {
  #include "pokemon.h"
};

#undef X

#endif // POKETABLES_H__
