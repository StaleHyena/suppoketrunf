#ifndef BTREE_H__
#define BTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct btree_data {
    uint64_t val;
    struct btree_data* l;
    struct btree_data* r;
} btree;

btree *btree_alloc(uint64_t val, btree *l, btree *r);
void btree_free(btree *bt);
void btree_print(btree *bt, void (*printfunc)(btree *));
void btree_print_char(btree *bt);
void btree_print_int(btree *bt);
btree *btree_from_ordered_vec(void *vec, size_t elmnt_size, size_t n_elmnts);

#endif // BTREE_H__
