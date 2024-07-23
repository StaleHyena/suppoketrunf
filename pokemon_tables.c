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
