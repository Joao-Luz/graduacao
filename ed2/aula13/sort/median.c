#include <stdlib.h>
#include "../item.h"

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

void quick_sort(Item*a, int lo, int hi){
    if(hi <= lo) return;
    int median = median_of_3(a, lo, hi);
    exch(a[lo], a[median]);
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}

void sort(Item*a, int lo, int hi){
    quick_sort(a, lo, hi);
}