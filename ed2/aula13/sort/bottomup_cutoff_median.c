#include <stdlib.h>
#include "../item.h"
#include "../stack.h"

#define push2(S, A, B) stack_push(S, B); stack_push(S, A)

#define CUTOFF 15

static void insertion_sort(Item *a, int lo, int hi) {
    for (int i = lo + 1; i <= hi; ++i) {
        Item key = key(a[i]);
        int k = i;

        while (k > lo && less(key, a[k-1])) {
            a[k] = a[k - 1];
            k--;
        }
        a[k] = key;
    }
}

int median_of_3(Item* a, int lo, int hi){
     struct timeval tv;
    gettimeofday(&tv, NULL);
    srand48(tv.tv_usec);

    int i = (unsigned int) (drand48() * (hi - lo) + lo);
    int j = (unsigned int) (drand48() * (hi - lo) + lo);
    int k = (unsigned int) (drand48() * (hi - lo) + lo);

    if(a[i] > a[j]){
        if(a[j] > a[k]) return j;
        else if(a[i] > a[k]) return k;
        else return i; 
    }
    else{
        if(a[i] > a[k]) return i;
        else if(a[j] > a[k]) return k;
        else return j; 
    }
}

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
        if(hi <= lo + CUTOFF - 1){
            insertion_sort(a, lo, hi);
            continue;
        }
        int median = median_of_3(a, lo, hi);
        exch(a[lo], a[median]);
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