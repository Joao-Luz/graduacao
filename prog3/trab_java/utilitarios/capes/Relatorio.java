package utilitarios.capes;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Map;
import java.util.HashMap;
import utilitarios.capes.producoes.*;
import utilitarios.leitura.CSV;


/**
 * Acionada quando o usuario tenta ver as informacoes de um tipo de producao nao contemplado pelo programa.
 */
class TipoInvalidoException extends Exception{
    private static final long serialVersionUID = 1L;

    TipoInvalidoException() {
        super("Tipo invalido.");
    }
}

/**
 * Acionada quando o usuario tenta acessar as informacoes de um PPG que nao existe no relatorio.
 */
class PPGNaoEncontradoException extends Exception{
    private static final long serialVersionUID = 1L;

    PPGNaoEncontradoException() {
        super("PPG nao encontrado.");
    }
}

/**
 * Acionada quando o usuario tenta acessar as informacoes de uma IES que nao existe no relatorio.
 */
class IESNaoEncontradaException extends Exception{
    private static final long serialVersionUID = 1L;

    IESNaoEncontradaException() {
        super("IES nao entrada.");
    }
}

/**
 * Acionada quando o usuario tenta executar um comando desconhecido ao relatorio.
 */
class ComandoDesconhecidoException extends Exception{
    private static final long serialVersionUID = 1L;

    ComandoDesconhecidoException(){
        super("Comando desconhecido.");
    }       
}

public class Relatorio{

    private String TITULO;
    private String NATUREZA;
    private String IDIOMA;
    private String CIDADE;
    private String EVENTO;
    private String CODIGO_PPG;
    private String NOME_PPG;
    private String SIGLA_IES;
    private String NOME_IES;
    private String PAG_INI;
    private String PAG_FIN;
    private int SUBTIPO;
    private String DATA;
    private String ISSN;
    private String ISBN;
    private String EDITORA;
    private String IDIOMA_TRADUCAO;
    private int VOLUME;
    private int FASCICULO;
    private int SERIE;
    private String FORMACAO_INSTRUMENTAL;
    private int PAGINAS;
    private int PAGINAS_COLABORACAO;
    private String CIDADE_PAIS;
    private String EDITORA_TRADUCAO;



    private CSV csv;
    private Map<String, IES> instituicoes;
    private Map<String, PPG> programas;
    private ArrayList<Producao> producoes;
    private int qtdIes = 0;
    private int qtdPpgs = 0;
    private int qtdProducoes = 0;
    private int qtdProducoesComPags = 0;
    private int qtdPags = 0;
    private double media_pags = 0;

    

    /**
     * Cria uma nova instancia da classe {@code}Relatorio{@code}.
     */
    public Relatorio(){
        this.instituicoes = new HashMap<>();
        this.programas = new HashMap<>();
        this.producoes = new ArrayList<Producao>();
    }


    /**
     * Metodo que atualiza o status do relatorio a partir de uma linha de um arquivo CSV formatado adequadamente.
     * Utiliza as informacoes do arquivo para adicionar ou atualizar os respectivos PPGs, IESs e producoes descritas na linha analizada.
     */
    public void update(){
    
        try {
            IES ies = checaInstituicao(NOME_IES, SIGLA_IES);

            PPG ppg = checaPpg(NOME_PPG, ies, CODIGO_PPG);

            Producao producao = checaProducao(SUBTIPO);
            if(producao != null){
                ppg.addProducao(producao);
                addProducao(producao);
            }
            else System.out.println(SUBTIPO);
 
            if(this.qtdProducoesComPags > 0) this.media_pags = (double)this.qtdPags / this.qtdProducoesComPags;
            
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    /**
     * Metodo que checa a validade de uma pagina. Checa se a String correspondente a suposta pagina pode ser convertida para um inteiro positivo
     * 
     * @param pag
     * @return -1 se a pagina e invalida (nao se encontra em formato de inteiro positivo)
     * @return o numero correspondente a pagina
     */
    private int checaPag(String pag){
        
        int pagConv;

        try {
            pagConv = Integer.parseInt(pag);
        } catch (Exception e) {
            pagConv = -1;
        }

        if(pagConv >= 0) return pagConv;
        return -1;
    }


    /**
     * Metodo que checa a validade da producao analizada e retorna um novo objeto do subtipo especifico da producao sendo checada.
     * Producoes que nao possuem um valor valido de paginas (valor inteiro positivo menor que 2000) possuira quantidade de paginas igual a zero.
     * 
     * @param subtipo
     * @return uma nova producao do subtipo correspondente; 'null' se o subtipo analizado nao existe.
     * @throws Exception
     */
    public Producao checaProducao(int subtipo) throws Exception {
        int pag1;
        int pag2;
        int pags = 0;

        pag2 = checaPag(PAG_FIN);
        pag1 = checaPag(PAG_INI);
        if(pag1 <= pag2 && pag1 >= 0 && pag2 >= 0){
            pags = pag2 - pag1 + 1;
            if(pags > 2000 || pags <= 0) pags = 0;
        }

        if(PAGINAS > 2000 || PAGINAS < 0) PAGINAS = 0;
        if(PAGINAS_COLABORACAO > 2000 || PAGINAS_COLABORACAO < 0) PAGINAS_COLABORACAO = 0;
        
        if(subtipo == 8) return new Anal(TITULO, NATUREZA, IDIOMA, CIDADE, pags, EVENTO);
        if(subtipo == 9) return new ArtigoJR(TITULO, IDIOMA, CIDADE, pags, DATA, ISSN);
        if(subtipo == 10) return new Outro(NATUREZA, IDIOMA, EDITORA, CIDADE, PAGINAS);
        if(subtipo == 21) return new Traducao(TITULO, NATUREZA, IDIOMA, CIDADE, PAGINAS, EDITORA_TRADUCAO, IDIOMA_TRADUCAO);
        if(subtipo == 25) return new ArtigoPE(NATUREZA, IDIOMA, CIDADE, pags, EDITORA, VOLUME, FASCICULO, SERIE, ISSN, PAG_INI, PAG_FIN);
        if(subtipo == 26) return new Livro(TITULO, NATUREZA, IDIOMA, CIDADE_PAIS, PAGINAS_COLABORACAO, EDITORA, ISBN);
        if(subtipo == 28) return new Partitura(NATUREZA, IDIOMA, CIDADE, PAGINAS, EDITORA, FORMACAO_INSTRUMENTAL);

        return null;
    }

    /**
     * Metodo que checa a validade da instituicao analizada.
     * Verifica se a mesma ja existe e, caso contrario, adiciona uma nova instituicao ao relatorio.
     * 
     * @param nome
     * @param sigla
     * @return a instituicao ja existente, caso haja ocorrencia da mesma no relatorio; uma nova instituicao, caso ela nao tenha sido criada ainda
     * 
     */
    public IES checaInstituicao(String nome, String sigla){
        if(instituicoes.containsKey(nome + sigla)) return instituicoes.get(nome + sigla);
        IES ies = new IES(nome, sigla);
        instituicoes.put(nome + sigla, ies);
        this.qtdIes++;

        return ies;
    }
    
    /**
     * Metodo que checa a validade de um PPG.
     * Verifica se ja houve ocorrencia do mesmo no relatorio, bem como se a instituicao ja esta contemplada no PPG, isto e, se o PPG ja esta relacionado a IES.
     * 
     * @param nome
     * @param ies
     * @param codigo
     * @return um novo PPG caso o PPG em questao nao haja ocorrencia do mesmo no relatorio; o PPG existente que possui mesmo codigo no relatorio.
     */
    public PPG checaPpg(String nome, IES ies, String codigo){
        PPG ppg;
        if(programas.containsKey(codigo)){
            ppg = programas.get(codigo);
            ppg.checaIES(ies);
        }
        else{
            ppg = new PPG(nome, codigo);
            programas.put(codigo, ppg);
            this.qtdPpgs++;
        }
        ies.checaPpg(ppg);
        
        return ppg;
    }

    /**
     * Metodo que checa se o arquivo de leitura das informacoes do relatorio acabou.
     * @return true se o arquivo acabou; false se o arquivo nao acabou.
     */
    public Boolean acabou(){
        return this.csv.acabou();
    }

    /**
     * Metodo auxiliar que converte uma string para inteiro.
     * @param str a ser convertida
     * @return o inteiro convertido ou -1 se nao foi possivel fazer a conversao
     */
    private int converter(String str){
        try {
            return Integer.parseInt(this.csv.getColuna(str));
        } catch (Exception e) {
            return -1;
        }
    }

    /**
     * Metodo que avanca a linha sendo lida pelo relatorio, isto e, pula para a proxima linha do arquivo de entrada.
     */
    public void proximaLinha(){
        this.csv.proximaLinha();
        if(!acabou()) setMacros();
    }
    /**
     * Metodo auxiliar para atualizar os macros utilizados para obter as informacoes do arquivo csv.
     */
    private void setMacros(){
        TITULO = this.csv.getColuna("NM_TITULO");
        NATUREZA = this.csv.getColuna("DS_NATUREZA");
        IDIOMA = this.csv.getColuna("DS_IDIOMA");
        CIDADE = this.csv.getColuna("NM_CIDADE");
        PAGINAS_COLABORACAO = converter("NR_PAGINAS_CONTRIBUICAO");
        PAGINAS = converter("NR_PAGINAS");
        VOLUME = converter("NR_VOLUME");
        FASCICULO = converter("DS_FASCICULO");
        SERIE = converter("NR_SERIE");
        EVENTO = this.csv.getColuna("DS_EVENTO");
        CODIGO_PPG = this.csv.getColuna("CD_PROGRAMA_IES");
        NOME_PPG = this.csv.getColuna("NM_PROGRAMA_IES");
        SIGLA_IES = this.csv.getColuna("SG_ENTIDADE_ENSINO");
        NOME_IES = this.csv.getColuna("NM_ENTIDADE_ENSINO");
        PAG_INI = this.csv.getColuna("NR_PAGINA_INICIAL");
        PAG_FIN = this.csv.getColuna("NR_PAGINA_FINAL");
        SUBTIPO = converter("ID_SUBTIPO_PRODUCAO");
        DATA = this.csv.getColuna("DT_PUBLICACAO");
        ISSN = this.csv.getColuna("DS_ISSN");
        ISBN = this.csv.getColuna("DS_ISBN");
        EDITORA = this.csv.getColuna("NM_EDITORA");
        IDIOMA_TRADUCAO = this.csv.getColuna("DS_IDIOMA_TRADUCAO");
        FORMACAO_INSTRUMENTAL = this.csv.getColuna("DS_FORMACAO_INSTRUMENTAL");
        CIDADE_PAIS = this.csv.getColuna("NM_CIDADE_PAIS");
        EDITORA_TRADUCAO = this.csv.getColuna("NM_EDITORA_TRADUCAO");
    }

    /**
     * Metodo que adiciona uma producao ao relatorio.
     * @param producao
     */
    public void addProducao(Producao producao){
        this.producoes.add(producao);
        this.qtdPags += producao.getQtdPags();
        if(producao.getQtdPags() > 0) this.qtdProducoesComPags++;
        this.qtdProducoes = this.producoes.size();
    }

    /**
     * Metodo para executar os possiveis comandos de um relatorio. Caso o comando nao exista, apenas imprime {@code}Comando desconhecido.{@code}
     * @param inputs , um vetor de strings que representa os inputs dos comandos
     * @throws Exception
     */
    public void executaComando(String[] inputs) throws Exception{
        String comando = inputs[0];
        if(comando.equals("rede")) imprimeRedes();
        else if(comando.equals("ppg")) imprimePpg(inputs[1]);
        else if(comando.equals("ies")) imprimeIes(inputs[1]);
        else if(comando.equals("csv")) imprimeCsv(inputs[1], inputs[2]);
        else throw new ComandoDesconhecidoException();
    }

    /**
     * Metodo para imprimir os PPGs redes.
     */
    public void imprimeRedes(){
        System.out.println("Programas em rede:");
        ArrayList<PPG> redes = new ArrayList<>();
        for(PPG iter : programas.values()){
            if(iter.getRede()) redes.add(iter);
        }
        Collections.sort(redes);

        for(PPG iter : redes){
            iter.imprimeRede();
        }
    }
    /**
     * Metodo para imprimir um PPG que possui codigo {@code}codigo{@code}.
     * @param codigo do PPG que se deseja imprimir.
     * @throws PPGNaoEncontradoException
     */
    public void imprimePpg(String codigo) throws PPGNaoEncontradoException{
        if(!this.programas.containsKey(codigo)){
           throw new PPGNaoEncontradoException();
        }
        PPG ppg = programas.get(codigo);
        ppg.imprimeRede();
        System.out.println();
        ppg.imprimeProducoes();
    }

    /**
     * Metodo para imprimir as instituicoes que possuem sigla {@code}sigla{@code} em ordem alfabetica do nome.
     * @param sigla das ies que se deseja imprimir.
     * @throws IESNaoEncontradaException
     */
    public void imprimeIes(String sigla) throws IESNaoEncontradaException{
        ArrayList<IES> iess = new ArrayList<>();
        for(IES iter : this.instituicoes.values()) if(iter.getSigla().equals(sigla)) iess.add(iter);
        if(iess.size() == 0){
            throw new IESNaoEncontradaException();
        }
        Collections.sort(iess);
        for(IES iter : iess){
            iter.imprimePpgs();
        }
    }

    /**
     * Metodo auxiliar para converter os nomes de input das producoes para os nomes correspondentes de classe.
     * Auxilia na verificacao de classes.
     * @param producao, a string a ser convertida
     * @return a string com o nome de uma classe que representa o subtipo de producao, ou nulo se {@code}producao{@code} nao for valida.
     */
    private String converteProducao(String producao){
        if(producao.equals("anais")) return "Anal";
        else if(producao.equals("artjr")) return "ArtigoJR";
        else if(producao.equals("artpe")) return "ArtigoPE";
        else if(producao.equals("livro")) return "Livro";
        else if(producao.equals("partmu")) return "Partitura";
        else if(producao.equals("tradu")) return "Traducao";
        else if(producao.equals("outro")) return "Outro";
        else return null;

    }
    /**
     * Metodo para imprimir as informacoes do tipo de producao {@code}producao{@code} de um PPG de codigo {@code}codigo{@code}
     * @param codigo do PPG;
     * @param producao a ser impressa;
     */
    public void imprimeCsv(String codigo, String producao) throws TipoInvalidoException, PPGNaoEncontradoException{
        String tipo = converteProducao(producao);
        if(tipo == null){
            throw new TipoInvalidoException();
        }
        else if(!programas.containsKey(codigo)){
            throw new PPGNaoEncontradoException();
        }

        PPG ppg = this.programas.get(codigo);
        ppg.imprimeCsv(tipo);
    }
    
    public int getQtdIes() {
        return this.qtdIes;
    }

    public int getQtdPpgs() {
        return this.qtdPpgs;
    }

    public int getQtdProducoes() {
        return this.qtdProducoes;
    }

    public int getQtdPags(){
        return this.qtdPags;
    }

    public double getMedia_pags(){
        return this.media_pags;
    }
    /**
     * Atualiza o csv do relatorio, efetivamente trocando o arquivo sendo lido.
     * @param csv novo;
     */
    public void setCsv(CSV csv){
        this.csv = csv;
        setMacros();
    }
}