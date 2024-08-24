#ifndef GAME_H__
#define GAME_H__
#include <stdio.h>
#include <stdint.h>
#include "stack.h"
#include "queue.h"
#include "pokecards.h"

#define MAX_PLAYERS 8

typedef int (*player_driver_fptr)(int);

typedef struct {
  stack_t hand;
  size_t card_cnt;
  queue_t *winnings;
  player_driver_fptr driver;
} player_t;

player_t
player_alloc(stack_t *take_pile, size_t card_cnt, player_driver_fptr driver);

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
  queue_t *draw_winnings;
  int draw_bitmask;
} game_t;

char *
game_repr_sall(game_t*);

void
game_next_round(game_t*);

#endif // GAME_H__
