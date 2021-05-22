#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

int main(int argc, char* argv[]){

    int N = (int)(pow(10.0, atof(argv[1])));
    SIEVE_getPrimes(N);

    return 0;
}