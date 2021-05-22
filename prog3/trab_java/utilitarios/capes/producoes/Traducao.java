package utilitarios.capes.producoes;

public class Traducao extends Producao implements Comparable<Traducao> {
    String editora;
    String idioma_traducao;

    public Traducao(String titulo, String natureza, String idioma, String cidade, int qtdPags, String editora, String idioma_traducao){
        super(titulo, natureza, idioma, cidade, qtdPags);
        this.editora = editora;
        this.idioma_traducao = idioma_traducao;
        this.tipo = 6;
    }

    @Override
    public int compareTo(Traducao o) {
        return this.natureza.compareTo(o.natureza) != 0 ?
        this.natureza.compareTo(o.natureza) : this.titulo.compareTo(o.titulo) != 0 ?
        this.titulo.compareTo(o.titulo) : this.idioma.compareTo(o.idioma) != 0 ?
        this.idioma.compareTo(o.idioma) : this.editora.compareTo(o.editora) != 0 ?
        this.editora.compareTo(o.editora) : this.cidade.compareTo(o.cidade) != 0 ?
        this.cidade.compareTo(o.cidade) : this.idioma_traducao.compareTo(o.idioma_traducao) != 0 ?
        this.idioma_traducao.compareTo(o.idioma_traducao) : this.qtdPags - o.qtdPags;
    }

    public static void imprimeCabecalho(){
        System.out.println("Natureza;Titulo;Idioma;Editora;Cidade;Traducao;Paginas");
    }

    @Override
    public String toString(){
        return (this.natureza + ";" + this.titulo + ";" + this.idioma + ";" + this.editora + ";" + this.cidade + ";" + this.idioma_traducao + ";" + this.qtdPags_string);
    } 
}