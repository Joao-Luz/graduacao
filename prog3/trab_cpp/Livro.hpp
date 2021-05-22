#ifndef LIVRO_HPP
#define LIVRO_HPP
#include "Producao.hpp"

class Livro: public Producao{
private:
    string editora;
    string isbn;
public:
    Livro(string, string, string, string, int, string, string);
    ~Livro();

    virtual string cabecalho();
    virtual bool operator < (Producao&);
    virtual string csv();
};

#endif