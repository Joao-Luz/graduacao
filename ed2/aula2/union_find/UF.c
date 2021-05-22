#include "UF.h"
#include <stdlib.h>
#include <stdio.h>
//implementing the quick union algorithm

struct uf{
    int* sz;
    int* id;
};

bool UF_connected(UF* uf, int p, int q) {
    return UF_find(uf, p) == UF_find(uf, q);
}

UF* UF_init(int size) {
    UF* uf = (UF*)malloc(sizeof(UF));
    uf->id = (int*)malloc(size * sizeof(int));
    uf->sz = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        uf->id[i] = i;
        uf->sz[i] = 1;
    }
    
    return uf;
}

int UF_find(UF* uf, int i) {
    while(i != uf->id[i]) {
        uf->id[i] = uf->id[uf->id[i]]; //making use of the path halving technique
        i = uf->id[i];
    }
    return i;
}

void UF_union(UF* uf, int p,int q) {
    int i = UF_find(uf, p);
    int j = UF_find(uf, q);
    if(i == j) return;
    if(uf->sz[i] < uf->sz[j]) { uf->id[i] = j; uf->sz[j] += uf->sz[i]; }
    else              { uf->id[j] = i; uf->sz[i] += uf->sz[j]; }

}

void UF_delete(UF* uf){
    free(uf->id);
    free(uf->sz);
    free(uf);
}