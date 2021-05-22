#include "circular_list.h"
#include <stdlib.h>
#include <stdio.h>

struct _cl{
    _cl* next;
    int n;
};


struct circular_list{
    _cl* fst;
    _cl* lst;
    int size;
};

cl* CL_init(){
    cl* l = (cl*)malloc(sizeof(cl));
    l->fst = l->lst = NULL;
    l->size = 0;
}

void CL_insert(cl* l, int n){
    _cl* node = (_cl*)malloc(sizeof(_cl));
    node->next = l->fst;
    node->n = n;
    if(!l->fst){
        l->fst = node;
        l->lst = node;
    }
    else{
        l->lst->next = node;
        l->lst = node;
    }
    l->size++;
}

int CL_remove(cl* l, int idx){
    _cl* tmp = l->fst;
    _cl* bfr = l->lst;
    for(int i = 0; i < idx; i++, tmp = tmp->next, bfr = bfr->next);

    bfr->next = tmp->next;
    if(tmp == l->fst) l->fst = bfr->next;
    else if(tmp == l->lst) l->lst = bfr;
    else if(tmp == l->fst && tmp == l->lst) l->fst = l->lst = NULL;

    int n = tmp->n;
    free(tmp);

    l->size--;

    return n;
}

int CL_get(cl* l, int idx){
    _cl* tmp = l->fst;
    for(int i = 0; i < idx; i++, tmp = tmp->next);

    return tmp->n;
}

int CL_getSize(cl* l){
    return l->size;
}

void CL_delete(cl* l){
    _cl* tmp = l->fst;
    _cl* nxt;
    do{
        nxt = tmp->next;
        free(tmp);
        tmp = nxt;
    }while(tmp != l->fst);
    free(l);
}
