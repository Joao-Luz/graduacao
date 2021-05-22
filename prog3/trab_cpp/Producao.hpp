#ifndef PRODUCAO_HPP
#define PRODUCAO_HPP
#include <string>
#include <iostream>
#include <sstream>
#include "StringUtils.h"


//o
using namespace std;
using namespace cpp_util;

class Producao{
protected:
    string titulo;
    string natureza;
    string idioma;
    string cidade;
    int qtd_pags;
    int subtipo;
    string _int_string(int);
public:
    Producao(string, string, string, string, int, int);
    Producao() = default;
    virtual ~Producao();
    /* Operador de comparacao de producoes. Puramente virtual, deve ser implementado pelas subclasses. */
    virtual bool operator < (Producao&) = 0;
    /* Metodo que retorna a string de cabecalho do arquivo csv de cada subtipo. Puramente virtual, deve ser implementado pelas subclasses. */
    virtual string cabecalho() = 0;
    /* Metodo que imprime as informacoes da producao em formato csv. Puramente virtual, deve ser implementado pelas subclasses. */
    virtual string csv() = 0;
    bool operator == (Producao&);

    friend ostream& operator << (ostream&, Producao&);

    int getSubtipo();
    int getQtdPags();
};


#endif