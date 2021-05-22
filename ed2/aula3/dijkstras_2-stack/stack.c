#include "stack.h"
#include <string.h>
#include <stdio.h>

struct stack{
    char* data;
    size_t data_size;
    int size;
    int capacity;
};

stack* ST_init(size_t data_size){
    stack* s = (stack*)malloc(sizeof(stack));
    s->data = malloc(DEFAULT_STACK_SIZE * data_size);
    s->size = 0;
    s->capacity = DEFAULT_STACK_SIZE;
    s->data_size = data_size;

    return s;
}

void ST_push(stack* s, void* data){
    if(s->size == s->capacity){
        s->capacity += 10;
        s->data = realloc(s->data, s->capacity * s->data_size);
    }
    memcpy(s->data + (s->size * s->data_size), data, s->data_size);
    s->size++;

}

void* ST_pop(stack* s){
    void* data = s->data + (s->size - 1) * s->data_size;
    s->size--;

    return data;
}

void ST_delete(stack* s){
    free(s->data);
    free(s);
}

