#include <stdlib.h>
#include "item.h"

extern void sort(Item* a, int lo, int hi){
    for(int i = lo; i < hi; i++){
        int smlst = i;
        for(int j = i; j < hi; j++){
            if(less(a[j], a[smlst])) smlst = j;
        }
        exch(a[i], a[smlst]);
    }
}