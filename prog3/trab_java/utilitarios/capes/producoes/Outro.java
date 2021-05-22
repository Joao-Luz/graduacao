package utilitarios.capes.producoes;

public class Outro extends Producao implements Comparable<Outro> {
    private String editora;

    public Outro(String natureza, String idioma, String editora, String cidade, int qtdPags){
        super(null, natureza, idioma, cidade, qtdPags);
        this.editora = editora;
        this.tipo = 7;
    }

    @Override
    public int compareTo(Outro o) {
        return this.natureza.compareTo(o.natureza) != 0 ?
        this.natureza.compareTo(o.natureza) : this.idioma.compareTo(o.idioma) != 0 ? 
        this.idioma.compareTo(o.idioma) : this.editora.compareTo(o.editora) != 0 ?
        this.editora.compareTo(o.editora) : this.cidade.compareTo(o.cidade) != 0 ?
        this.cidade.compareTo(o.cidade) : this.qtdPags - o.qtdPags;
    }
    
    public static void imprimeCabecalho(){
        System.out.println("Natureza;Idioma;Editora;Cidade;Paginas");
    }

    @Override
    public String toString(){
        return (this.natureza + ";" + this.idioma + ";" + this.editora + ";" + this.cidade + ";" + this.qtdPags_string);
    } 
}