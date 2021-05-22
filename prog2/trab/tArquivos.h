#ifndef TARQUIVOS_H
#define TARQUIVOS_H
#include "tStill_lifes.h"
#include "tStat.h"

//estrutura que armazena as informacoes fornecidas pelo arquivo config.txt
typedef struct{
    
    int h;
    int w;
    int maxGen;
    int start[100];
    int trocas[200][100];
    
}tConfig;

//realiza a leitura do arquivo config e atribui os deevidos valores a estrutura tConfig
tConfig leArquivo(int argc, char** argv);

//imprime as informacoes devidas do arquivo output
void imprimeOutput(char **argv, int* tabuleiro, int gen, int vivas, int lin, int col);

//gera o arquivo ghost.txt e escreve nele a matriz com todas as celulcas que ficaram vivas em algum momento do jogo (que chegou a ser impresso)
void imprimeGhost(char **argv, int *tabuleiro, int lin, int col);

//gera o arquivo still_life.txt e escreve nele a quantidade que cada still life apareceu no jogo am ordem decrescente e alfabetica
void imprimeStill(char **argv, tStill *stills);

//geta o arquivo stat.txt e escreve nele a media de celulas vivas por geracao, alem da geracao com mais mortos, vivos e uma lista decrescente de quantidade de vivos e suas geracoes 
void imprimeStat(char **argv, tStat *stat, int tam);

#endif /* TARQUIVOS_H */

