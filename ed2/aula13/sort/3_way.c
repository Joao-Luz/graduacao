#include <stdlib.h>
#include <sys/time.h>
#include "../item.h"

void shuffle(Item* a, int N){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand48(tv.tv_usec);

    for(int i = N-1; i > 0; i--){
        int j = (unsigned int) (drand48() * (i + 1));
        exch(a[i], a[j]);
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
    Item v = a[lo];
    int lt = lo, gt = hi, i = lo;
    while(i <= gt){
        if(a[i] < v){
            exch(a[lt], a[i]);
            lt++;
            i++;
        }
        else if(a[i] > v){
            exch(a[i], a[gt]);
            gt--;
        }
        else i++;
    }
    quick_sort(a, lo, lt-1);
    quick_sort(a, gt+1, hi);
}

void sort(Item*a, int lo, int hi){
    quick_sort(a, lo, hi);
}