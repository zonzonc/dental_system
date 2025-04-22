#ifndef DLL_H
#define DLL_H
#include <stddef.h>

typedef struct DllNode {
    void *data;
    struct DllNode *prev, *next;
} DllNode;

typedef struct {
    DllNode *head, *tail;
    size_t   size;
} DoublyLinkedList;

DoublyLinkedList *dll_create(void);
void dll_destroy(DoublyLinkedList *l, void (*free_fn)(void *));
void dll_push_back(DoublyLinkedList *l, void *data);
void *dll_pop_front(DoublyLinkedList *l);
size_t dll_size(const DoublyLinkedList *l);

#endif /* DLL_H */
