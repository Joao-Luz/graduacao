#include "Livro.hpp"

Livro::Livro(string titulo, string natureza, string idioma, string cidade, int qtd_pags, string editora, string isbn): Producao(titulo, natureza, idioma, cidade, qtd_pags, 26){
    this->editora = editora;
    this->isbn = isbn;
}

Livro::~Livro(){}

/* Metodo que retorna a string que contem as informacoes de uma producao em formato csv. No caso, reorna uma string no seguinte formato:
 "<Natureza>;<Titulo>;<Idioma>;<Editora>;<Cidade>;<ISBN>;<Paginas>"*/
string Livro::csv(){
    stringstream stream;
    stream << natureza << ";" << titulo << ";" << idioma << ";" << editora << ";" << cidade << ";" << isbn << ";" << _int_string(qtd_pags);
    return stream.str();
}

/* Metodo que retorna a string cabecalho. */
string Livro::cabecalho(){
    return "Natureza;Titulo;Idioma;Editora;Cidade;ISBN;Paginas";
}

/* Operador de comparacao de uma producao com outra de mesmo subtipo. */
bool Livro::operator < (Producao& o){
    Livro& prod = (Livro&)o;
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
    cmp = isbn.compare(prod.isbn);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = qtd_pags - prod.qtd_pags;
    if(cmp<0) return true; else return false;
}