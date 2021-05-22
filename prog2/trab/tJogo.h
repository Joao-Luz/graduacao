#ifndef TJOGO_H
#define TJOGO_H

//chama as funcoes que inicializam as informacoes do tabuleiro e do jogo
void iniciaJogo(int argc, char** argv, int *atual, int *novo, int *ghost);

//roda o jogo chamando funcoes que realizam a simulacao alem de funcoes que geram as informacoes contidas nos arquivos de saida
void rodaJogo(char **argv);

#endif /* TJOGO_H */

