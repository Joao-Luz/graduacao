package utilitarios.capes.producoes;

public class ArtigoPE extends Producao implements Comparable<ArtigoPE>{
    private String editora;
    private int volume;
    private String volume_string;
    private int fasciculo;
    private String fasciculo_string;
    private int serie;
    private String serie_string;
    private String issn;
    private String pagFin;
    private String pagIni;
    

    public ArtigoPE(String natureza, String idioma, String cidade, int qtdPags, String editora, int volume, int fasciculo, int serie, String issn, String pagIni, String pagFin){
        super(null, natureza, idioma, cidade, qtdPags);
        this.editora = editora;
        this.volume = volume;
        this.volume_string = formataNum(volume);
        this.fasciculo = fasciculo;
        this.fasciculo_string = formataNum(fasciculo);
        this.serie = serie;
        this.serie_string = formataNum(serie);
        this.issn = issn;
        this.tipo = 3;
        this.pagIni = pagIni;
        this.pagFin = pagFin;
    }

    @Override
    public int compareTo(ArtigoPE o) {
        int cmp;

        cmp = this.natureza.compareTo(o.natureza); if(cmp!=0) return cmp;
        cmp = this.idioma.compareTo(o.idioma);     if(cmp!=0) return cmp;
        cmp = this.editora.compareTo(o.editora);   if(cmp!=0) return cmp;
        cmp = this.cidade.compareTo(o.cidade);     if(cmp!=0) return cmp;
        cmp = this.volume - o.volume;              if(cmp!=0) return cmp;
        cmp = this.fasciculo - o.fasciculo;        if(cmp!=0) return cmp;
        cmp = this.serie - o.serie;                if(cmp!=0) return cmp;
        cmp = this.qtdPags - o.qtdPags;            if(cmp!=0) return cmp;
        cmp = this.issn.compareTo(o.issn);                    return cmp;
    }

    public static void imprimeCabecalho(){
        System.out.println("Natureza;Idioma;Editora;Cidade;Volume;Fasciulo;Serie;ISSN;Paginas");
    }

    @Override
    public String toString(){
        return (this.natureza + ";" + this.idioma + ";" + this.editora + ";" + this.cidade + ";" + this.volume_string + ";" + this.fasciculo_string + ";" + this.serie_string + ";" + this.issn + ";" + this.qtdPags_string);
    } 
}