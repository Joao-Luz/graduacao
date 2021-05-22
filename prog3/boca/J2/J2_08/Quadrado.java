import java.util.Formatter;

public class Quadrado extends Quadrilateros{
    Quadrado(Double lado){
        super(lado, lado, lado, lado);
    }

    @Override
    public Double calculaArea(){
        return  this.getL1() * this.getL1() ;
    }

    @Override
    public String toString(){
        Formatter f = new Formatter();
        String l = f.format("%.2f", this.getL1()).out().toString();
        f = new Formatter();
        String p = f.format("%.2f", this.calculaPerimetro()).out().toString();
        f = new Formatter();
        String a = f.format("%.2f", this.calculaArea()).out().toString();
        return "Quadrado de lado " + l + "-perimetro: " + p + "; area: " + a + ".";
    }
}