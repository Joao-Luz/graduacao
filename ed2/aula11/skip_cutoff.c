#include <stdlib.h>
#include "item.h"

#define CUTOFF 10

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

void merge(Item* a, Item* aux, int lo, int mid, int hi){
    for(int k = lo; k <= hi; k++){
        aux[k] = a[k];
    }
    int i = lo, j = mid+1;
    for(int k = lo; k <= hi; k++){
        if      (i > mid)              a[k] = aux[j++];
        else if (j > hi)               a[k] = aux[i++];
        else if (less(aux[j], aux[i])) a[k] = aux[j++];
        else                           a[k] = aux[i++];
    }
}

void merge_sort(Item* a, Item* aux,int lo,int hi){
    if(hi <= lo + CUTOFF - 1){
        insertion_sort(a, lo, hi);
        return;
    }
    int mid = lo + (hi - lo) / 2;
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    if(!less(a[mid+1], a[mid])) return;
    merge(a, aux, lo, mid, hi);
}

extern void sort(Item* a, int lo, int hi){
    int n = (hi - lo) + 1;
    Item* aux = malloc(n*sizeof(Item));
    merge_sort(a, aux, lo, hi);
    free(aux);
}