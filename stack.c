#include "stack.h"

struct stack_data {
  stack_value_t val;
  stack_t next;
};

// PROMISE me: PROMISE you won't build arbitrary directed graphs with the
// powers I've granted you! You *will* double free. The only way
// to implement garbage collection that I could come up with (refcounting)
// would seriously harm the time complexity of pushing and popping.
// You've been warned.
stack_t
stack_push(stack_t handle, stack_value_t val) {
  stack_t s = calloc(sizeof(struct stack_data), 1);
  if (handle) s->next = handle;
  s->val = val;
  return s;
}

stack_t
stack_pop(stack_t handle, stack_value_t *out) {
  if (!handle) return NULL;
  *out = handle->val;
  stack_t aux = handle->next;
  free(handle);
  return aux;
}

int
stack_peek(stack_t handle, stack_value_t *out) {
  if (!handle) return 0;
  *out = handle->val;
  return 1;
}

void
stack_free(stack_t handle) {
  stack_value_t _;
  while(handle = stack_pop(handle, &_));
}

size_t stack_size(stack_t s) {
  size_t acc = 0;
  while(s->next) {
    s = s->next;
    acc++;
  }
  return acc;
}

char *stack_debug_str_sall4(stack_t handle) {
  #define BUFSZ 256
  static char buf[4][BUFSZ] = {0};
  static size_t bufidx = 0;
  if (!handle) {
    snprintf(buf[bufidx], BUFSZ, "(empty stack)");
    goto end;
  }
  size_t offs = 0;
  for (stack_t head = handle; head; head = head->next) {
    offs += snprintf(
        buf[bufidx] + offs,
        BUFSZ - offs,
        "(%d)%s", head->val, (head->next)? "->":""
      );
  }
end:
  char *r = buf[bufidx];
  bufidx = (bufidx + 1) % 4;
  return r;
}
