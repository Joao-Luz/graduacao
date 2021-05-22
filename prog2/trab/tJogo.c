#include <stdio.h>
#include "tArquivos.h"
#include "tTabuleiro.h"
#include "tSimulacao.h"
#include "tStill_lifes.h"
#include "tStat.h"

//variaveis globais sao utilizadas com cautela para evitar uso indevido da memoria
tTabuleiro tabuleiro;
tConfig config;
tStill vetStill[5];


void iniciaJogo(int argc, char** argv, int *atual, int *novo, int *ghost){
    
    config=leArquivo(argc, argv);   
    
    iniciaTab(&tabuleiro, &config, atual, novo, ghost); 
    
}

void rodaJogo(char** argv){
    
    tStat vetStat[config.maxGen];
    int i,lin,col;
    
    lin=tabuleiro.h;
    col=tabuleiro.w;
    
    for(i=0; i<5; i++){
        vetStill[i].qtd=0;
    }
    
    for(i=0; i<tabuleiro.maxGen; i++){
        tabuleiro.gen=i;
                
        simulaJogo(&tabuleiro, &config);
        tabuleiro.vivas=contaVivas(&tabuleiro);
        imprimeOutput(argv, tabuleiro.pNovo, tabuleiro.vivas, i, lin, col);
        geraGhost(&tabuleiro);
        procuraStills(tabuleiro.pNovo, lin, col, &vetStill[0]);
        
        vetStat[i].vivos=tabuleiro.vivas;
        vetStat[i].gen=i;
        vetStat[i].mortos=(lin-2)*(col-2)-tabuleiro.vivas;
        
        swap(&tabuleiro.pAtual, &tabuleiro.pNovo);
    }
    
    imprimeGhost(argv, tabuleiro.pGhost, lin, col);
    ordenaStill(vetStill);
    imprimeStill(argv, &vetStill[0]);
    ordenaStat(vetStat, config.maxGen);
    imprimeStat(argv, vetStat, config.maxGen);
    
    
}
