#include <stdio.h>
#include <stdlib.h>
#include "tArquivos.h"
#include "tTabuleiro.h"
#include "tStill_lifes.h"
#include "tStat.h"

tConfig leArquivo(int argc, char** argv){
    
    tConfig configs;
    int i, gen=0,a;
    
    if(argc<=1){
        printf("DIRETORIO NAO INFORMADO, ANIMAL!!!\n");
        exit(0);
    }
    
    FILE *config;
    char dir[1000];
    
    sprintf (dir, "%s/config.txt", argv[1]);
    config=fopen(dir, "r");
    
    if(!config){
        printf("ARQUIVO NAO ENCONTRADO, ANIMAL!!!\n");
        exit(0);
    }
    
    printf("O ARQUIVO LIDO FOI ESSE AQUI:%s\n",dir);
    
    fscanf(config,"shape=%d,%d\nmax_gen=%d\n",&configs.w,&configs.h,&configs.maxGen);
    //altura e largura do tabuleiro incrementados em dois para formar bordas
    configs.h+=2;
    configs.w+=2;
    fscanf(config,"start: %d ",&configs.start[0]);
    for(i=0, a=1; i<configs.start[0]; i++){
        fscanf(config,"%d,%d",&configs.start[a+1],&configs.start[a]);
        a+=2;
    }
    fscanf(config,"\n");
    
    while(!feof(config)){
        fscanf(config,"gen %d: %d ",&configs.trocas[gen][0],&configs.trocas[gen][1]);
        for(i=0, a=2; i<configs.trocas[gen][1]; i++){
            fscanf(config,"%d,%d",&configs.trocas[gen][a+1],&configs.trocas[gen][a]);
            a+=2;
        }
        fscanf(config,"\n");
        gen++;
    }
    
    fclose(config);
    
    return configs;
}

void imprimeOutput(char **argv, int* tabuleiro, int vivas, int gen, int lin, int col){
    

    int mortas=(lin-2)*(col-2)-vivas, i, j;

    printf("Geracao: %d\n"
            "N. celulas vivas: %d\n"
            "N. celulas mortas: %d\n", gen, vivas, mortas);
    

    
    for(i=1; i<lin-1; i++){
        for(j=1; j<col-1; j++){
            if(*(tabuleiro+(i*col+j))) printf("O");
            else printf("-");
        }  
        printf("\n");
    }
}

void imprimeGhost(char **argv, int *tabuleiro, int lin, int col){
    
    FILE* ghost;
    char dirGhost[1000];
    int i, j;
    
    sprintf(dirGhost, "%s/saida//ghost.txt", argv[1]);
    ghost=fopen(dirGhost, "w");
    
    for(i=1; i<lin-1; i++){
        for(j=1; j<col-1; j++){
            if(*(tabuleiro+(i*col+j))) fprintf(ghost, "O");
            else fprintf(ghost, "-");
        }  
        fprintf(ghost,"\n");
    }
    fclose(ghost);
}

void imprimeStill(char **argv, tStill *stills){
    
    FILE* still_life;
    char dirStill[1000];
    int i;
    
    sprintf(dirStill, "%s/saida//still_life.txt", argv[1]);
    still_life=fopen(dirStill, "w");
    
    for(i=0; i<5; i++){        
        fprintf(still_life, " -%s: %d\n",(stills+i)->nome, (stills+i)->qtd);
    }
    fclose(still_life);
}

void imprimeStat(char **argv, tStat *stat, int tam){
    
    FILE* stats;
    char dirStats[1000];
    int i, idMortas;
    float mediaVivos=media(stat, tam);
    idMortas=maisMortos(stat, tam);
    
    sprintf(dirStats, "%s/saida//stats.txt", argv[1]);
    stats=fopen(dirStats, "w");
    
    fprintf(stats, "A media de celulas vivas ao longo das geracoes foi %.2f.\n", mediaVivos);
    fprintf(stats, "A maior quantidade de celulas vivas foi de %d na geracao %d.\n", stat[0].vivos, stat[0].gen);
    fprintf(stats, "A maior quantidade de celulas mortas foi de %d na geracao %d.\n", stat[idMortas].mortos, stat[idMortas].gen);
    fprintf(stats, "Lista de geracoes ordenada pela quantidade de celulas vivas:\n");
    
    for(i=0; i<tam; i++){
        fprintf(stats, " - Geracao %d: %d celulas\n", stat[i].gen, stat[i].vivos);
        
    }
    
    
}