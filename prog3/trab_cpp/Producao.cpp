#include "Producao.hpp"

/* Construtor da classe puramente virtual Producao. */
Producao::Producao(string titulo, string natureza, string idioma, string cidade, int qtd_pags, int subtipo){
    this->titulo = titulo;
    this->natureza = natureza;
    this->idioma = idioma;
    this->cidade = cidade;
    this->qtd_pags = qtd_pags;
    this->subtipo = subtipo;
}

Producao::~Producao(){}

int Producao::getSubtipo(){
    return subtipo;
}

int Producao::getQtdPags(){
    return qtd_pags;
}

/* Metodo que transforma um inteiro em uma string. Caso o inteiro seja nulo, retorna uma string vazia. */
string Producao::_int_string(int num){
    stringstream s;
    if(num > 0) s << num; 
    return s.str();
}

//Sobrescrita do operador << para uma producao qualquer. Depende da implementacao da subclasse do metodo csv()
ostream& operator << (ostream& out, Producao& prod){
    out << prod.csv();
    return out;
}

//Sobrescrita do operador == para uma producao qualquer. Depende da implementacao da subclasse do metodo csv()
bool Producao::operator == (Producao& prod){
    return this->csv() == prod.csv();
}