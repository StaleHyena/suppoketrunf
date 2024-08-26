#ifndef UTILS_H__
#define UTILS_H__
#include <stdint.h>
#include <string.h>
#include "btree.h"
#include "queue.h"
#include "pokemon_dyntables.h"

#ifndef DEBUG
#define DEBUG_PRINT 0
#else
#define DEBUG_PRINT 1
#endif
#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#define EXPAND(x) x
#define IIF(cond) CAT(IIF_, cond)
#define IIF_0(t,f) f
#define IIF_1(t,f) t
#define DPRINTF(fmt, ...) IIF(DEBUG_PRINT)(fprintf(stderr, fmt, __VA_ARGS__),)
#define M2STRI(x) #x
#define M2STR(x) M2STRI(x)

#define BIT_GET(x,pos) ((x >> pos) & 0b1)
#define BIT_SET(x,pos) (x | (0b1 << pos))

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
