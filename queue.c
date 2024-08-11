#include "queue.h"

struct queue_data {
  queue_value_t *vals;
  size_t head, tail;
  size_t capacity;
  size_t size;
};

// util func
size_t
queue_mod(queue_t *handle, size_t idx) {
  return (handle->capacity > 0)? (idx % handle->capacity) : 0;
}

queue_t *
queue_alloc(size_t size_hint) {
  queue_t *nq = malloc(sizeof(struct queue_data));
  nq->capacity = size_hint;
  nq->size = 0;
  nq->vals = calloc(1, sizeof(queue_value_t) * nq->capacity);
  nq->head = 0;
  nq->tail = 0;
  return nq;
}

// private func FIXME: breaks when tail is not in the last position!
queue_t *
queue_realloc(queue_t *handle, size_t nsize) {
  handle->vals = realloc(handle->vals, nsize * sizeof(queue_value_t));
  handle->capacity = nsize;
  return handle;
}

queue_t *
queue_insert(queue_t *handle, queue_value_t nval) {
  if (!handle) return NULL;
  if (handle->size >= handle->capacity) {
    // then resize the backing buffer (currently broken)
    assert(0); // panic "for now"™
    handle = queue_realloc(handle, handle->capacity * 3 / 2);
  }

  handle->vals[handle->tail] = nval;
  handle->size++;
  handle->tail = queue_mod(handle, handle->head + handle->size);
  return handle;
}

int
queue_remove(queue_t *handle, queue_value_t *out) {
  int off = queue_peek(handle, out);
  handle->size = handle->size - off;
  handle->head = queue_mod(handle, handle->head + off);
  return off;
}

// doubles as an empty checker, returns falsy if empty
int
queue_peek(queue_t *handle, queue_value_t *out) {
  if (!handle || handle->size == 0) return 0;
  *out = handle->vals[handle->head];
  return 1;
}

void
queue_free(queue_t *handle) {
  if (handle->vals) {
    free(handle->vals);
    handle->vals = NULL;
  }
  free(handle);
}

char *
queue_debug_str_sall4(queue_t *handle) {
  #define BUFSZ 256
  static char buf[4][BUFSZ] = {0};
  static size_t bufidx = 0;
  if (!handle || !handle->vals || handle->size == 0) {
    snprintf(buf[bufidx], BUFSZ, "(empty queue)");
    goto end;
  }
  size_t offs = 0;
  for(int i = 0; i < handle->size; i++) {
    size_t idx = queue_mod(handle, handle->head + i);
    offs += snprintf(
        buf[bufidx] + offs,
        BUFSZ - offs,
        "%s%d%s%s",
        (idx == handle->head)? "{" : (idx == handle->tail)? "[" : "(",
        handle->vals[idx],
        (idx == handle->head)? "}" : (idx == handle->tail)? "]" : ")",
        (idx != (handle->tail - 1))? "->":""
      );
  }
end:
  char *r = buf[bufidx];
  bufidx = (bufidx + 1) % 4;
  return r;
}
