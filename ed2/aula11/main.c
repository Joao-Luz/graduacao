#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "item.h"

extern void sort(Item* a, int lo, int hi);

int main(int argc, char* argv[]){
    if(argc <= 1){
        printf("Please, input number of items to be sorted");
        return 0;
    }

    int n = atoi(argv[1]);
    int print = 1;
    if(argc >= 3 && !strcmp(argv[2], "false")) print = 0;

    Item* items = (Item*)malloc(sizeof(Item) * n);
    for(int i = 0; i < n; i++){
        int item;
        scanf("%d", &item);
        items[i] = item;
    }

    clock_t start, end;
    start = clock();

    sort(items, 0, n);
    
    end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time: %lfs\n", time);
    
    if(print){
        printf("[");
        for(int i = 0; i < n; i++){
            printf("%d", items[i]);
            if(i != n - 1) printf(", ");
        }
        printf("]");
    }

    free(items);
}