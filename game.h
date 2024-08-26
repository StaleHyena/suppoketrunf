#ifndef GAME_H__
#define GAME_H__
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "pokecards.h"
#include "utils.h"

#define MAX_PLAYERS 8

typedef int (*player_driver_fptr)(int);

typedef struct {
  stack_t hand;
  size_t card_cnt; // holdover from when we didn't have `stack_size`
  stack_t winnings;
  player_driver_fptr driver;
} player_t;

player_t
player_alloc(stack_t *take_pile, size_t card_cnt, player_driver_fptr driver);
void
player_free(player_t *p);

char *
player_repr_sall(player_t*);

enum game_state {
  GAME_RUN,
  GAME_RUN_DRAW,
  GAME_CANCEL_ROUND,
  GAME_STOP,
};

typedef struct {
  player_t players[MAX_PLAYERS];
  size_t player_cnt;
  size_t player_active;
  size_t total_cards;
  enum game_state state;
  stack_t draw_winnings;
  uint16_t draw_bitmask;
  uint16_t playing_bitmask;
} game_t;

char *
game_repr_sall(game_t*);

game_t
game_new(stack_t (*gen_cards_f)(size_t size), player_driver_fptr *, int player_cnt, int cards_per_player, long prng_seed);

void
game_next_round(game_t*);

void
game_free(game_t*);

#endif // GAME_H__
