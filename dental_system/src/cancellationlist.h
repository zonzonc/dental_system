#ifndef CANCELLATIONLIST_H
#define CANCELLATIONLIST_H
#include "dll.h"

typedef DoublyLinkedList CancellationList;

static inline CancellationList *cancellation_create(void){ return dll_create(); }
static inline void cancellation_destroy(CancellationList *l){ dll_destroy(l, NULL); }

#endif /* CANCELLATIONLIST_H */
