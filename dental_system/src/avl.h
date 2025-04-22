#ifndef AVL_H
#define AVL_H
#include <stdbool.h>
#include "patient.h"

/* 簡化版 AVL：僅支援插入與搜尋；用連結指標作為 key。 */

typedef struct AvlNode {
    Patient *data;
    struct AvlNode *left, *right;
    int height;
} AvlNode;

typedef struct {
    AvlNode *root;
} AVLTree;

AVLTree *avl_create(void);
void     avl_destroy(AVLTree *t);                  /* 不會 free data 本身 */
bool     avl_insert(AVLTree *t, Patient *p);
Patient *avl_search(const AVLTree *t, const char *id_card);

#endif/* AVL_H */
