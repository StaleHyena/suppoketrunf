#ifndef POKETABLES_H__
#define POKETABLES_H__
#include <stdint.h>
#include <stddef.h>
#define True 1
#define False 0

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

typedef struct {
  int hp, attack, defense, sp_attack, sp_defense, legendary;
} pokemon_stats_t;

const char *pokemon_type_repr_str(int type_id);

extern const char *pokemon_names[];
extern const uint8_t pokemon_name_lengths[];
extern const size_t pokemon_ids[];
extern enum pokemon_types_t pokemon_types[][2];
extern pokemon_stats_t pokemon_stats[];
extern size_t pokemon_count;

#endif // POKETABLES_H__
