#include <stdio.h>

#include "tStill_lifes.h"
#include "tTabuleiro.h"

//declaracao de variaveis globais para minimizar problemas de uso indevido da memoria
int shapeBeehive[5][6]={{0,0,0,0,0,0},{0,0,1,1,0,0},{0,1,0,0,1,0},{0,0,1,1,0,0},{0,0,0,0,0,0}};
int shapeLoaf[6][6]={{0,0,0,0,0,0},{0,0,1,1,0,0},{0,1,0,0,1,0},{0,0,1,0,1,0},{0,0,0,1,0,0},{0,0,0,0,0,0}};
int shapeBoat[5][5]={{0,0,0,0,0},{0,1,1,0,0},{0,1,0,1,0},{0,0,1,0,0},{0,0,0,0,0}};
int shapeTub[5][5]={{0,0,0,0,0},{0,0,1,0,0},{0,1,0,1,0},{0,0,1,0,0},{0,0,0,0,0}};
int shapeBlock[4][4]={{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}};

void procuraStills(int *tabuleiro, int lin, int col, tStill* vetStill){
    
    int i, j;
    
    iniciaStills(vetStill, (vetStill+1), (vetStill+2), (vetStill+3), (vetStill+4));
    
    verificaStill(tabuleiro, lin, col, vetStill);
    verificaStill(tabuleiro, lin, col, (vetStill+1));
    verificaStill(tabuleiro, lin, col, (vetStill+2));
    verificaStill(tabuleiro, lin, col, (vetStill+3));
    verificaStill(tabuleiro, lin, col, (vetStill+4));
}

//still liffes sao incializadas em ordem alfabetica para evitar uso de uma fucao que realiza essa tarefa
void iniciaStills(tStill *beehive, tStill *block, tStill *boat, tStill *loaf, tStill *tub){   
    
    block->nome="Block";
    block->lin=4;
    block->col=4;
    block->formato=&shapeBlock[0][0];
    
    beehive->nome="Beehive";
    beehive->lin=5;
    beehive->col=6;
    beehive->formato=&shapeBeehive[0][0];
    
    loaf->nome="Loaf";
    loaf->lin=6;
    loaf->col=6;
    loaf->formato=&shapeLoaf[0][0];
    
    boat->nome="Boat";
    boat->lin=5;
    boat->col=5;
    boat->formato=&shapeBoat[0][0];
    
    tub->nome="Tub";
    tub->lin=5;
    tub->col=5;
    tub->formato=&shapeTub[0][0];
    
}

void verificaStill(int *tabuleiro, int lin, int col, tStill* still){
    
    int i, j, limI, limJ;
  
    limI=still->lin+1;
    limJ=still->col+1;
    
    for(i=1; i<=lin-limI; i++){
        for(j=1; j<=col-limJ; j++){            
            if(comparaStill(tabuleiro, col, j, i, still)){
                still->qtd++;
            }            
        }       
    }
}

int comparaStill(int *tabuleiro, int col, int x, int y, tStill *still){
    
    int i, j, a, b, result=1 ,tamLin, tamCol;
    
    tamLin=still->lin;
    tamCol=still->col;
    
      //printf("%d\n",y);
    
    for(i=0, a=y; i<tamLin; i++, a++){
      
        for(j=0, b=x; j<tamCol; j++, b++){
            //printf("%d ",*(tabuleiro+(a*col+b)));
            result*=(*(tabuleiro+(a*col+b))==*(still->formato+(i*tamCol+j)));
        }
        //printf("\n");
    }
    
    //printf("\n\n\n");
    return result;
}

int achaMaior(tStill pvetStill[], int start){
    
    tStill maior=pvetStill[start];
    int i, id=start;
    
    for(i=start; i<5-start; i++){
        if(pvetStill[i].qtd > maior.qtd){
            maior=pvetStill[i];
            id=i;
        }
    }
    return id;
}

void ordenaStill(tStill pvetStill[]){
    
    int i, id, j;
    tStill aux;
    
    for(i=0; i<5; i++){
        id=achaMaior(pvetStill, i);
        for(j=id; j>i; j--){
            aux=pvetStill[j];
            pvetStill[j]=pvetStill[j-1];
            pvetStill[j-1]=aux;
        }       
    }   
}

