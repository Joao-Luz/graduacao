#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "NumPunctPTBR.h"
#include "NumberUtils.h"
#include "Tokenizer.h"
#include "StringUtils.h"
#include "LeitorCSV.hpp"
#include "Relatorio.hpp"

using namespace std;
using namespace cpp_util;
using namespace rel;


int main(int argc, char **argv) {

	Relatorio* rel = new Relatorio();
	string dir;
	cin >> dir;

	//lendo o nome dos 7 arquivos
	for(int i = 0; i < 7; i++){
		string arquivo;
		cin >> arquivo;

		//checando se eh possivel abrir o arquivo da vez
		try{
			rel->trocaArquivo(dir + arquivo); 
		}
		catch(const char* e){
			cout << e << endl;
			delete rel;
			return 0;
		}
		//loop para ler as informacoes do arquivo fornecido linha por linha
		while(true) {
			rel->update();
			if(rel->acabou()) break;
		}
	}
	
	//lendo o comando a ser executado
	string comando;
	cin >> comando;

	//tentando executar o comando
	try{
		rel->executaComando(comando);
	}
	catch(exception& e){
		cout << e.what() << endl;
	}

	//liberando a memoria alocada
	delete rel;
}
