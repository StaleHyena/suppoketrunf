#ifndef UTILS_H__
#define UTILS_H__
#include <stdint.h>
#include <string.h>
#include "btree.h"
#include "queue.h"
#include "pokemon_dyntables.h"

uint64_t powil(uint8_t base, uint8_t exp);

typedef struct { int take; uint64_t val; } visitor_result_t;
void
queue_from_btree_inner(btree *bt, visitor_result_t (*visitor)(uint64_t, void *), void *visitor_args, queue_t **out, size_t depth);

queue_t *
queue_from_btree(btree *bt, size_t bt_depth, visitor_result_t (*visitor)(uint64_t, void *), void *visitor_args);

typedef struct { const char *buf; size_t buflen; } visitor_poke_starts_with_args_t;
visitor_result_t
visitor_poke_starts_with(uint64_t val, void *arg);

#endif // UTILS_H__
