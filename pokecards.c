#include "pokecards.h"

char *pokecard_repr_simplestr_salloc_aligned(uint16_t uid, size_t namelen, size_t grace) {
  #define BUFSZ 256
  static char buf[BUFSZ] = {0};
  const char *name = pokemon_names[uid];
  pokemon_stats_t s = pokemon_stats[uid];
  
  size_t offs = snprintf(buf, BUFSZ, "%s ", name);
  if (namelen) {
    while (offs < namelen) {
      buf[offs++] = ' ';
    }
  }
  offs += snprintf(buf + offs, BUFSZ - offs, "(%s",
      pokemon_type_repr_str(pokemon_types[uid][0]));
  int second_type = pokemon_types[uid][1];
  if (second_type != Undef) {
    offs += snprintf(buf + offs, BUFSZ - offs, "/%s", pokemon_type_repr_str(second_type));
  }
  offs += snprintf(buf + offs, BUFSZ - offs, "):");
  if (grace) {
    while (offs < namelen + grace) {
      buf[offs++] = ' ';
    }
  }
  offs += snprintf(buf + offs, BUFSZ - offs,
      " HP %3d"
      " ATK %3d"
      " DEF %3d"
      " SPATK %3d"
      " SPDEF %3d"
      "%s",
      s.hp, s.attack, s.defense, s.sp_attack, s.sp_defense,
      s.legendary? " ! LEGENDARY !" : ""
    );
  return buf;
  #undef BUFSZ
}

char *pokecard_repr_simplestr_salloc(uint16_t uid) {
  return pokecard_repr_simplestr_salloc_aligned(uid, 0, 0);
}

