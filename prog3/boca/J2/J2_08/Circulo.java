import java.util.Formatter;

public class Circulo implements Formas{
    Double raio;

    Circulo(Double raio){
        this.raio = raio;
    }

    @Override
    public Double calculaPerimetro(){
        return 2 * Math.PI * this.raio;
    }
    @Override
    public Double calculaArea(){
        return Math.PI * this.raio * this.raio;
    }

    @Override
    public String toString(){
        Formatter f = new Formatter();
        String r = f.format("%.2f", this.raio).out().toString();
        f = new Formatter();
        String p = f.format("%.2f", this.calculaPerimetro()).out().toString();
        f = new Formatter();
        String a = f.format("%.2f", this.calculaArea()).out().toString();
        return "Circulo de raio " + r + "-perimetro: " + p + "; area: " + a + ".";
    }

}