#include "PPG.hpp"
#include <iostream>
#include "StringUtils.h"

/* Construtor da classe ppg_exception, a excessao padrao dos ppgs.*/
ppg_exception::ppg_exception(string msg){
    this->msg = msg;
}

const char* ppg_exception::what() const throw(){
    return msg.c_str();
}

/* Excessao de tipo invalido. */
tipo_invalido_exception::tipo_invalido_exception(): ppg_exception("Tipo invalido."){}

PPG::PPG(string nome, string codigo){
    this->nome = nome;
    this->codigo = codigo;
}

PPG::~PPG(){
    for(auto iter : producoes) delete iter;
}

string PPG::getCodigo(){
    return codigo;
}

string PPG::getNome(){
    return nome;
}

int PPG::getQtdProd(int subtipo){
    int counter = 0;
    for(auto iter : producoes) if(iter->getSubtipo() == subtipo) counter++;
    return counter;
}

int PPG::getQtdProd(){
    return producoes.size();
}

/* Metodo que retorna a quantidade de paginas produzido pelo PPG. */
int PPG::getQtdPags(){
    int counter = 0;
    //Soma a quantidade de paginas de cada producao associada ao PPG.
    for(auto iter : producoes) counter += iter->getQtdPags();
    return counter;
}

/* Metodo que adiciona uma IES associada ao PPG. Checa antes se a IES ja foi cadastrada ao PPG. */
void PPG::addInstituicao(IES* ies){
    string chave = ies->getSigla() + ies->getNome();
    if(instituicoes.find(chave) == instituicoes.end()) instituicoes.insert({chave, ies});
}

/* Metodo que insere uma nova producao no PPG. */
void PPG::addProducao(Producao* prod){
    producoes.push_back(prod);
}

/* Metodo que retorna se o PPG eh rede ou nao. */
bool PPG::ehRede(){
    return instituicoes.size() > 1;
}

//Funcao auxiliar para a ordenacao das instituicoes.
bool _ordena_Nome(IES* ies1, IES* ies2){
    return *ies1 < *ies2;
}

/* Metodo que imprime as informacoes da rede de instituicoes relacionado ao PPG. */
void PPG::imprimeRede(){
    //Criando um vector temporario para futura ordenacao
    vector<IES*> temp;

    //Inserindo no vector as instituicoes do PPG
    for(auto iter : instituicoes) temp.push_back(iter.second);
    sort(temp.begin(), temp.end(), _ordena_Nome);

    //Imprimindo as informacoes de cada instituicao
    for(IES* iter : temp) cout << "\t- " << *iter << endl;
}

//Funcao auxiliar que transforma o subtipo da producao em um valor numerico.
int geraCodigo(string producao){
    if(producao == "anais") return 8;
    if(producao == "artjr") return 9;
    if(producao == "artpe") return 25; 
    if(producao == "livro") return 26;
    if(producao == "partmu") return 28;
    if(producao == "tradu") return 21;
    if(producao == "outro") return 10;
    return -1;
}

//Funcao auxiliar para a ordenacao de producoes
bool _ordena_producao(Producao* p1, Producao* p2){
    return *p1 < *p2;
}

//Funcao auxiliar para a insersao de producoes no vector auxiliar para imprimir o csv
bool contem(vector<Producao*> temp, Producao* prod){
    for(auto iter : temp) if(*prod == *iter) return true;
    return false;
}

/* Metodo que gera e imprime as informacoes de uma producao referente a um PPG em formato csv.
Caso o tipo de producao que se deseja imprimir nao existe, lanca "Tipo invalido." */
void PPG::imprimeCsv(string producao){

    //checando se o subtipo da producao existe
    int subtipo = geraCodigo(producao);
    if(subtipo == -1){
        throw tipo_invalido_exception();
    }

    //criando o vector auxiliar e inserindo apenas as producoes desejadas.
    vector<Producao*> temp;
    for(auto iter : producoes) if(iter->getSubtipo() == subtipo && !contem(temp, iter)) temp.push_back(iter);
    sort(temp.begin(), temp.end(), _ordena_producao);

    //imprimindo o cabecalho da producao desejada
    cout << temp[0]->cabecalho() << endl;
    for(auto iter : temp) cout << *iter << endl;
}

/* Metodo que imprime as informacoes estatisticas do PPG da seguinte forma:
 "Instituicoes:
<instituicoes_relacionadas_ao_ppg>
Quantidade de producoes por tipo:
Artigos em anais de eventos: <qtd_prod_anal>
Artigos em jornais e revistas: <qtd_prod_artjr>
Artigos em periodicos cientificos: <qtd_prod_artpe>
Livros: <qtd_prod_livro>
Partituras musicais: <qtd_prod_partmu>
Traducoes: <qtd_prod_tradu>
Outros: <qtd_prod_outro>
Total de paginas produzidas pelo PPG: <total_pags_ppg>"*/
void PPG::imprimeInfo(){
    cout << "Instituicoes:" << endl;
    imprimeRede();
    cout << "\nQuantidade de producoes por tipo:" << endl;
    cout << "\t- Artigos em anais de eventos: " << getQtdProd(8) << endl;
    cout << "\t- Artigos em jornais e revistas: " << getQtdProd(9) << endl;
    cout << "\t- Artigos em periodicos cientificos: " << getQtdProd(25) << endl;
    cout << "\t- Livros: " << getQtdProd(26) << endl;
    cout << "\t- Partituras musicais: " << getQtdProd(28) << endl;
    cout << "\t- Traducoes: " << getQtdProd(21) << endl;
    cout << "\t- Outros: " << getQtdProd(10) << endl;
    cout << "\nTotal de paginas produzidas pelo PPG: " << getQtdPags() << endl;


}

//sobrescrita do operador << para o PPG.
ostream& operator << (ostream& out, PPG& ppg){
    out << ppg.getCodigo() << ": " << ppg.getNome();
    return out;
}