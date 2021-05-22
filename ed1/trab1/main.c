#include <stdio.h>
#include "netmap.h"

int main(int argc, char** argv){
  NetMap* netmap=iniciaNetMap();
  runNetMap(argc, argv, netmap);
  liberaNetMap(netmap);
}
