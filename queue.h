#ifndef QUEUE_H__
#define QUEUE_H__
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

typedef uint64_t queue_value_t;
struct queue_data;
typedef struct queue_data queue_t;

queue_t *queue_alloc(size_t);
queue_t *queue_insert(queue_t *, queue_value_t);
int queue_remove(queue_t *, queue_value_t *);
char *queue_debug_str_sall4(queue_t *handle);
int queue_peek(queue_t *, queue_value_t *);
void queue_free(queue_t *);

#endif // QUEUE_H__
