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

#define X(ID, ...) \
  [UID] = ID,

const size_t pokemon_ids[] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, ...) \
  [UID] = NAME,

const char *pokemon_names[] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, LEN, ...) \
  [UID] = LEN,

const uint8_t pokemon_name_lengths[] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, LEN, T1, T2, ...) \
  [UID] = { T1, T2 },

enum pokemon_types_t pokemon_types[][2] = {
  #include "pokemon.h"
};

#undef X

#define X(ID, NAME, LEN, T1, T2, HP, ATK, DEF, SPATK, SPDEF, LEG) \
  [UID] = (pokemon_stats_t) {HP, ATK, DEF, SPATK, SPDEF, LEG},

pokemon_stats_t pokemon_stats[] = {
  #include "pokemon.h"
};

#undef X

#define X(...) \
  +1

size_t pokemon_count = 0
  #include "pokemon.h"
;

#undef X

