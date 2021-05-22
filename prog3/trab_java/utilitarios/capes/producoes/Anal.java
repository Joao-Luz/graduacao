package utilitarios.capes.producoes;


public class Anal extends Producao implements Comparable<Anal>{
    private String evento;

    public Anal(String titulo, String natureza, String idioma, String cidade, int qtdPags, String evento){
        super(titulo, natureza, idioma, cidade, qtdPags);
        this.evento = evento;
        this.tipo = 1;
    }  

    public static void imprimeCabecalho(){
        System.out.println("Natureza;Titulo;Idioma;Evento;Cidade;Paginas");
    }
    
    @Override
    public String toString(){
        return (this.natureza + ";" + this.titulo + ";" + this.idioma + ";" + this.evento + ";" + this.cidade + ";" + this.qtdPags_string);
    }
    
    @Override
    public int compareTo(Anal o) {
        return this.natureza.compareTo(o.natureza) != 0 ?
        this.natureza.compareTo(o.natureza) : this.titulo.compareTo(o.titulo) != 0 ?
        this.titulo.compareTo(o.titulo) : this.idioma.compareTo(o.idioma) != 0 ?
        this.idioma.compareTo(o.idioma) : this.evento.compareTo(o.evento) != 0 ?
        this.evento.compareTo(o.evento) : this.cidade.compareTo(o.cidade) != 0 ?
        this.cidade.compareTo(o.cidade) : (this.qtdPags - o.qtdPags);
    }
}