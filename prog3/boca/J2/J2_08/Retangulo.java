import java.util.Formatter;

public class Retangulo extends Quadrilateros{
    Retangulo(Double base, Double altura){
        super(base, altura, base, altura);
    }

    @Override
    public Double calculaArea(){
        return this.getL1() * this.getL2();
    }

    @Override
    public String toString(){
        Formatter f = new Formatter();
        String w = f.format("%.2f", this.getL1()).out().toString();
        f = new Formatter();
        String h = f.format("%.2f", this.getL2()).out().toString();
        f = new Formatter();
        String p = f.format("%.2f", this.calculaPerimetro()).out().toString();
        f = new Formatter();
        String a = f.format("%.2f", this.calculaArea()).out().toString();
        return "Retangulo de base " + w + "e altura " + h + "-perimetro: " + p + "; area: " + a + ".";
    }
}