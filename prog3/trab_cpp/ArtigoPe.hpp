#ifndef ARTIGOPE_HPP
#define ARTIGOPE_HPP
#include "Producao.hpp"

class ArtigoPe: public Producao{
private:
    string editora;
    string issn;
    int volume, fasciculo, serie;
public:
    ArtigoPe(string, string, string, int, string, int, int, int, string);
    ~ArtigoPe();

    virtual string cabecalho();
    virtual bool operator < (Producao&);
    virtual string csv();
};

#endif