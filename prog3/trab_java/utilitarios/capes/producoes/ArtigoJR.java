package utilitarios.capes.producoes;

import java.text.SimpleDateFormat;
import java.util.Date;

public class ArtigoJR extends Producao implements Comparable<ArtigoJR>{
    private Date data;
    private String issn;

    public ArtigoJR(String titulo, String idioma, String cidade, int qtdPags, String data, String issn){
        super(titulo, null, idioma, cidade, qtdPags);
        try {
            this.data = new SimpleDateFormat("dd/MM/yyyy").parse(data);
        } catch (Exception e) {
            this.data = null;
            e.printStackTrace();
        }
        this.issn = issn;
        this.tipo = 2;
    } 
    
    @Override
    public int compareTo(ArtigoJR o) {
        int cmp;

        cmp = this.titulo.compareTo(o.titulo); if(cmp!=0) return cmp;
        cmp = this.idioma.compareTo(o.idioma); if(cmp!=0) return cmp;
        cmp = this.cidade.compareTo(o.cidade); if(cmp!=0) return cmp;
        cmp = this.data.compareTo(o.data); if(cmp!=0) return cmp;
        cmp = this.issn.compareTo(o.issn); if(cmp!=0) return cmp;
        cmp = this.qtdPags - o.qtdPags; return cmp;
    }

    public static void imprimeCabecalho(){
        System.out.println("Titulo;Idioma;Cidade;Data;ISSN;Paginas");
    }
    
    @Override
    public String toString(){
        return (this.titulo + ";" + this.idioma + ";" + this.cidade + ";" + new SimpleDateFormat("dd/MM/yyyy").format(this.data) + ";" + this.issn + ";" + this.qtdPags_string);
    } 
}