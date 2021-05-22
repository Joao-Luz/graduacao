#ifndef TSTILL_LIFES_H
#define TSTILL_LIFES_H

//estrutura que armazena informacoes para uma still life qualquer
//contempla informacoes especificas que serao utilizadas para que haja funcionamento do programa, como seu formato
typedef struct{
    
    int qtd;
    char *nome;
    int lin;
    int col;
    int *formato;
    
}tStill;

//chama a funcao que inicializa as sill lifes que serao procuradas no jogo, alem de chamar as funcoes que procuram cada still life especifica
void procuraStills(int *tabuleiro, int lin, int col, tStill *vetStill);

//inicia as cinco still lifes usadas no trabalho, atribuido formatos, dimensoes e nomes
void iniciaStills(tStill *block, tStill *beehive, tStill *loaf, tStill *boat, tStill *tub);

//verifica o tabuleiro para certa still life. Note que deve ser chamada para cada still liffe que se deseja procurar
void verificaStill(int *tabuleiro, int x, int y, tStill* vetStill);

//realiza a comparacao de um pedaco do tabuleiro de dimensoes iguais a da still que se deseja analisar e o formato da still life analisada, retorna 1 se for igual e 0 se nao for
int comparaStill(int *tabuleiro, int col, int x, int y, tStill *still);

//funcao que ordena um vetor de still lifes para colocar na ordem decrescente de aparicoes porem respeitando a ordem alfabetica
void ordenaStill(tStill *pvetStill);

//funcao auxiliar para que possa ser ordenado o vetor de still lifes
int achaMaior(tStill pvetStill[], int start);


#endif /* TSTILL_LIFES_H */

