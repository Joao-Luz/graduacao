#include <stdlib.h>
#include "../item.h"
#include "../stack.h"

#define push2(S, A, B) stack_push(S, B); stack_push(S, A)

int partition(Item* a, int lo, int hi){
    int i = lo, j = hi + 1;
    Item v = a[lo];
    while(1){
        while(less(a[++i], v)) if(i == hi) break;
        while(less(v, a[--j])) if(j == lo) break;
        if(i >= j) break;
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]);
    return j;
}

void quick_sort(Item* a,int lo,int hi){
    stack(int)* s = stack_init(int);
    push2(s, lo, hi);
    while(stack_size(s)){
        lo = stack_pop(s);
        hi = stack_pop(s);
        if(hi <= lo) continue;
        int i = partition(a, lo, hi);
        if(i-lo > hi-i){
            push2(s, lo, i-1);
            push2(s, i+1, hi);
        }
        else{
            push2(s, i+1, hi);
            push2(s, lo, i-1);
        }
    }
    stack_free(s);
}

void sort(Item*a, int lo, int hi){
    quick_sort(a, lo, hi);
}