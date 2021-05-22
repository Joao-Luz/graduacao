#include <stdio.h>
#include "tTabuleiro.h"
#include "tArquivos.h"
#include "tJogo.h"


void iniciaTab(tTabuleiro *tabuleiro, tConfig *config, int *atual, int *novo, int *ghost){
    
    int a, i;
    
    tabuleiro->h=config->h;
    tabuleiro->w=config->w;
    tabuleiro->maxGen=config->maxGen;
    
    tabuleiro->pAtual=atual;
    tabuleiro->pNovo=novo;
    tabuleiro->pGhost=ghost;
    
    //o programa inicializa os tres tabuleiros (atual, novo e ghost) da mesma forma
    for(i=0, a=1; i<config->start[0]; i++, a+=2){        
        trocaCel(tabuleiro->pAtual, config->start[a], config->start[a+1], tabuleiro->w);
        trocaCel(tabuleiro->pNovo, config->start[a], config->start[a+1], tabuleiro->w);
        trocaCel(tabuleiro->pGhost, config->start[a], config->start[a+1], tabuleiro->w);
    }    
}

void trocaCel(int *tabuleiro, int x, int y, int col){
    //os valores das posicoes x e y sao incrementados em 1 pois as posicoes fornecidas no arquivo config nao levam em consideracao as bordas implementadas
    x++;
    y++;
    
    if(*(tabuleiro+(x*col+y))) *(tabuleiro+(x*col+y))=0;
    else *(tabuleiro+(x*col+y))=1;
}

void imprimeTabuleiro(int *tabuleiro, int col, int lin){
    
    int i, j;
    
    for(i=1; i<lin-1; i++){
        for(j=1; j<col-1; j++){
            if(*(tabuleiro+(i*col+j))) printf("O");
            else printf("-");
        }  
        printf("\n");
    }   
}

int contaVivas(tTabuleiro *tabuleiro){
    
    int i, j, lin, col, vivas=0;
    lin=tabuleiro->h;
    col=tabuleiro->w;
    
    //o laco e uma forma mais elegante de se contar os vizinhos de uma celula
    //perceba que se a celula se encontra no limite proposto pelo arquivo config ela ainda possui 8 vizinhos, porem os que nao estao compreendidos por esse limite possuem valor 0
    for(i=1; i<lin-1; i++){
        for(j=1; j<col-1; j++){
            vivas+=*(tabuleiro->pNovo+(i*col+j));
        }  
    }   
    return vivas;
}

