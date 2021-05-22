#include "dijkstra_stack.h"
#include "stack.h"
#include <stdio.h>

int main(int argc, char* argv[]){
    char op[256];
    while (scanf(" %[^\n]", op) == 1){
        printf("%s = %lf\n", op, DS_execute(op));
    }
    return 0;
}
