#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct arvore{
  unsigned char c; //caracter lido no arquivo
  Arv* e;          //arvores filhas esquerda e direita
  Arv* d;
};

Arv* criaVazia(){
  return NULL;  //retorna null para uma arvore
}

Arv* criaArv(unsigned char c, Arv* d, Arv* e){
  Arv* a=(Arv*)malloc(sizeof(Arv));
  a->c=c; //atribui o caracter a arvore
  a->e=e; //atribui as arvores do parametro a nova arvore
  a->d=d;

  return a;
}

void liberaArv(Arv* a){
  if(a!=NULL){        //recursivamente, verifica nulidade da arvore
    liberaArv(a->e);  //libera esquerda e direita
    liberaArv(a->d);
    free(a);          //quando tiver liberado todos seus filhos, libera a arvore
  }
}

Arv* criaHuffman(FILE* arquivo){
  char c;
  fread(&c, sizeof(char), 1, arquivo);  //le um caracter do arqivo
  Arv* a;

  if(c=='0'){  //se o caracter for '0', eh criada uma nova arvore com chamada recursiva da funcao como parametros de filhos
    a=criaArv('\0', criaHuffman(arquivo), criaHuffman(arquivo));
  }
  else if(c=='1'){  //se for '1', eh criada uma nova arvore com filhos nulos e byte correspondente ao lido (no folha da arvore)
    unsigned char valor;

    fread(&valor, sizeof(unsigned char), 1, arquivo);

    a=criaArv(valor, criaVazia(), criaVazia());
  }
  return a;
}

int folha(Arv* a){
  return (a->e==NULL && a->d==NULL); //retorna verdadeiro se for folha, falso caso contrario
}

void imprimeArv(Arv* a){
  if(a!=NULL){              //verifica nulidade para a recursao
    printf("<%c", a->c);  //imprime todos os filhos antes de imprimir a propria arvore
    imprimeArv(a->e);
    imprimeArv(a->d);
    printf(">");
  }
}

void descodifica(FILE* entrada, Arv* aOrg, int ignorar, FILE* saida){
  unsigned char c;
  unsigned char prox;
  fread(&c, sizeof(unsigned char), 1, entrada);     //le um caracter
  fread(&prox, sizeof(unsigned char), 1, entrada);  //le o proximo
  int lim;
  if(feof(entrada)) lim=ignorar; //se estiver no final do arquivo (ultimo byte da mensagem compactada) o limite eh o limite
  else lim=8;                    //impresso no arquivo compactado, caso contrario eh 8, a quantidade normal de bits em um byte
  Arv* a=aOrg;

  int i;
  int teste;
  for(i=0; i<lim; i++){  //loop para a analise do byte lido bit a bit
    if((teste=(c & (1 <<(7 - i))))){  //navegando na arvore de acordo com o valor do bit analisado
      a=a->d;
    }
    else{
      a=a->e;
    }
    if(folha(a)){  //se a navegacao chega em um no folha da arvore, eh impresso o byte correspondente no arquivo de saida
      fwrite(&(a->c), sizeof(unsigned char), 1, saida);
      a=aOrg;
    }
    if(i==(lim-1)){  //caso cehgue no fim da leitura do byte
      i=-1;
      if(feof(entrada)) break;  //caso o ultimo byte lido seja o ultimo byte do arquivo
      c=prox;
      fread(&prox, sizeof(unsigned char), 1, entrada);  //caso o novo byte a ser lido seja o ultimo do arquivo
      if(feof(entrada)) lim=ignorar;
    }
  }
}
