#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "descompactador.h"
#include "arvore.h"

struct descompactador{
  Arv* huffman;       //arvore de Huffman utilizada na compactacao
  char* nome;         //nome do arquivo compactado
  char* tipo;         //extensao do arquivo compactado
  FILE* arquivo;      //arquivo a ser descompactado
  int ignorar;        //INTEIRO//////////////////
};

Descomp* criaDescomp(FILE* arquivo){
  char* nome=recuperaNome(arquivo); //recupera o nome do arquivo compactado
  char* tipo=recuperaTipo(arquivo); //recupera a extensao

  Descomp* dc=(Descomp*)malloc(sizeof(Descomp));
  dc->nome=strdup(nome);                  //atribui o nome ao descompactador
  dc->tipo=strdup(tipo);                  //a extensao
  dc->huffman=recuperaHuffman(arquivo);   //copia a arvore de Huffman utilizada na compactacao
  dc->ignorar=recuperaIgnorar(arquivo);   /////////////////////////////////////////////
  dc->arquivo=arquivo;                    //pega o arquivo a ser descompactado

  free(nome);
  free(tipo);


  return dc;
}

char* recuperaNome(FILE* arquivo){
  char nome[100];

  for(int i=0; 1; i++){ //le caracter por caracter do nome do arquivo
    fread(&nome[i], sizeof(char), 1, arquivo);
    if(nome[i]=='.'){ //quebra a iteracao quando chegar no '.' (extensao do arquivo)
      nome[i]='\0';
      char* retorno=strdup(nome);
      return retorno;
    }
  }
}

char* recuperaTipo(FILE* arquivo){
  char tipo[100];

  for(int i=0; 1; i++){ //le caracter por caracter do arquivo
    fread(&tipo[i], sizeof(char), 1, arquivo);
    if(tipo[i]=='.'){  //quando encontra o ponto, retorna tudo que vier depois
      tipo[i]='\0';
      char* retorno=strdup(tipo);
      return retorno;
    }
  }
}

Arv* recuperaHuffman(FILE* arquivo){
  Arv* a=criaHuffman(arquivo);  //pega os atributos da arvore de Huffman utilizada
                                //e retorna a arvore ja pronta
  return a;
}

int recuperaIgnorar(FILE* arquivo){
  int retorno;

  fread(&retorno, sizeof(int), 1, arquivo); /////////////////////

  return retorno;
}

void liberaDescomp(Descomp* dc){
  liberaArv(dc->huffman); //libera a arvore de Huffman da memoria
  free(dc->nome); //depois os demais atributos do descompactador
  free(dc->tipo);
  free(dc);
}

void descompacta(Descomp* dc){
  printf("Descompactando...\n");

  char nomeSaida[strlen(dc->nome)+strlen(dc->tipo)+10];
  sprintf(nomeSaida, "./%s.%s", dc->nome, dc->tipo);  //acerta o nome do arquivo que foi
                                                      //compactado
  FILE* saida=fopen(nomeSaida, "wb");
  descodifica(dc->arquivo, dc->huffman, dc->ignorar, saida);  //descodifica o arquivo
  fclose(saida);                                          //compactado, descompactando
}
