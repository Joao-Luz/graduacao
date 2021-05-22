#include "Relatorio.hpp"


namespace rel{
    
    /* Construtor da classe rel_exception, a excessao padrao do namespace rel */
    rel_exception::rel_exception(string msg){
        this->msg = msg;
    }

    const char* rel_exception::what() const throw(){
        return msg.c_str();
    }

    /* Excessao de comando desconhecido */
    comando_desconhecido_exception::comando_desconhecido_exception():rel_exception("Comando desconhecido."){}

    /* Excessao de ppg nao encontrado */
    ppg_nao_encontrado_exception::ppg_nao_encontrado_exception():rel_exception("PPG nao encontrado."){}

    /* Excessao de ies nao encontrada */
    ies_nao_encontrada_exception::ies_nao_encontrada_exception():rel_exception("IES nao encontrada."){}

    Relatorio::Relatorio(){
        leitor = NULL;
        qtd_pags = 0;
        qtd_ppgs = 0;
        qtd_prod_val = 0;
        qtd_prod = 0;
        media_pags = 0;
    }

    Relatorio::~Relatorio(){
        if(leitor != nullptr) delete leitor;

        for(auto iter : instituicoes) delete iter.second;
        for(auto iter : programas) delete iter.second;

        instituicoes.clear();
        programas.clear();

    }

    /* Funcao que atualiza o relatorio lendo mais uma linha do arquivo atual.
    Le as informacoes da instituicao, programa de graduacao e producao referentes a cada linha do arquivo csv.*/
    void Relatorio::update(){

        //lendo as informacoes e criando/obtendo a instituicao a ser manipulada, bem como a producao e programa de graduacao da vez
        IES* ies = addInstituicao(leitor->getColuna(3), leitor->getColuna(2));
        PPG* ppg = addPrograma(leitor->getColuna(1), leitor->getColuna(0));
        Producao* producao = addProducao(stoi(leitor->getColuna(7)));

        //inserindo a instituicao, programa de graduacao e producao nas estruturas internas de cada classe
        ies->addPrograma(ppg);
        ppg->addInstituicao(ies);
        if(producao != nullptr) ppg->addProducao(producao);

        //passando para a proxima linha do arquivo csv
        leitor->next();
    }

    /* Metodo que troca o arquivo analisado pelo relatorio.
    Checa se ja existe um arquivo alocado na estrutura da classe e libera a memoria de acordo. */
    void Relatorio::trocaArquivo(string arquivo){
        //checando se ja existe um leitor de arquivos csv alocado dentro do relatorio e desalocando a memoria de acordo
        if(leitor != nullptr) delete leitor;

        //criando novo leitor de aquivo csv a partir do nome de arquivo passado como parametro
        ifstream* in = new ifstream(arquivo);
        leitor = new LeitorCSV(in);

        //caso o arquivo seja invalido, lanca erro de I/O
        if(in->fail()){
            throw ("Erro de I/O");
        }

    }

    double Relatorio::getMedia_pags(){
        return media_pags;
    }

    int Relatorio::getQtd_pags(){
        return qtd_pags;
    }

    int Relatorio::getQtd_instituicoes(){
        return instituicoes.size();
    }

    int Relatorio::getQtd_programas(){
        return programas.size();
    }

    int Relatorio::getQtd_prod(){
        return qtd_prod;
    }

    /* funcao auxiliar para transformar strings em inteiros */
    long _parsePositiveLong(string s) {
        try {
            if (cpp_util::isNumber(s)) return stol(s);
            else return -1;
        }
        catch (exception& e) {
            return -1;
        }
    }

    /* Metodo privativo para validar um valor numerico de acordo com as regras propostas. */
    int Relatorio::_checa_pag(string s){
        int pags = _parsePositiveLong(s);
         return pags;
    } 

    /* Metodo que valida as paginas de uma producao de acordo com as regras propostas */
    int Relatorio::_checa_pags(string pi, string pf){
        int inicial = _parsePositiveLong(pi);
        int final  = _parsePositiveLong(pf);

        if (inicial != -1 && final != -1) {
			long tamanho = final - inicial + 1;
			if (tamanho > 0 && tamanho < 2000) return tamanho;
            else return 0;
		}
        else return 0;
    }

    /* Metodo que adiciona uma instituicao ao mapa nao ordenado de instituicoes de um relatorio.
    Retorna uma nova instituicao se a mesma nao se encontrar no mapa, ou a correspondente se a mesma existir no mapa. */
    IES* Relatorio::addInstituicao(string nome, string sigla){

        //checando se a instituicao ja existe
        unordered_map<string, IES*>::iterator iter = instituicoes.find(nome+sigla);
        if(iter != instituicoes.end()) return iter->second;
        else{
            //gerando uma nova instituicao caso ela nao exista no mapa
            IES* ies = new IES(nome, sigla);
            instituicoes.insert({nome+sigla, ies});
            return ies;
        }
    }

    /* Metodo que adiciona um programa de graducao ao mapa nao ordenado de instituicoes de um relatorio.
    Retorna um novo programa se a mesma nao se encontrar no mapa, ou a correspondente se o mesmo existir no mapa. */
    PPG* Relatorio::addPrograma(string nome, string codigo){

        //checando se o programa ja existe
        unordered_map<string, PPG*>::iterator iter = programas.find(codigo);
        if(iter != programas.end()) return iter->second;
        else{
            //gerando um novo programa caso ele nao exista no mapa
            PPG* ppg = new PPG(nome, codigo);
            programas.insert({codigo, ppg});
            return ppg;
        }
    }

    /* Metodo que cria uma nova producao de acordo com a informacao do arquivo csv sendo lido.
    Retorna uma nova producao do subtipo passado como parametro.
    Retorna 'nullptr' caso o subtipo passado nao exista. */
    Producao* Relatorio::addProducao(int subtipo){
        Producao* producao = nullptr;
        if(subtipo ==  8) producao = new Anal(leitor->getColuna(9), leitor->getColuna(8), leitor->getColuna(18), leitor->getColuna(16), _checa_pags(leitor->getColuna(14), leitor->getColuna(13)), leitor->getColuna(15));
        if(subtipo ==  9) producao = new ArtigoJr(leitor->getColuna(8), leitor->getColuna(12), leitor->getColuna(13), _checa_pags(leitor->getColuna(11), leitor->getColuna(10)), leitor->getColuna(9), leitor->getColuna(15));
        if(subtipo == 25) producao = new ArtigoPe(leitor->getColuna(8), leitor->getColuna(14), leitor->getColuna(19), _checa_pags(leitor->getColuna(13), leitor->getColuna(12)), leitor->getColuna(18), _checa_pag(leitor->getColuna(9)), _checa_pag(leitor->getColuna(10)), _checa_pag(leitor->getColuna(11)), leitor->getColuna(21));
        if(subtipo == 26) producao = new Livro(leitor->getColuna(15), leitor->getColuna(9), leitor->getColuna(21), leitor->getColuna(11), _checa_pag(leitor->getColuna(38)), leitor->getColuna(10), leitor->getColuna(12));
        if(subtipo == 28) producao = new Partitura(leitor->getColuna(8), leitor->getColuna(11), _checa_pag(leitor->getColuna(13)), leitor->getColuna(10), leitor->getColuna(9));
        if(subtipo == 21) producao = new Traducao(leitor->getColuna(10), leitor->getColuna(8), leitor->getColuna(11), leitor->getColuna(14), _checa_pag(leitor->getColuna(17)), leitor->getColuna(13), leitor->getColuna(12));
        if(subtipo == 10) producao = new Outro(leitor->getColuna(8), leitor->getColuna(12), leitor->getColuna(10), _checa_pag(leitor->getColuna(13)), leitor->getColuna(9));
        return producao;
    }

    /* Metodo que retorna se o arquivo sendo lido pelo relatorio chegou ao fim ou nao. */
    bool Relatorio::acabou(){
        return leitor->acabou();
    }
    
    // Funcao auxiliar para a ordenacao dde PPGs
    bool _ordena_ppg_Codigo(PPG* ppg1, PPG* ppg2){
        return cpp_util::stringCompare(ppg1->getCodigo(), ppg2->getCodigo());
    }

    /* Metodo que executa o comando "rede".
    Imprime as informacoes dos programas de graducao em rede. */
    void Relatorio::imprimeRede(){
        cout << "Programas em rede:" << endl;

        //criando um vector auxiliar para ser ordenado e impresso
        vector<PPG*> temp;
        for(auto iter : programas){
            if(iter.second->ehRede()) temp.push_back(iter.second);
        }

        //ordenando o vector temporario
        sort(temp.begin(), temp.end(), _ordena_ppg_Codigo);

        //imprimindo as informacoes de cada membro do vector
        for(auto iter : temp){
            cout << *iter << endl;
            iter->imprimeRede();
        }
    }

    /* Metodo que executa o comando "ppg".
    Imprime as informacoes de um PPG com codigo passado como parametro.
    Caso o PPG nao exista, lanca "PPG nao encontrado". */
    void Relatorio::imprimePpg(string codigo){
        if(programas.find(codigo) == programas.end()){
            throw ppg_nao_encontrado_exception();
        }
        PPG* ppg = programas.find(codigo)->second;
        cout << "Programa: " << ppg->getNome() << endl;
        ppg->imprimeInfo();
    }

    //funcao auxiliar para a ordenacao de instituicoes
    bool _ordena_ies_Nome(IES* ies1, IES* ies2){
        return *ies1 < *ies2;
    }

    /* Metodo que executa o comando "ies".
    Imprime as informacoes das instituicoes que possuem a sigla passada como parametro, caso existam. */
    void Relatorio::imprimeIes(string sigla){
        vector<IES*> temp;
        for(auto iter : instituicoes) if(iter.second->getSigla() == sigla) temp.push_back(iter.second);
        if(temp.size() == 0){
            throw ies_nao_encontrada_exception();
        }
        sort(temp.begin(), temp.end(), _ordena_ies_Nome);

        for(auto iter : temp){
            cout << iter->getNome() << " (" << sigla << "):" << endl;
            iter->imprimeInfo();
        }
    }

    /* Metodo que executa o comando "csv".
    Ele imprime um arquivo em formato csv referente ao tipo de producao passado como parametro do PPG com codigo passado como parametro, caso existam. */
    void Relatorio::imprimeCsv(string codigo, string subtipo){
        if(programas.find(codigo) == programas.end()){
            throw ppg_nao_encontrado_exception();
        }
        PPG* ppg = programas.find(codigo)->second;
        ppg->imprimeCsv(subtipo);
    }

    /* Metodo que chama os metodos de execucao de comando. Caso o comando nao exista, lanca "Comando desconhecido." */
    void Relatorio::executaComando(string comando){
        if(comando == "rede") imprimeRede();
        else if(comando == "ppg"){
            string ppg;
            cin >> ppg;
            imprimePpg(ppg);
        }
        else if(comando == "ies"){
            string sigla;
            cin >> sigla;
            imprimeIes(sigla);
        }
        else if(comando == "csv"){
            string codigo, subtipo;
            cin >> codigo >> subtipo;
            imprimeCsv(codigo, subtipo);
        }
        else throw comando_desconhecido_exception();
    }

}