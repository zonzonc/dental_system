#ifndef HEAP_H
#define HEAP_H
#include <stdbool.h>
#include "patient.h"

typedef struct {
    Patient **data;   /* index 1..size */
    int size;
    int capacity;
} MinHeap;

MinHeap *heap_create(int initial_capacity);
void     heap_destroy(MinHeap *h);

bool heap_insert(MinHeap *h, Patient *p);
bool heap_top   (const MinHeap *h, Patient **out);
bool heap_pop   (MinHeap *h, Patient **out);   /* extract-min */
int  heap_size  (const MinHeap *h);

#endif /* HEAP_H */
