#ifndef TSTAT_H
#define TSTAT_H

//estrutura auxiliar que armazena infformacoes de forma mais simples para geracao do arquivo de estatisticas
typedef struct{
    
    int gen;
    int vivos;
    int mortos;
    
}tStat;

//funcao auxiliar para a ordenacao emm ordem decrescente de geracoes com respeito a quantidade de celulas vivas nela
int maiorVivos(tStat vetStat[], int tam, int start);

//funcao que ordena um vetor de tStat em ordem decrescente de celulas vivas em cada geracao, porem respeitando a ordem crescente de geracao
void ordenaStat(tStat vetStat[], int tam);

//funcao que retorna o indice da posicao do vetor de tStat que possui a geracao com menor numero e maior quantidade de celulcas mortas
int maisMortos(tStat vetStat[], int tam);

//funcao que calcula a media de celulas vivas por geracao de um jogo
float media(tStat vetStat[], int qtd);

#endif /* TSTAT_H */

