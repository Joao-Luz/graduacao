#include <stdlib.h>
#include <stdio.h>
#include "bst.h"
#include "stack.h"
#include "queue.h"

struct bst{
    bst* l;
    bst* r;
    int key;
};

typedef bst* bst_ptr;

bst* BST_init(){
    bst* t = NULL;
    return t;
}

bst* _BST_new_node(int key){
    bst* t = (bst*)malloc(sizeof(bst));
    t->l = t->r = NULL;
    t->key = key;

    return t;
}

bst* BST_insert(bst* t, int key){
    if(t == NULL) t = _BST_new_node(key);
    else if(key < t->key) t->l = BST_insert(t->l, key);
    else if(key > t->key) t->r = BST_insert(t->r, key);

    return t;
}

int BST_get_key(bst* t){
    return t->key;
}

void BST_pre_treverse(bst* t, void (*cb) (bst*)){
    if(t == NULL) return;
    cb(t);
    BST_pre_treverse(t->l, cb);
    BST_pre_treverse(t->r, cb);
}

void BST_pre_treverse_it(bst* t, void (*cb) (bst*)){
    if(t == NULL) return;
    stack(bst_ptr)* s = stack_init(bst_ptr);

    stack_push(s, t);
    while(stack_size(s) > 0){
        t = stack_pop(s);
        cb(t);
        if(t->r != NULL) stack_push(s, t->r); 
        if(t->l != NULL) stack_push(s, t->l);
    }

    stack_free(s);
}

void BST_in_treverse(bst* t, void (*cb) (bst*)){
    if(t == NULL) return;
    BST_in_treverse(t->l, cb);
    cb(t);
    BST_in_treverse(t->r, cb);
}

void BST_in_treverse_it(bst* t, void (*cb) (bst*)){
    stack(bst_ptr)* s = stack_init(bst_ptr);

    while(stack_size(s) > 0 || t != NULL){
        if(t != NULL){
            stack_push(s, t);
            t = t->l;
        }
        else{
            t = stack_pop(s);
            cb(t);
            t = t->r;
        }
    }

    stack_free(s);
}

void BST_post_treverse(bst* t, void (*cb) (bst*)){
    if(t == NULL) return;
    BST_post_treverse(t->l, cb);
    BST_post_treverse(t->r, cb);
    cb(t);
}

void BST_post_treverse_it(bst* t, void (*cb) (bst*)){
    stack(bst_ptr)* s = stack_init(bst_ptr);
    bst* last = NULL;

    while(stack_size(s) > 0 || t != NULL){
        if(t != NULL){
            stack_push(s, t);
            t = t->l;
        }
        else{
            bst* temp = stack_at(s, stack_size(s) - 1);
            if(temp->r != NULL && last != temp->r){
                t = temp->r;
            }
            else{
                cb(temp);
                last = stack_pop(s);
            }
        }
    }

    stack_free(s);
}

void BST_level_treverse(bst* t, void (*cb) (bst*)){
    queue(bst_ptr)* q = queue_init(bst_ptr);

    queue_push(q, t);
    while(queue_size(q) > 0){
        t = queue_pop(q);
        cb(t);
        if(t->l != NULL) queue_push(q, t->l);
        if(t->r != NULL) queue_push(q, t->r);
    }

    queue_free(q);
}

int BST_height(bst* t){
    if(t == NULL) return -1;
    int hl = 1 + BST_height(t->l);
    int hr = 1 + BST_height(t->r);
    return  hl > hr ? hl : hr; 
}

bst* BST_delete(bst* t){
    if(t == NULL) return NULL;
    BST_delete(t->l);
    BST_delete(t->r);
    free(t);
}
