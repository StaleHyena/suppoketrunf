#include "pokemon_tables.h"
#define UID __LINE__ - 1

const char *pokemon_type_repr_str(int type_id) {
  #define X(NAME, TID) \
    [TID] = #NAME,

  const char *LUT[] = {
    POKETYPES_LIST
  };
  #undef X
  return LUT[type_id];
}

#define X(ID, NAME, T1, T2, TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY, LEN) \
  [UID] = ID,

const size_t pokemon_ids[] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, T1, T2, TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY, LEN) \
  [UID] = NAME,

const char *pokemon_names[] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, T1, T2, TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY, LEN) \
  [UID] = LEN,

const uint8_t pokemon_name_lengths[] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, T1, T2, TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY, LEN) \
  [UID] = { T1, T2 },

enum pokemon_types_t pokemon_types[][2] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, T1, T2, TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY, LEN) \
  [UID] = (pokemon_stats_t) {TOTAL, HP, ATK, DEF, SP_ATK, SP_DEF, SPEED, GEN, LEGENDARY},

pokemon_stats_t pokemon_stats[] = {
  #include "pokemon.h"
};

#undef X

#define X(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14) + 1

size_t pokemon_count = 0
  #include "pokemon.h"
;

#undef X

