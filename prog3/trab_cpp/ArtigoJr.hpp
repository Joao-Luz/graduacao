#ifndef ARTIGOJR_HPP
#define ARTIGOJR_HPP
#include "Producao.hpp"
#include "DateUtils.h"

using namespace cpp_util;

class ArtigoJr: public Producao{
private:
    time_t data;
    string issn;
public:
    ArtigoJr(string, string, string, int, string, string);
    ~ArtigoJr();

    virtual string cabecalho();
    virtual bool operator < (Producao&);
    virtual string csv();
};

#endif