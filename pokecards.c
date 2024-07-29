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

char *pokecard_repr_simplestr_salloc(uint16_t uid) {
  #define BUFSZ 256
  static char buf[BUFSZ] = {0};
  const char *name = pokemon_names[uid];
  pokemon_stats_t s = pokemon_stats[uid];
  size_t offs = snprintf(buf, BUFSZ,
      "%s (%s", name, pokemon_type_repr_str(pokemon_types[uid][0])
    );
  int second_type = pokemon_types[uid][1];
  if (second_type != Undef) {
    offs += snprintf(buf + offs, BUFSZ - offs, "/%s", pokemon_type_repr_str(second_type));
  }
  offs += snprintf(buf + offs, BUFSZ - offs, ")");
  
  offs += snprintf(buf + offs, BUFSZ - offs,
      ": TOTAL %d"
      " HP %d"
      " ATK %d"
      " DEF %d"
      " GROUP %c",
      s.total, s.hp, s.attack, s.defense,
      card_group_char(pokecard_group_of(uid))
    );
  return buf;
  #undef BUFSZ
}

card_group_t
pokecard_group_of(uint16_t uid) {
  int first = pokemon_types[uid][0];

  /* Old balancing, considering both primary and secondary types
#define IS(TYPE) (first == TYPE || second == TYPE)

  if (0
      || IS(Ground)
      || IS(Rock)
      || IS(Bug)
      || IS(Grass)
      || IS(Fighting))
    return GROUP_A;
  else if (0
      || IS(Normal)
      || IS(Poison)
    ) return GROUP_B;
  else if (0
      || IS(Water)
      || IS(Psychic)
      || IS(Electric)
    ) return GROUP_C;
  else if (0
      || IS(Ice)
      || IS(Dragon)
      || IS(Dark)
      || IS(Fairy)
      || IS(Flying)
      || IS(Fire)
      || IS(Steel)
      || IS(Ghost)
    ) return GROUP_D;
#undef IS
  */

  /* Simplified groups */
#define IS(TYPE) (first == TYPE)
    if (0 // 42 pokes
      || IS(Normal)
      || IS(Fairy)
      || IS(Dragon)
      || IS(Ice)
      || IS(Psychic)
    ) return GROUP_A;
    else if (0 // 41 pokes
      || IS(Water)
      || IS(Rock)
    ) return GROUP_B;
    else if (0 // 41 pokes
      || IS(Fire)
      || IS(Electric)
      || IS(Ghost)
      || IS(Bug)
    ) return GROUP_C;
    else if (0 // 42 pokes
      || IS(Grass)
      || IS(Fighting)
      || IS(Poison)
      || IS(Ground)
    ) return GROUP_D;
#undef IS

  return GROUP_UNDEF;
}

char
card_group_char(card_group_t cg) {
  char *LUT = "?ABCD";
  return LUT[cg];
}
