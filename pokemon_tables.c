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

#define X(ID, NAME, LEN, T1, T2, TOTAL, HP, ATK, DEF, GEN) \
  [UID] = ID,

const size_t pokemon_ids[] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, LEN, T1, T2, TOTAL, HP, ATK, DEF, GEN) \
  [UID] = NAME,

const char *pokemon_names[] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, LEN, T1, T2, TOTAL, HP, ATK, DEF, GEN) \
  [UID] = LEN,

const uint8_t pokemon_name_lengths[] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, LEN, T1, T2, TOTAL, HP, ATK, DEF, GEN) \
  [UID] = { T1, T2 },

enum pokemon_types_t pokemon_types[][2] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, LEN, T1, T2, TOTAL, HP, ATK, DEF, GEN) \
  [UID] = (pokemon_stats_t) {TOTAL, HP, ATK, DEF, GEN},

pokemon_stats_t pokemon_stats[] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, LEN, T1, T2, TOTAL, HP, ATK, DEF, GEN) \
  +1

size_t pokemon_count = 0
  #include "pokemon.h"
;

#undef X

