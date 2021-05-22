package utilitarios.capes.producoes;

/**
 * Classe Abstrata que representa uma producao academica generica. Deve ser extendida pelas subclasses e, preferencialmente, ter o metodo {@code}toString{@code} sobreposto.
 */
public abstract class Producao{
    protected String titulo;
    protected String natureza;
    protected String idioma;
    protected String cidade;
    protected int qtdPags;
    protected int tipo;
    protected String qtdPags_string;
    
    public Producao(String titulo, String natureza, String idioma, String cidade, int qtdPags){
        this.idioma = idioma;
        this.cidade = cidade;
        this.qtdPags = qtdPags;
        this.titulo = titulo;
        this.natureza = natureza;
        this.qtdPags_string = this.qtdPags <= 0 ? "" : "" + this.qtdPags;
    }
    
    @Override
    public boolean equals(Object obj) {
        return this.toString().equals(obj.toString());
    }

    public int getQtdPags() {
        return this.qtdPags;
    }

    public int getTipo(){
        return this.tipo;
    }

    /**
     * Metodo interno auxiliar para a conversao de valores inteiros em string. Aqui, qualquer numero menor que zero sera equivalente a uma string vazia.
     * @param val o valor a ser convertido
     * @return O proprio valor em forma {@code}String{@code} se {@code}val >= 0{@code}, ou uma string vazia, caso {@code}val < 0{@code}
     */
    protected String formataNum(int val){
        return val < 0 ? "" : "" + val;
    }

}