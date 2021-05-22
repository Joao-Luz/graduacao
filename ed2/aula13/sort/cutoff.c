#include <stdlib.h>
#include "../item.h"

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

void quick_sort(Item*a, int lo, int hi){
    if(hi <= lo + CUTOFF - 1){
        insertion_sort(a, lo, hi);
        return;
    }
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}

void sort(Item*a, int lo, int hi){
    quick_sort(a, lo, hi);
}