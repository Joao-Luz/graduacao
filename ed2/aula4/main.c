#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "bst.h"

void print_int(bst* t){ printf("%d ", BST_get_key(t)); }
void nothing(bst* t){ return; }

int main(int argc, char* argv[]){

    if(argc < 2){
        printf("Please, type an input N\n");
        return 0;
    }
    int n = atoi(argv[1]);
    int qtd = pow(10, n);

    bst* t = BST_init();

    for(int i = 0; i < qtd; i++){
        int r = rand() % qtd;
        t = BST_insert(t, r);
    }

    printf("Height: %d\n", BST_height(t));

    BST_pre_treverse(t, print_int);
    BST_pre_treverse_it(t, print_int);

    BST_in_treverse(t, print_int);
    BST_in_treverse_it(t, print_int);

    BST_post_treverse(t, print_int);
    BST_post_treverse_it(t, print_int);

    BST_level_treverse(t, print_int);

    printf("\n");

    t = BST_delete(t);

    return 0;
}