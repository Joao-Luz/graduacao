package utilitarios.capes;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import utilitarios.capes.producoes.*;

/**
 * Classe comparadora que realiza a comparacao entre dois PPGs pelo nome
 */
class ComparadorNome implements Comparator<PPG>{
    public int compare(PPG a, PPG b){
        return a.getNome().compareTo(b.getNome());
    }
}

/**
 * Classe que representa um Programa de Pos Graducao.
 */
public class PPG implements Comparable<PPG>{
    private String nome;
    private ArrayList<IES> instituicoes;
    private String codigo;
    private ArrayList<Producao> producoes;
    private int qtdProducoes = 0;
    private int qtdPags = 0;
    private boolean rede = false;
    private int qtdAnal = 0;
    private int qtdArtjr = 0;
    private int qtdArtpe = 0;
    private int qtdLivro = 0;
    private int qtdPartmu = 0;
    private int qtdTradu = 0;
    private int qtdOutro = 0;


    PPG(String nome, String codigo){
        this.nome = nome;
        this.instituicoes = new ArrayList<>();
        this.codigo = codigo;
        this.producoes = new ArrayList<Producao>();
    }

    @Override
    public int compareTo(PPG o) {
        return this.codigo.compareTo(o.getCodigo());
    }

    @Override
    public boolean equals(Object o){
        PPG ppg = (PPG) o;
        return this.codigo.equals(ppg.getCodigo());
    }
    /**
     * Metodo que cadastra uma producao {@code}producao{@code} ao PPG
     * @param producao a ser cadastrada
     */
    public void addProducao(Producao producao){
        if(!this.producoes.contains(producao))this.producoes.add(producao);
        this.qtdPags += producao.getQtdPags();
        this.qtdProducoes++;

        if(producao instanceof Anal) this.qtdAnal++;
        if(producao instanceof ArtigoJR) this.qtdArtjr++;
        if(producao instanceof ArtigoPE) this.qtdArtpe++;
        if(producao instanceof Livro) this.qtdLivro++;
        if(producao instanceof Partitura) this.qtdPartmu++;
        if(producao instanceof Traducao) this.qtdTradu++;
        if(producao instanceof Outro) this.qtdOutro++;

    }

    /**
     * Metodo que verifica se o PPG possui uma instituicao {@code}ies{@code} e, caso nao possua, cadastra a mesma ao PPG. 
     * Se o PPG possuir mais de uma instituicao cadastrada, o metodo qualifica ele como Rede.
     * @param ies a ser checada
     */
    public void checaIES(IES ies){
        if(!instituicoes.contains(ies))
            instituicoes.add(ies);

        if(instituicoes.size() > 1) this.rede = true;
        Collections.sort(this.instituicoes);    
    }

    /**
     * Metodo que imprime as instituicoes cadastradas do PPG.
     */
    public void imprimeRede(){
        System.out.println("Programa: " + this.getNome());
        System.out.println("Instituicoes:");
        for(IES iter : this.instituicoes){
            System.out.print("\t");
            System.out.println("- " + iter.getSigla() + " (" + iter.getNome() + ")");
        }
    }

    /**
     * Metodo que imprime a quantidade de cada subtipo de producao o PPG possui.
     */
    public void imprimeProducoes(){
        System.out.println("Quantidade de producoes por tipo:");
        System.out.println("\t- Artigos em anais de eventos: " + this.qtdAnal);
        System.out.println("\t- Artigos em jornais e revistas: " + this.qtdArtjr);
        System.out.println("\t- Artigos em periodicos cientificos: " + this.qtdArtpe);
        System.out.println("\t- Livros: " + this.qtdLivro);
        System.out.println("\t- Partituras musicais: " + this.qtdPartmu);
        System.out.println("\t- Traducoes: " + this.qtdTradu);
        System.out.println("\t- Outros: " + this.qtdOutro);
        System.out.println("\nTotal de paginas produzidas pelo PPG: " + this.qtdPags);

    }

    /**
     * Metodo que imprime informacoes de forma simplificada sobre o PPG
     */
    public void imprimeSimples(){
        System.out.println("\t- " + this.nome + ": " + this.qtdProducoes + " producoes");
    }

    private void imprimeCabecalho(String tipo){
        if(tipo.equals("Anal")) Anal.imprimeCabecalho();
        if(tipo.equals("ArtigoPE")) ArtigoPE.imprimeCabecalho();
        if(tipo.equals("ArtigoJR")) ArtigoJR.imprimeCabecalho();
        if(tipo.equals("Livro")) Livro.imprimeCabecalho();
        if(tipo.equals("Partitura")) Partitura.imprimeCabecalho();
        if(tipo.equals("Traducao")) Traducao.imprimeCabecalho();
        if(tipo.equals("Outro")) Outro.imprimeCabecalho();
    }
    /**
     * 
     * Metodo que imprime as informacoes de um tipo de producao especifico do PPG.
     * O parametro fornecido deve ser: {@code}Anal{@code} {@code}ArtigoPE{@code} {@code}ArtigoJR{@code} {@code}Livro{@code} {@code}Partitura{@code} {@code}Traducao{@code} {@code}Outro{@code}.
     * @param tipo o tipo da producao que se deseja observar.
     */
    public void imprimeCsv(String tipo){
        imprimeCabecalho(tipo);
        List prods = new ArrayList<>();
        
        for(Producao iter : this.producoes){
            try {
                if(Class.forName(tipo).isInstance(iter)) prods.add(iter);
            } catch (ClassNotFoundException e){
                continue;
            }
        }
        Collections.sort(prods);
        for(Object iter : prods) System.out.println(iter.toString());
    }

    public String getNome() {
        return this.nome;
    }

    public String getCodigo() {
        return this.codigo;
    }

    public int getQtdPags(){
        return this.qtdPags;
    }

    public boolean getRede(){
        return this.rede;
    }
    
}