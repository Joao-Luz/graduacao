#ifndef PPG_HPP
#define PPG_HPP
#include <string>
#include <unordered_map>
#include <vector>
#include <exception>
#include "IES.hpp"
#include "Producao.hpp"

using namespace std;

class ppg_exception: public exception{
    private:
        string msg;
    public:
        ppg_exception(string);
        const char* what() const throw();
};

class tipo_invalido_exception: public ppg_exception{
    public:
        tipo_invalido_exception();
};

class IES;

class PPG{
private:    
    string nome;
    string codigo;
    unordered_map<string, IES*> instituicoes;
    vector<Producao*> producoes;

public:
    PPG(string, string);
    ~PPG();
    void addInstituicao(IES* ies);
    bool ehRede();
    void imprimeRede();
    void addProducao(Producao*);
    int getQtdProd(int);
    int getQtdProd();
    int getQtdPags();
    void imprimeInfo();
    void imprimeCsv(string);

    friend ostream& operator << (ostream&, PPG&);

    string getCodigo();
    string getNome();
};


#endif