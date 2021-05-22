#include <stdio.h>
#include <stdlib.h>
#include "josephus.h"

int main(int argc, char* argv[]){
    int N, M;
    N = atoi(argv[1]);
    M = atoi(argv[2]);

    JP_execute(N, M);
}