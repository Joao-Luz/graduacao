#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include "compactador.h"



int main(int argc, char* argv[]){

  if(argc<=1){
    printf("Por favor, indique o arquivo a ser compactado!\n");
    exit(0);
  }

  FILE* f=fopen(argv[1], "rb");

  if(f==NULL){
    printf("Arquivo \"%s\" nao existe!\n", argv[1]);
  }

  Comp* c=criaComp(argv[1], f);
  compacta(c, argv[1]);
  printf("OK!\n");

  liberaComp(c);
}
