#include "sieve.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void SIEVE_getPrimes(int N){
    int size = N/8 + 1;
    unsigned char* nums = (char*)malloc(size * sizeof(char));
    for(int i = 0; i < size; i++){
        nums[i] = 0;
    }
    for(int i = 2; i < N; i++){
        unsigned char aux = 128;
        unsigned char temp = (nums[i/8]<<(i % 8)) & aux;
        if(temp) continue;
        printf("%d ", i);
        for(int j = 2; (i * j) < N; j++){
            nums[(i*j)/8] = (nums[(i*j)/8]<<((i*j) % 8) | aux)>>((i*j) % 8);
        }
    }
    free(nums);
}