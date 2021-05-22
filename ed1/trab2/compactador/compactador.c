#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include "arvlista.h"
#include "compactador.h"
#include "bitmap.h"
#define ASCII 256
#define MEGA 8388608

struct comp{
  char* nome; //nome do arquivo fornecido pelo usuario
  char* tipo; //extensao do arquivo
  FILE* arquivo;  //arquivo para leitura
  int vet[ASCII]; //vetor para guardar frequencias
  Arv* huffman; //arvore de huffman para compactacao
  unsigned char tab[ASCII+1][ASCII];  //tabela com caracteres e seus respectivos codigos
};

static char* Nome(char* a){
  char* s=strdup(a);

  for(int i=0; i<=strlen(s); i++){//copia o nome ate chegar na extensao
    if(s[i]=='.'){
      s[i]='\0';
      return s;
    }
  }
  return NULL;
}

static char* Tipo(char* s){
  return strrchr(s, '.'); // retorna apenas a extensao do arquivo
}

Comp* criaComp(char* dir, FILE* arquivo){
  dir=basename(dir);
  char* nome=Nome(dir);
  char* tipo=Tipo(dir);

  Comp* c=(Comp*)malloc(sizeof(Comp));
  c->nome=(char*)malloc((strlen(nome)+1)*sizeof(char));
  strcpy(c->nome, nome); //atribui o nome do arquivo ao compactador
  c->tipo=(char*)malloc((strlen(tipo)+1)*sizeof(char));
  strcpy(c->tipo, tipo); //faz o mesmo com a extensao
  c->arquivo=arquivo; //o arquivo eh passado para o compactador
  for(int i=0; i<ASCII; i++){
    c->tab[i][0]='\0'; //todos os codigos sao inicializados com \0
    c->vet[i]=0;  //frequencias se iniciam com 0
  }
  c->huffman=NULL;  //arvore inicializada como nula
  c->tab[ASCII][0]='\0'; //ultima string inicializada com \0

  free(nome);

  return c;
}

void liberaComp(Comp* c){ //libera os componentes do compactador
  free(c->nome);
  free(c->tipo);
  liberaArvore(c->huffman); //libera a arvore de Huffman
  free(c);
}

Lista* converteVetLista(int vet[]){
  Lista* l=criaLista();

  for(int i=0; i<ASCII; i++){ //insere todos os caracteres que foram contabilizados
    if (vet[i]>0){            //com frequencia maior que um na lista
      Arv* a=criaArv(i, vet[i], criaArvVazia(), criaArvVazia());
      insereLista(l, a);
    }
  }
  return l;
}

Arv* Huffman(Lista* l){

  while(tamLista(l)>1){ //enquanto houver mais de um componente na lista
    Arv* e=retiraListaPrim(l); //retira-se os dois primeiros componentes
    Arv* d=retiraListaPrim(l);

    int f=retornaFreqArv(e) + retornaFreqArv(d); //soma-se suas frequencias

    Arv* a=criaArv(0, f, e, d); //cria uma nova arvore com a soma das frequencias
                                //tendo como filhas as duas arvores retiradas
    insereLista(l, a);          //a insere na lista
    ordenaLista(l);             //ordena a lista
  }
  return retiraListaPrim(l); //retorna a unica arvore da lista
}

void compacta(Comp* c, char* dir){
  printf("Compactando...\n");

  while(1){
    unsigned char i;
    fread(&i, sizeof(unsigned char), 1, c->arquivo); //le um caracter do arquivo
    if(feof(c->arquivo))break;  //ate que chegue no final
    c->vet[i]++;  //incrementa um para a frequencia do caracter lido
  }
  fclose(c->arquivo);
  c->arquivo=(fopen(dir, "rb"));  //reabre o arquivo para rele-lo

  Lista* temp=converteVetLista(c->vet); //monta a lista com as frequencias e caracteres
  ordenaLista(temp); //ordena a lista

  c->huffman=Huffman(temp); //cria a arvore de Huffman
  liberaLista(temp);  //libera a lista

  percorreArvHuffman(c->huffman, c->tab); //codifica os caracteres da arvore inserindo-os na tabela
  geraArquivoComp(c); //gera o arquivo compactado
}

void geraArquivoComp(Comp* c){
  printf("Gerando arquivo comprimido...\n");

  char nome[strlen(c->nome)+10];
  char ponto='.';

  sprintf(nome, "%s.comp", c->nome);

  FILE* saida=fopen(nome, "wb"); //escreve o nome do arquivo no compactador
  fwrite(c->nome, sizeof(char), strlen(c->nome), saida);  //para a leitura do
  fwrite(c->tipo, sizeof(char), strlen(c->tipo), saida);  //descompactador
  fwrite(&ponto, sizeof(char), 1, saida);

  imprimeHuffman(c->huffman, saida);  //imprime os caracteres com seus respectivos codigos

  int ignorar=calculaIgnorar(c->huffman, c->tab); //calculando a quantidade de bits a serem lidos no ultimo byte
  ignorar=ignorar%8;
  fwrite(&ignorar, sizeof(int), 1, saida);

  imprimeCodificado(c, saida); //imprime o arquivo fornecido pelo usuario ja codificado
  fclose(saida);               //pela arvore de Huffman
  fclose(c->arquivo);
}

void imprimeCodificado(Comp* c, FILE* saida){

  bitmap bm=bitmapInit(MEGA);

  while(1){
    unsigned char temp;
    fread(&temp, sizeof(unsigned char), 1, c->arquivo); //le um caracter
    char* codigo=c->tab[temp]; //pega o codigo do caracter na tabela
    if(feof(c->arquivo)) break; //enquanto nao chegar no final do arquivo
    for(int i=0; i<strlen(codigo); i++){
      checaBitmap(&bm, saida);  //caso esteja cheio, eh impresso no arquivo
      bitmapAppendLeastSignificantBit(&bm, codigo[i]);  //acrescenta o codigo do caracter no bitmap
    }
  }
  salvaArquivo(bm, saida);  //imprime o ultimo bitmap
}

void imprimeNome(Comp* c){
  printf("%s\n", c->nome);  //imprime campo nome do compactador
}

void imprimeTipo(Comp* c){
  printf("%s\n", c->tipo);  //imprime extensao do compactador
}

void imprimeTab(Comp* c){
  for(int i=0; i<ASCII; i++) if(strlen(c->tab[i])) printf("%c = %s\n", i, c->tab[i]);
} //imprime a tabela de codigos e seus caracteres

void imprimeComp(Comp* c){ //todas as impressoes do compactador que serao chaves no descompactador
  printf("Lista: ");
  imprimeArv(c->huffman); //arvore

  printf("Nome: ");
  imprimeNome(c); //nome

  printf("Tipo: ");
  imprimeTipo(c); //extensao

  printf("Tabela de conversao:\n");
  imprimeTab(c); //tabela
}
