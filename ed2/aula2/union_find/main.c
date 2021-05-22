#include <stdio.h>
#include <stdlib.h>
#include "UF.h"

int main(int argc, char* argv[]) {
    int p, q, N = atoi(argv[1]);

    UF* uf = UF_init(N);
    
    while(scanf("%d %d", &p, &q) == 2) {
        if(!UF_connected(uf, p, q)) {
            UF_union(uf, p, q);
            printf("%d %d\n", p, q);
        }
    }

    UF_delete(uf);
    return 0;
}