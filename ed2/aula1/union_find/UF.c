#include "UF.h"

static int id[1000];
static int N;

bool UF_connected(int p,int q) {
    return UF_find(p) == UF_find(q);
}

void UF_init(int size) {
    N = size;
    for(int i = 0; i < N; i++) {
        id[i] = i;
    }
}

int UF_find(int p) {
    return id[p];
}

void UF_union(int p,int q) {
    int pid = id[p];
    int qid = id[q];

    for(int i = 0; i < N; i++) {
        if(id[i] == pid) {
            id[i] = qid;
        }
    }
}