#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "assert.h"
#include "string.h"

btree *btree_alloc(uint64_t val, btree *l, btree *r) {
  btree *bt = malloc(sizeof(btree));
  assert(bt); // allocation valid check
  bt->l = l;
  bt->r = r;
  bt->val = val;
  return bt;
}

void btree_free(btree *bt) {
  if (bt == NULL) return;
  if (bt->l) btree_free(bt->l);
  if (bt->r) btree_free(bt->r);
  free(bt);
}

void btree_print_inner(btree *a, int depth, void (*printfunc)(btree *a)) {
  if(a == NULL) {
    putc('\n', stdout);
    return;
  }
  putc('(', stdout);
  printfunc(a); //imprime raiz
  if (!a->l && !a->r) {
    puts(")");
    return;
  }
  putc('\n', stdout);
  for (int i = 0; i <= depth; i++) {
    putc(' ', stdout);
  }
  btree_print_inner(a->l, depth + 1, printfunc);
  for (int i = 0; i <= depth; i++) {
    putc(' ', stdout);
  }
  btree_print_inner(a->r, depth + 1, printfunc);
  for (int i = 0; i < depth; i++) {
    putc(' ', stdout);
  }
  puts(")");
}

void btree_print(btree *a, void (*printfunc)(btree *a)) {
  btree_print_inner(a, 0, printfunc);
}


static void print_char_node(btree *a) {
  printf("%c", (char)a->val);
}

void btree_print_char(btree *a){
  btree_print(a, print_char_node);
}

static void print_int_node(btree *a) {
  printf("%ld", a->val);
}

void btree_print_int(btree* a) {
  btree_print(a, print_int_node);
}

btree *btree_from_ordered_vec_inner(void *vec, size_t elmnt_size, ssize_t start_idx, ssize_t end_idx) {
  btree *bt = NULL;
  
  size_t middle = (end_idx + start_idx) / 2;
  void *cur_val = vec + elmnt_size * middle;

  if (start_idx > end_idx) { // base case
    return NULL;
  }
  bt = btree_alloc(0,
    btree_from_ordered_vec_inner(vec, elmnt_size, start_idx, middle - 1),
    btree_from_ordered_vec_inner(vec, elmnt_size, middle + 1, end_idx)
  );
  memcpy(&bt->val, cur_val, elmnt_size);
  return bt;
}

btree *btree_from_ordered_vec(void *vec, size_t elmnt_size, size_t n_elmnts) {
  assert(elmnt_size <= sizeof(uint64_t)); // does it fit in the val field?
  return btree_from_ordered_vec_inner(vec, elmnt_size, 0, n_elmnts - 1);
}

