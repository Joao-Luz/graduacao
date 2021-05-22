#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "item.h"

void shuffle(Item* a, int N){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand48(tv.tv_usec);

    for(int i = N-1; i > 0; i--){
        int j = (unsigned int) (drand48() * (i + 1));
        exch(a[i], a[j]);
    }
}

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

    shuffle(items, n);

    clock_t start, end;
    start = clock();

    sort(items, 0, n);
    
    end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time: %lfs\n", time);
    
    if(print){
        printf("[");
        if(n > 20){
            for(int i = 0; i < 5; i++){
                printf("%d, ", items[i]);
            }
            printf("... , ");
            for(int i = n-5; i < n; i++){
                printf("%d", items[i]);
                if(i != n - 1) printf(", ");
            }
        }
        else{
            for(int i = 0; i < n; i++){
                printf("%d", items[i]);
                if(i != n - 1) printf(", ");
            }
        }
        printf("]\n");
    }
    int sorted = 1;
    Item aux = items[0];
    for(int i = 1; i < n; i++){
        Item a = items[i];
        if(aux > a){
            sorted = 0;
            break;
        }
    }
    if(!sorted) printf("Not sorted!\n");

    free(items);
}