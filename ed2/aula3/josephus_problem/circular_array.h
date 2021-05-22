#ifndef CIRCULAR_ARRAY_H
#define CIRCULAR_ARRAY_H

typedef struct circular_array ca;

ca* CA_init(int N);

void CA_insert(ca* l);

int CA_remove(ca* l, int idx);

int CA_get(ca* l, int idx);

void CA_delete(ca* l);

int CA_getSize(ca* l);

#endif