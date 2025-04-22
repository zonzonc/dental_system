#include "avl.h"
#include <stdlib.h>
#include <string.h>

static int height(AvlNode *n){ return n? n->height : 0; }
static int max(int a,int b){ return a>b?a:b; }

static AvlNode *new_node(Patient *p){
    AvlNode *n = malloc(sizeof *n);
    n->data = p; n->left=n->right=NULL; n->height=1;
    return n;
}

static AvlNode *rotate_right(AvlNode *y){
    AvlNode *x=y->left;
    AvlNode *T2=x->right;
    x->right=y; y->left=T2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}

static AvlNode *rotate_left(AvlNode *x){
    AvlNode *y=x->right;
    AvlNode *T2=y->left;
    y->left=x; x->right=T2;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}

static int get_balance(AvlNode *n){
    return n? height(n->left)-height(n->right):0;
}

static AvlNode *insert_rec(AvlNode *node, Patient *p){
    if(!node) return new_node(p);
    int cmp = strcmp(p->id_card, node->data->id_card);
    if(cmp<0) node->left = insert_rec(node->left,p);
    else if(cmp>0) node->right = insert_rec(node->right,p);
    else return node; /* duplicate, ignore */

    node->height = 1+max(height(node->left),height(node->right));
    int bal = get_balance(node);
    /* LL */
    if(bal>1 && strcmp(p->id_card,node->left->data->id_card)<0)
        return rotate_right(node);
    /* RR */
    if(bal<-1 && strcmp(p->id_card,node->right->data->id_card)>0)
        return rotate_left(node);
    /* LR */
    if(bal>1 && strcmp(p->id_card,node->left->data->id_card)>0){
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    /* RL */
    if(bal<-1 && strcmp(p->id_card,node->right->data->id_card)<0){
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}

static void destroy_rec(AvlNode *n){
    if(!n) return;
    destroy_rec(n->left); destroy_rec(n->right);
    free(n);
}

static Patient *search_rec(const AvlNode *n,const char *key){
    if(!n) return NULL;
    int cmp = strcmp(key,n->data->id_card);
    if(cmp==0) return n->data;
    if(cmp<0) return search_rec(n->left,key);
    return search_rec(n->right,key);
}

AVLTree *avl_create(void){
    return calloc(1,sizeof(AVLTree));
}

void avl_destroy(AVLTree *t){
    if(t){ destroy_rec(t->root); free(t);}
}

bool avl_insert(AVLTree *t, Patient *p){
    if(!t) return false;
    t->root = insert_rec(t->root,p);
    return true;
}

Patient *avl_search(const AVLTree *t, const char *id_card){
    return t? search_rec(t->root,id_card):NULL;
}
