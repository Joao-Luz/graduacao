#include <stdio.h>
#include <stdlib.h>
#include "tJogo.h"

//alocacao dos espacos para tabuleiro
//perceba que as matrizes alocadas tem duas colunas e duas linhas a mais, para representar as possiveis bordas do tabuleiro
int atual[2502][2502]={0}, novo[2502][2502]={0}, ghost[2502][2502]={0};

int main(int argc, char **argv) {
    
    iniciaJogo(argc, argv, &atual[0][0], &novo[0][0], &ghost[0][0]);
    rodaJogo(argv);
    
    return (EXIT_SUCCESS);
}

