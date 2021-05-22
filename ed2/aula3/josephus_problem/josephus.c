#include "josephus.h"
#include <stdio.h>
#include "circular_array.h"
#include "circular_list.h"

void JP_execute(int N, int M){
    ca* a = CA_init(N);
    //cl* a = CA_init();

    for(int i = 0; i < N; i++){
        CA_insert(a, i+1);
    }

    int last_idx = 0;
    while(CA_getSize(a) > 1){
        int idx = (last_idx + (M-1)) % CA_getSize(a);
        int rmv = CA_remove(a, idx);
        last_idx = idx;
        // printf("%d ", rmv);
    }

    // printf("\n");
    CA_delete(a);
}