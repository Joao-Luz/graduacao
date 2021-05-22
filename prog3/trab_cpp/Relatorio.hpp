#ifndef RELATORIO_H
#define RELATORIO_H
#include <exception>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "IES.hpp"
#include "PPG.hpp"
#include "LeitorCSV.hpp"
#include "StringUtils.h"
#include "Producao.hpp"
#include "Anal.hpp"
#include "ArtigoJr.hpp"
#include "ArtigoPe.hpp"
#include "Livro.hpp"
#include "Outro.hpp"
#include "Partitura.hpp"
#include "Traducao.hpp"

using namespace std;

namespace rel{

    class rel_exception: public exception{
        protected:
            string msg;
        public:
            rel_exception(string);
            const char* what() const throw();
    };

    class comando_desconhecido_exception: public rel_exception{
        public:
            comando_desconhecido_exception();
    };

    class ppg_nao_encontrado_exception: public rel_exception{
        public:
            ppg_nao_encontrado_exception();
    };

    class ies_nao_encontrada_exception: public rel_exception{
        public:
            ies_nao_encontrada_exception();
    };



    class Relatorio{
    private:
        unordered_map<string, IES*> instituicoes;
        unordered_map<string, PPG*> programas;
        LeitorCSV* leitor;
        int qtd_pags;
        int qtd_ppgs;
        int qtd_iess;
        int qtd_prod;
        int qtd_prod_val;
        double media_pags;
        int _checa_pags(string, string);
        int _checa_pag(string);
        void imprimeRede();
        void imprimePpg(string);
        void imprimeIes(string);
        void imprimeCsv(string, string);
    public:
        Relatorio();
        ~Relatorio();
        void update();
        IES* addInstituicao(string, string);
        PPG* addPrograma(string, string);
        Producao* addProducao(int);
        bool acabou();
        void trocaArquivo(string);
        void executaComando(string);
        

        double getMedia_pags();
        int getQtd_pags();
        int getQtd_instituicoes();
        int getQtd_programas();
        int getQtd_prod();
    };
}

#endif