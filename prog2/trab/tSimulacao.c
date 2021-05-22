#include <stdio.h>
#include "tTabuleiro.h"

int troca=0;

void leTrocas(tTabuleiro *tabuleiro, tConfig *config){
    int x, i;
    
    if(config->trocas[troca][0]==tabuleiro->gen){
            for(i=0, x=2; i<config->trocas[troca][1]; i++, x+=2){
                trocaCel(tabuleiro->pAtual, config->trocas[troca][x], config->trocas[troca][x+1], tabuleiro->w);
            }
            troca++;
        }
}

int contaVizinhos(int *tabuleiro, int x, int y, int col){
    
    int soma=0, i, j;
    
    for(i=-1; i<=1; i++){
        for(j=-1; j<=1; j++){
            if(!(i==0 && j==0)){
                soma+=*(tabuleiro+(x+i)*col+(y+j));
            }
        }
    }
    return soma;
}

void swap(int** a, int** b){
    
    int*aux=*a;
    *a=*b;
    *b=aux;
    
}

void trocaGen(tTabuleiro *tabuleiro){
    
    int i, j, col=tabuleiro->w, lin=tabuleiro->h, estado, vizinhos;
    
    for(i=1; i<lin-1; i++){
        for(j=1; j<col-1; j++){
            estado=*(tabuleiro->pAtual+i*col+j);
            vizinhos=contaVizinhos(tabuleiro->pAtual, i, j, col);
            
            if(estado==0 && vizinhos==3) *(tabuleiro->pNovo+i*col+j)=1;
            else if(estado==1 && (vizinhos<2 || vizinhos>3)) *(tabuleiro->pNovo+i*col+j)=0;
            else *(tabuleiro->pNovo+i*col+j)=*(tabuleiro->pAtual+i*col+j);
        }       
    }    
}

void simulaJogo(tTabuleiro *tabuleiro, tConfig *config){
    
        if(tabuleiro->gen>0){
            leTrocas(tabuleiro, config);

            trocaGen(tabuleiro);
        }   
}

void geraGhost(tTabuleiro *tabuleiro){
    
    int i, j, lin, col;
    
    lin=tabuleiro->h;
    col=tabuleiro->w;
    
    for(i=1; i<lin-1; i++){
        for(j=1; j<col-1; j++){
            if(*(tabuleiro->pNovo+i*col+j)) *(tabuleiro->pGhost+i*col+j)=1;
        }       
    }
    
}