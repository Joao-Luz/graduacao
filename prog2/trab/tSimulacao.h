#ifndef TSIMULACAO_H
#define TSIMULACAO_H


//chama funcoes para que ocorra a simulacao de um ciclo do jogo
void simulaJogo(tTabuleiro *tabuleiro, tConfig *config);

//le as trocas especificadas pelo arquivo config e aplica no tabuleiro em dada geracao
void leTrocas(tTabuleiro *tabuleiro, tConfig *config);

//checa os vizinhos de uma celula para que possa ocorrer a simulacao
int contaVizinhos(int *tabuleiro, int x, int y, int col);

//aplica as regras do jogo e realiza um ciclo da simulacao
void trocaGen(tTabuleiro *tabuleiro);

//troca valores ponteiro de ponteiro para inteiro. Funcao de apoio para que ocorra a troca dos valores do tabuleiro atual
void swap(int** a, int** b);

//atribui valores nas devidas posicoes to tabuleiro ghost
void geraGhost(tTabuleiro *tabuleiro);

#endif /* TSIMULACAO_H */

