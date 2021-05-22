package utilitarios.capes.producoes;

public class Partitura extends Producao implements Comparable<Partitura> {
    String editora;
    String formacao_instrumental;

    public Partitura(String natureza, String idioma, String cidade, int qtdPags, String editora, String formacao_instrumental){
        super(null, natureza, idioma, cidade, qtdPags);
        this.editora = editora;
        this.formacao_instrumental = formacao_instrumental;
        this.tipo = 5;
    }

    @Override
    public int compareTo(Partitura o) {
        return this.natureza.compareTo(o.natureza) != 0 ?
        this.natureza.compareTo(o.natureza) : this.editora.compareTo(o.editora) != 0 ?
        this.editora.compareTo(o.editora) : this.cidade.compareTo(o.cidade) != 0 ?
        this.cidade.compareTo(o.cidade) : this.formacao_instrumental.compareTo(o.formacao_instrumental) != 0 ?
        this.formacao_instrumental.compareTo(o.formacao_instrumental) : this.qtdPags - o.qtdPags;
    }

    public static void imprimeCabecalho(){
        System.out.println("Natureza;Editora;Cidade;Formacao;Paginas");
    }  

    @Override
    public String toString(){
        return (this.natureza + ";" + this.editora + ";" + this.cidade + ";" + this.formacao_instrumental + ";" + this.qtdPags_string);
    } 
}