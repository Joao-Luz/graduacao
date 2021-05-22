import java.util.ArrayList;

public class PPG{
    private ArrayList<Artigo> artigosCurtos;
    private ArrayList<Artigo> artigosLongos;
    private ArrayList<Artigo> artigosPeriodicos;
    private int qtdPags = 0;
    private int qtdPags_curtos = 0;
    private int qtdPags_longos = 0;
    private int qtdPags_periodicos = 0;
    private int qtdArtigos_curtos = 0;
    private int qtdArtigos_longos = 0;
    private int qtdArtigos_periodicos = 0;
    private double media_curtos = 0;
    private double media_longos = 0;
    private double media_periodicos = 0;
    private int qtd_A1 = 0;
    private int qtd_A2 = 0;
    private int qtd_B1 = 0;
    private int qtd_B2 = 0;
    private int qtd_B3 = 0;
    private int qtd_B4 = 0;
    private int qtd_B5 = 0;
    private int qtd_C = 0;


    PPG(){
        this.artigosCurtos = new ArrayList<Artigo>();
        this.artigosLongos = new ArrayList<Artigo>();
        this.artigosPeriodicos = new ArrayList<Artigo>();
    }

    public void addArtigo(Artigo artigo){
        this.qtdPags += artigo.getQtdPags();
        if(artigo.getTipo_id() != 2){
            if(artigo.getQualis().equals("A1")) this.qtd_A1++;
            if(artigo.getQualis().equals("A2")) this.qtd_A2++;
            if(artigo.getQualis().equals("B1")) this.qtd_B1++;
            if(artigo.getQualis().equals("B2")) this.qtd_B2++;
            if(artigo.getQualis().equals("B3")) this.qtd_B3++;
            if(artigo.getQualis().equals("B4")) this.qtd_B4++;
            if(artigo.getQualis().equals("B5")) this.qtd_B5++;
            if(artigo.getQualis().equals("C")) this.qtd_C++;

        }

        if(artigo.getTipo_id() == 1){ 
            this.artigosLongos.add(artigo);
            if(artigo.valido()){
                this.qtdArtigos_longos++;
                this.qtdPags_longos += artigo.getQtdPags();
                if(this.qtdArtigos_longos > 0)this.media_longos = (double)this.qtdPags_longos / this.qtdArtigos_longos;
            }
        }
        if(artigo.getTipo_id() == 2){ 
            this.artigosCurtos.add(artigo);
            if(artigo.valido()){
                this.qtdArtigos_curtos++;
                this.qtdPags_curtos += artigo.getQtdPags();
                if(this.qtdArtigos_curtos > 0)this.media_curtos = (double)this.qtdPags_curtos / this.qtdArtigos_curtos;
            }
        }
        if(artigo.getTipo_id() == 3){ 
            this.artigosPeriodicos.add(artigo);
            if(artigo.valido()){
                this.qtdArtigos_periodicos++;
                this.qtdPags_periodicos += artigo.getQtdPags();
                if(this.qtdArtigos_periodicos > 0)this.media_periodicos = (double)this.qtdPags_periodicos / this.qtdArtigos_periodicos;
            }
        }
    }


    public int getQtdPags() {
        return this.qtdPags;
    }

    public double getMedia_curtos() {
        return this.media_curtos;
    }

    public double getMedia_longos() {
        return this.media_longos;
    }

    public double getMedia_periodicos() {
        return this.media_periodicos;
    }

    public int getQtd_A1() {
        return this.qtd_A1;
    }

    public int getQtd_A2() {
        return this.qtd_A2;
    }

    public int getQtd_B1() {
        return this.qtd_B1;
    }

    public int getQtd_B2() {
        return this.qtd_B2;
    }

    public int getQtd_B3() {
        return this.qtd_B3;
    }

    public int getQtd_B4() {
        return this.qtd_B4;
    }

    public int getQtd_B5() {
        return this.qtd_B5;
    }

    public int getQtd_C() {
        return this.qtd_C;
    }

}

