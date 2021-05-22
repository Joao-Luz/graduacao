#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#define DEFAULT_STACK_SIZE 10

typedef struct stack stack;

stack* ST_init(size_t data_size);

void ST_push(stack* s, void* item);

void* ST_pop(stack* s);

void ST_delete(stack* s);

#endif