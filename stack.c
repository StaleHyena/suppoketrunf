#include "stack.h"

struct stack_data {
  stack_value_t val;
  stack_t next;
};

stack_t
stack_push(stack_t handle, stack_value_t val) {
  stack_t s = calloc(sizeof(struct stack_data), 1);
  if (handle) s->next = handle;
  s->val = val;
  return s;
}

stack_t stack_pop(stack_t handle, stack_value_t *out) {
  if (!handle) return NULL;
  *out = handle->val;
  stack_t aux = handle->next;
  free(handle);
  return aux;
}

int stack_peek(stack_t handle, stack_value_t *out) {
  if (!handle) return 0;
  *out = handle->val;
  return 1;
}

void stack_free(stack_t handle) {
  while(stack_pop(handle));
}
