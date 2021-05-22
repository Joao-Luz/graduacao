#include <stdio.h>
#include "tTabuleiro.h"
#include "tStat.h"

int maiorVivos(tStat vetStat[], int tam, int start){
    
    tStat maior=vetStat[start];
    int i, id=start;
    
    for(i=start; i<tam; i++){
        if(vetStat[i].vivos > maior.vivos){
            maior=vetStat[i];
            id=i;
        }
    }
    return id;    
}

void ordenaStat(tStat vetStat[], int tam){
    
    int i, id, j;
    tStat aux;
    
    for(i=0; i<tam; i++){
        id=maiorVivos(vetStat, tam, i);
        for(j=id; j>i; j--){
            aux=vetStat[j];
            vetStat[j]=vetStat[j-1];
            vetStat[j-1]=aux;
        }       
    }     
}

int maisMortos(tStat vetStat[], int tam){
    
    int i, id, maiorMortos;
    
    maiorMortos=vetStat[tam-1].mortos;
    
    for(i=0; i<tam; i++){
        
        if(vetStat[i].mortos==maiorMortos){
            id=i;
            break;
        }
    }
    return id;
}

float media(tStat vetStat[], int qtd){
    
    float soma, media;
    int i, tam;
    
    tam=vetStat[0].vivos+vetStat[0].mortos;
    
    for(i=0; i<qtd; i++){    
        soma+=vetStat[i].vivos;    
    }
    media=soma/qtd;
    
    return media;   
}