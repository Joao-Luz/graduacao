#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvlista.h"
#define MEGA 8388608

typedef struct cel Cel; //struct celula que configura a lista

struct cel{
  Cel* prox;
  Arv* info; //a arvore compoe a celula da lista
};

struct lista{
  Cel* prim;
  Cel* ult;
};

struct arv{
  unsigned char c;  //caracter lido da entrada fornecida pelo usuario
  int f;  //frequencia do caracter
  Arv* e;
  Arv* d;
};

Lista* criaLista(){
  Lista* l=(Lista*)malloc(sizeof(Lista)); //aloca dinamicamente
  l->prim=NULL; //ponteiros para NULL
  l->ult=NULL;

  return l;
}

void insereLista(Lista* l, Arv* a){
  Cel* cel=(Cel*)malloc(sizeof(Cel));
  cel->prox=NULL;

  if(l->prim==NULL) l->prim=l->ult=cel; //  caso a lista esteja vazia, insere como primeiro componente
  else{
    cel->prox=l->prim;  //caso contrario, insere no inicio normalmente
    l->prim=cel;
  }
  cel->info=a;
}

void ordenaLista(Lista* l){
  Cel* i; //percorre a lista para ordena-la
  for(i=l->prim; i!=NULL; i=i->prox){
    Cel* j;
    for(j=i; j!=NULL; j=j->prox){
      if(j->info->f<i->info->f){ //caso uma celula a frente tenha frequencia maior que
        Arv* aux=i->info;       // uma de tras, trocam de posicao
        i->info=j->info;
        j->info=aux;
      }
    }
  }
}

void liberaLista(Lista* l){
  Cel* t=l->prim;
  Cel* prox;

  while(t!=NULL){ //percorre a lista, liberando todos os componentes
    prox=t->prox;
    liberaArvore(t->info);  //libera os conteudos da arvore e a arvore
    free(t);  //libera a celula
    t=prox;
  }
  free(l);  //libera a lista
}

void imprimeLista(Lista* l){ // funcao auxiliar
  Cel* t;

  for(t=l->prim; t!=NULL; t=t->prox){ //percorre a lista e imprime informacoes das arvores
    printf("%c - %d bytes\n", t->info->c, t->info->f);
  }
}

void insereOrdenado(Lista* l, Arv* a){  //ja insere na lista de forma ordenada
  Cel* t;
  Cel* ant=NULL;
  Cel* cel=(Cel*)malloc(sizeof(Cel));


  for(t=l->prim; t!=NULL; t=t->prox){ //percorre a lista por completo
    int freq;
    if(t->prox!=NULL) freq=t->prox->info->f; //pega a frequencia da proxima celula
    if(freq>a->f || t->prox==NULL){ //caso esta seja maior ou a proxima seja nula
      if(ant==NULL){  //se for o primeiro elemento da lista
        cel->prox=t->prox;  //insere a celula
        l->prim=cel;
      }
      else{ //caso contrario
        cel->prox=t->prox;  //insere a celula
        ant->prox=t;
        t->prox=cel;
      }
    }
    ant=t;
  }
}

Arv* retiraListaPrim(Lista* l){
  Cel* aux=l->prim;
  Arv* temp=aux->info;

  if(l->ult==l->prim) l->ult=NULL;; //caso a lista so tenha um componente

  l->prim=aux->prox;  //retira do inicio

  free(aux);  //libera a celula

  return temp; //retorna a arvore da celula retirada
}

Arv* criaArvVazia(){
  return NULL;
}

Arv* criaArv(unsigned char c, int f, Arv* e, Arv* d){
  Arv* a=(Arv*)malloc(sizeof(Arv));
  a->c=c; //acrescenta todos os parametros a arvore
  a->f=f;
  a->e=e;
  a->d=d;

  return a;
}

int retornaFreqArv(Arv* a){
  if(a==NULL) return 0; //arvore nula retorna 0
  return a->f;  //caso contrario, retorna sua frequencia
}

Arv* liberaArvore(Arv* a){
  if(a!=NULL){  //verificacao de arvore nula
    liberaArvore(a->e); //libera as da esquerda
    liberaArvore(a->d); //libera as da direita
    free(a);  //libera a arvore
  }
  return NULL;
}

void imprimeArv(Arv* a){
  if(a!=NULL){
    printf("(");
    printf("%d - %d", a->c, a->f); //imprime caracter e frequencia
    imprimeArv(a->e); //imprime as arvores da esquerda
    imprimeArv(a->d); //imprime as arvores da direita
    printf(")");
  }
}

int tamLista(Lista* l){
  Cel* t;
  int qtd=0;

  for(t=l->prim; t!=NULL; t=t->prox) qtd++; //percorre a lista e incrementa
                                            //a variavel de tamanho
  return qtd;
}

int folha(Arv* a){
  return (a->e==NULL && a->d == NULL);  //retorna verdadeiro caso seja folha, falso caso contrario
}

void percorreArvHuffman(Arv* a, unsigned char vet[][256]){
  unsigned char* codigo=(vet[256]);
  char* temp=(char*) codigo;
  int i=strlen(temp);

  if(folha(a)){ //verificacao de folha
    strcpy(vet[a->c], codigo);  //caso seja, insere o codigo do caracter na tabela
    return;
  }
  codigo[i+1]='\0'; //fecha a string
  codigo[i]='0';  //adiciona '0' na string
  percorreArvHuffman(a->e, vet);  //recursao para filhos a esquerda
  codigo[i+1]='\0'; //fecha a string
  codigo[i]='1';  //acidiona '1' na string
  percorreArvHuffman(a->d, vet);  //recursao para filhos a direita

  return;
}

void checaBitmap(bitmap* bm, FILE* saida){

  if(bitmapGetLength(*bm)==bitmapGetMaxSize(*bm)){  //caso tenha atingido seu tamanho maximo
    salvaArquivo(*bm, saida); //imprime o codigo na saida para descompactar
    *bm=bitmapInit(MEGA); //reinicia o bitmap
  }
}

void salvaArquivo(bitmap bm, FILE* saida){
  long int a = bitmapGetLength(bm);
  if(a%8){
    a=a%8;
    for(int i=0; i<(8-a); i++){ //completa o bitmap com '0' ate fechar um byte
      bitmapAppendLeastSignificantBit(&bm, '0');
    }
  }
  a = bitmapGetLength(bm);
  fwrite(bitmapGetContents(bm), sizeof(unsigned char), bitmapGetLength(bm)/8, saida);
  free(bitmapGetContents(bm)); //escreve o conteudo do bitmap completo no arquivo
}

void imprimeHuffman(Arv* a, FILE* saida){
  char um='1';
  char zero='0';

  if(folha(a)){
    fwrite(&um, sizeof(char), 1, saida);  //imprime '1' no arquivo de saida
    fwrite(&(a->c), sizeof(char), 1, saida); //imprime o char da arvore
  }
  else{
    fwrite(&zero, sizeof(char), 1, saida);  //imprime '0' no arquivo de saida
    imprimeHuffman(a->e, saida); //entra na arvore da esquerda e da direita
    imprimeHuffman(a->d, saida);
  }
}

int calculaIgnorar(Arv* a, unsigned char vet[][256]){
  if(folha(a)){  //percorrendo a arvore a, se o no analisado for folha, eh retornado a frequencia do no multiplicado
    return (((a->f)*strlen(vet[a->c]))%8);  //pela quantidade de bits que o representam na codificacao de huffman
  }
  return calculaIgnorar(a->e, vet) + calculaIgnorar(a->d, vet);  //caso contrario, a funcao eh chamada recursivamente como soma
}
