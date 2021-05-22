#include "Traducao.hpp"

Traducao::Traducao(string titulo, string natureza, string idioma, string cidade, int qtd_pags, string editora, string idioma_traducao): Producao(titulo, natureza, idioma, cidade, qtd_pags, 21){
    this->editora = editora;
    this->idioma_traducao = idioma_traducao;
}

Traducao::~Traducao(){}

/* Metodo que retorna a string que contem as informacoes de uma producao em formato csv. No caso, reorna uma string no seguinte formato:
 "<Natureza>;<Titulo>;<Idioma>;<Editora>;<Cidade>;<Traducao>;<Paginas>"*/
string Traducao::csv(){
    stringstream stream;
    stream << natureza << ";" << titulo << ";" << idioma << ";" << editora << ";" << cidade << ";" << idioma_traducao << ";" << _int_string(qtd_pags);
    return stream.str();
}

/* Metodo que retorna a string cabecalho. */
string Traducao::cabecalho(){
    return "Natureza;Titulo;Idioma;Editora;Cidade;Traducao;Paginas";
}

/* Operador de comparacao de uma producao com outra de mesmo subtipo. */
bool Traducao::operator < (Producao& o){
    Traducao& prod = (Traducao&)o;
    int cmp = natureza.compare(prod.natureza);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = titulo.compare(prod.titulo);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = idioma.compare(prod.idioma);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = editora.compare(prod.editora);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = cidade.compare(prod.cidade);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = idioma_traducao.compare(prod.idioma_traducao);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = qtd_pags - prod.qtd_pags;
    if(cmp<0) return true; else return false;
}