#ifndef TTABULEIRO_H
#define TTABULEIRO_H
#include "tArquivos.h"

//estrutura do tabbuleiro de jogo. Nela esta contida as informacoes do tabuleiro, alem dos ponteiros para os espacos alocados para os diferentes subtabuleiros (novo, atual e ghost)
typedef struct{
   
    int h;
    int w;
    int *pAtual;
    int *pNovo;
    int *pGhost;
    int maxGen;
    int gen;
    int vivas;
       
}tTabuleiro;

//passa as devidas informacoes para o tipo tTabuleiro
void iniciaTab(tTabuleiro *tabuleiro, tConfig *config, int *atual, int *novo, int *ghost);

//funcao que troca o estado de uma celula. Utilizado de apoio para a troca de celulas especificadas no arquivo config
void trocaCel(int *tabuleiro, int x, int y, int col);

//funcao de apoio para depuracao
void imprimeTabuleiro(int *tabuleiro, int col, int lin);

//conta a quantidade de celulas vivas no tabuleiro em uma certa geracao
int contaVivas(tTabuleiro *tabuleiro);

#endif /* TTABULEIRO_H */

