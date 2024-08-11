#include "utils.h"

uint64_t
powil(uint8_t base, uint8_t exp) {
  uint64_t acc = 1;
  while(exp) {
    acc *= base;
    exp--;
  }
  return acc;
}

void
queue_from_btree_inner(btree *bt, visitor_result_t (*visitor)(uint64_t, void *), void *visitor_args, queue_t **out, size_t depth) {
  if (!bt) return;
  
  queue_from_btree_inner(bt->l, visitor, visitor_args, out, depth + 1);

  visitor_result_t this_visit = visitor(bt->val, visitor_args);
  if (this_visit.take) {
    *out = queue_insert(*out, this_visit.val);
    if (0) printf("inserted %lu on queue\n", this_visit.val);
  }

  queue_from_btree_inner(bt->r, visitor, visitor_args, out, depth + 1);
}

queue_t *
queue_from_btree(btree *bt, size_t bt_depth, visitor_result_t (*visitor)(uint64_t, void *), void *visitor_args) {
  queue_t *q = queue_alloc((1 << bt_depth) - 1);
  queue_from_btree_inner(bt, visitor, visitor_args, &q, 0);
  return q;
}

visitor_result_t
visitor_poke_starts_with(uint64_t val, void *arg) {
  visitor_poke_starts_with_args_t *s = (visitor_poke_starts_with_args_t*)arg;
  visitor_result_t r = {.take = 0, .val = val};
  uint16_t id = val & 0x3FF;
  const char *pokename = pokemon_names[id];
  size_t pokenamelen = strlen(pokename);
  if (pokenamelen < s->buflen) return r;
  r.take = strncasecmp(s->buf, pokename, s->buflen) == 0;
  return r;
}
