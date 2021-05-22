#include <stdlib.h>
#include "item.h"

extern void sort(Item* a, int lo, int hi){
    for(int i = lo; i < hi; i++){
        int swap = 0;
        for(int j = hi; j > i; j--){
            if(less(a[j], a[j-1])){
                exch(a[j], a[j-1]);
                swap = 1;
            }
        }
        if(!swap) break;
        for(int j = i + 1; j < hi; j++){
            if(less(a[j+1], a[j])){
                exch(a[j], a[j+1]);
                swap = 1;
            }
        }
        if(!swap) break;
    }
}