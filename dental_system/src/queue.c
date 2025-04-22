#include "queue.h"
#include <stdlib.h>

Queue *queue_create(void)
{
    Queue *q = malloc(sizeof *q);
    if (!q) return NULL;
    q->list = dll_create();
    if (!q->list) { free(q); return NULL; }
    return q;
}

void queue_destroy(Queue *q, void (*free_fn)(void *))
{
    if (!q) return;
    dll_destroy(q->list, free_fn);
    free(q);
}

bool queue_enqueue(Queue *q, void *data)
{
    if (!q) return false;
    dll_push_back(q->list, data);
    return true;
}

void *queue_dequeue(Queue *q)
{
    if (!q) return NULL;
    return dll_pop_front(q->list);
}

size_t queue_size(const Queue *q)
{
    return q ? dll_size(q->list) : 0;
}
