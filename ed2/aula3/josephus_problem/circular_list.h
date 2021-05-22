#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

typedef struct circular_list cl;
typedef struct _cl _cl;

cl* CL_init();

void CL_insert(cl* l, int n);

int CL_remove(cl* l, int idx);

int CL_get(cl* l, int idx);

void CL_delete(cl* l);

int CL_getSize(cl* l);

#endif