#include "circular_array.h"
#include <stdlib.h>
#include <stdio.h>

struct circular_array{
    int size;
    int capacity;
    int circle_size;
    unsigned char* rmv;
};

ca* CA_init(int N){
    ca* a = (ca*)malloc(sizeof(ca));
    a->rmv = (char*)malloc((N/8 + 1) * sizeof(char));
    for(int i = 0; i < (N/8 + 1); i++){
        a->rmv[i] = 0;
    }
    a->size = 0;
    a->capacity = (N/8 + 1);
    a->circle_size = 0;
}

void CA_insert(ca* a){
    a->size++;
    a->circle_size++;
    if(a->size/8 + 1 > a->capacity){
        a->rmv = realloc(a->rmv, (a->size / 8 + 1) * sizeof(char));
        a->rmv[a->size / 8] = 0;
        a->capacity++;
    }
}

int CA_remove(ca* a, int idx){
    int i = 0;
    unsigned char cmp = 128;
    for(int j = 0; j <= (idx % a->circle_size); j++){
        unsigned char tmp = (a->rmv[i/8] << (i % 8) & cmp);
        while(tmp){
            i++;
            tmp = (a->rmv[i/8] << (i % 8) & cmp);
        }
        i++;
    }
    a->circle_size--;
    i = (i - 1) % a->size;
    a->rmv[i/8] = (a->rmv[i/8] << (i % 8) | cmp) >> (i % 8);

    return i + 1;
}

int CA_get(ca* a, int idx){
    int i = 0;
    unsigned char cmp = 128;
    for(int j = 0; j <= (idx % a->circle_size); j++){
        unsigned char tmp = (a->rmv[i/8] << (i % 8) & cmp);
        while(tmp){
            i++;
            tmp = (a->rmv[i/8] << (i % 8) & cmp);
        }
        i++;
    }
    i = (i - 1) % a->size;
    return i + 1;
}

int CA_getSize(ca* a){
    return a->circle_size;
}

void CA_delete(ca* a){
    free(a->rmv);
    free(a);
}
