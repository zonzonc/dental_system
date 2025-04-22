#include "dll.h"
#include <stdlib.h>

DoublyLinkedList *dll_create(void)
{
    return calloc(1, sizeof(DoublyLinkedList));
}

void dll_destroy(DoublyLinkedList *l, void (*free_fn)(void *))
{
    if (!l) return;
    DllNode *cur = l->head;
    while (cur) {
        DllNode *nxt = cur->next;
        if (free_fn) free_fn(cur->data);
        free(cur);
        cur = nxt;
    }
    free(l);
}

void dll_push_back(DoublyLinkedList *l, void *data)
{
    DllNode *node = malloc(sizeof *node);
    node->data = data;
    node->prev = l->tail;
    node->next = NULL;
    if (l->tail) l->tail->next = node;
    l->tail = node;
    if (!l->head) l->head = node;
    l->size++;
}

void *dll_pop_front(DoublyLinkedList *l)
{
    if (!l || !l->head) return NULL;
    DllNode *node = l->head;
    void *ret = node->data;
    l->head = node->next;
    if (l->head) l->head->prev = NULL;
    else l->tail = NULL;
    free(node);
    l->size--;
    return ret;
}

size_t dll_size(const DoublyLinkedList *l)
{
    return l ? l->size : 0;
}
