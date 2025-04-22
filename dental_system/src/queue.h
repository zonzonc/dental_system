#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
#include "dll.h"

typedef struct {
    DoublyLinkedList *list;
} Queue;

Queue *queue_create(void);
void queue_destroy(Queue *q, void (*free_fn)(void *));
bool queue_enqueue(Queue *q, void *data);
void *queue_dequeue(Queue *q);
size_t queue_size(const Queue *q);

#endif /* QUEUE_H */
