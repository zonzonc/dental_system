#include "heap.h"
#include <stdlib.h>
#include <string.h>

#define PARENT(i) ((i) >> 1)
#define LEFT(i)   ((i) << 1)
#define RIGHT(i)  (LEFT(i) + 1)

static void swap(Patient **a, Patient **b)
{
    Patient *t = *a; *a = *b; *b = t;
}

static void swim(MinHeap *h, int i)
{
    while (i > 1 && patient_compare(h->data[i], h->data[PARENT(i)]) < 0) {
        swap(&h->data[i], &h->data[PARENT(i)]);
        i = PARENT(i);
    }
}

static void sink(MinHeap *h, int i)
{
    while (LEFT(i) <= h->size) {
        int j = LEFT(i);
        if (j+1 <= h->size && patient_compare(h->data[j+1], h->data[j]) < 0) j++;
        if (patient_compare(h->data[i], h->data[j]) <= 0) break;
        swap(&h->data[i], &h->data[j]);
        i = j;
    }
}

static bool grow(MinHeap *h)
{
    int newcap = h->capacity * 2;
    Patient **nptr = realloc(h->data, (newcap + 1) * sizeof(Patient*));
    if (!nptr) return false;
    h->data = nptr;
    h->capacity = newcap;
    return true;
}

MinHeap *heap_create(int cap)
{
    if (cap < 8) cap = 8;
    MinHeap *h = malloc(sizeof *h);
    if (!h) return NULL;
    h->data = calloc(cap + 1, sizeof(Patient*));
    if (!h->data) { free(h); return NULL; }
    h->size = 0;
    h->capacity = cap;
    return h;
}

void heap_destroy(MinHeap *h)
{
    if (h) {
        free(h->data);
        free(h);
    }
}

bool heap_insert(MinHeap *h, Patient *p)
{
    if (!h) return false;
    if (h->size == h->capacity && !grow(h)) return false;
    h->data[++h->size] = p;
    swim(h, h->size);
    return true;
}

bool heap_top(const MinHeap *h, Patient **out)
{
    if (!h || h->size == 0) return false;
    if (out) *out = h->data[1];
    return true;
}

bool heap_pop(MinHeap *h, Patient **out)
{
    if (!heap_top(h, out)) return false;
    h->data[1] = h->data[h->size--];
    sink(h, 1);
    return true;
}

int heap_size(const MinHeap *h)
{
    return h ? h->size : 0;
}
