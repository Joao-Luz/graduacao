#include <stdlib.h>
#include "item.h"

extern void sort(Item* a, int lo, int hi){
    for(int i = lo + 1; i < hi; i++){
        int x = a[i];
        int j;
        for(j = i - 1; (j >= 0) && (less(x, a[j])); j--){
            a[j+1] = a[j];
        }
        a[j+1] = x;
    }
}