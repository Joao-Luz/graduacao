#include <stdlib.h>
#include "item.h"

#define SZ2      (sz+sz)
#define MIN(X,Y) ((X < Y) ? (X) : (Y))

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

void sort(Item* a,int lo,int hi){
    int N = (hi - lo) + 1;
    int y = N - 1;
    Item* aux = malloc(N * sizeof(Item));
    for(int sz = 1; sz < N; sz = SZ2){
        for(int lo = 0; lo < N-sz; lo += SZ2){
            int x = lo + SZ2 - 1;

            if (MIN(x,y) <= lo + CUTOFF - 1) insertion_sort(a, lo, MIN(x,y));
            else merge(a, aux, lo, lo+sz-1, MIN(x,y));
        }
    }
    free(aux);
}