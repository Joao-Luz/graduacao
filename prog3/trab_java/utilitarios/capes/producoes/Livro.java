package utilitarios.capes.producoes;

public class Livro extends Producao implements Comparable<Livro> {
    private String editora;
    private String isbn;

    public Livro(String titulo, String natureza, String idioma, String cidade, int qtdPags, String editora, String isbn) {
        super(titulo, natureza, idioma, cidade, qtdPags);
        this.editora = editora;
        this.isbn = isbn;
        this.tipo = 4;
    }

    @Override
    public int compareTo(Livro o) {
        return this.natureza.compareTo(o.natureza) != 0 ?
        this.natureza.compareTo(o.natureza) : this.titulo.compareTo(o.titulo) != 0 ?
        this.titulo.compareTo(o.titulo) : this.idioma.compareTo(o.idioma) != 0 ? 
        this.idioma.compareTo(o.idioma) : this.editora.compareTo(o.editora) != 0 ?
        this.editora.compareTo(o.editora) : this.cidade.compareTo(o.cidade) != 0 ?
        this.cidade.compareTo(o.cidade) : this.isbn.compareTo(o.isbn) != 0 ?
        this.isbn.compareTo(o.isbn) : this.qtdPags - o.qtdPags;
    }
    public static void imprimeCabecalho(){
        System.out.println("Natureza;Titulo;Idioma;Editora;Cidade;ISBN;Paginas");
    }
    
    @Override
    public String toString(){
        return (this.natureza + ";" + this.titulo + ";" + this.idioma + ";" + this.editora + ";" + this.cidade + ";" + this.isbn+ ";" + this.qtdPags_string);
    } 
}