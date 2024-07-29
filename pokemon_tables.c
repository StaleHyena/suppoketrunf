#include "pokemon_tables.h"

const char *pokemon_type_repr_str(int type_id) {
  #define X(NAME, TID) \
    [TID] = #NAME,

  const char *LUT[] = {
    POKETYPES_LIST
  };
  #undef X
  return LUT[type_id];
}

#define X(ID, NAME, T1, T2, TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY) \
  [__LINE__ - 2] = ID,

const size_t pokemon_ids[] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, T1, T2, TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY) \
  [__LINE__ - 2] = NAME,

const char *pokemon_names[] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, T1, T2, TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY) \
  [__LINE__ - 2] = { T1, OR_UNDEF(T2) },

enum pokemon_types_t pokemon_types[][2] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, T1, T2, TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY) \
  [__LINE__ - 2] = (pokemon_stats_t) {TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY},

pokemon_stats_t pokemon_stats[] = {
  #include "pokemon.h"
};

#undef X

