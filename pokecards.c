#include "pokecards.h"

char *pokecard_repr_str_salloc(uint16_t uid) {
  #define BUFSZ 256
  static char buf[BUFSZ] = {0};
  const char *name = pokemon_names[uid];
  pokemon_stats_t s = pokemon_stats[uid];
  size_t offs = snprintf(buf, BUFSZ,
      "%s is a %s", name, pokemon_type_repr_str(pokemon_types[uid][0])
    );
  int second_type = pokemon_types[uid][1];
  if (second_type != Undef) {
    offs += snprintf(buf + offs, BUFSZ - offs, "/%s", pokemon_type_repr_str(second_type));
  }
  offs += snprintf(buf + offs, BUFSZ - offs, " type pokemon");
  
  offs += snprintf(buf + offs, BUFSZ - offs, ", which has"
      " %d total, %d hp, %d attack, %d defense, %d sp attack, %d sp defense, %d speed"
      ", is of the %d generation and is %slegendary.",
      s.total, s.hp, s.attack, s.defense, s.sp_attack, s.sp_defense, s.speed,
      s.generation, (s.legendary)? "" : "not ");
  return buf;
  #undef BUFSZ
}

