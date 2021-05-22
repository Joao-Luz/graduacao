#include "Anal.hpp"
#include <exception>

Anal::Anal(string titulo, string natureza, string idioma, string cidade, int qtd_pags, string evento): Producao(titulo, natureza, idioma, cidade, qtd_pags, 8){
    this->evento = evento;
}

Anal::~Anal(){
}

/* Metodo que retorna a string que contem as informacoes de uma producao em formato csv. No caso, reorna uma string no seguinte formato:
 "<Natuzrea>;<Titulo>;<Idioma>;<Evento>;<Cidade>;<Paginas>"*/
string Anal::csv(){
    stringstream stream;
    stream << natureza << ";" << titulo << ";" << idioma << ";" << evento << ";" << cidade << ";" << _int_string(qtd_pags);
    return stream.str();
}
/* Metodo que retorna a string cabecalho. */
string Anal::cabecalho(){
    return "Natureza;Titulo;Idioma;Evento;Cidade;Paginas";
}

/* Operador de comparacao de uma producao com outra de mesmo subtipo. */
bool Anal::operator < (Producao& o){
    Anal& prod = (Anal&)o;
    int cmp = natureza.compare(prod.natureza);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = titulo.compare(prod.titulo);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = idioma.compare(prod.idioma);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = evento.compare(prod.evento);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = cidade.compare(prod.cidade);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = qtd_pags - prod.qtd_pags;
    if(cmp<0) return true; else return false;
}
