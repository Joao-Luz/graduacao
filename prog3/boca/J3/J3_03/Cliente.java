import java.util.Formatter;
import java.util.Locale;

public class Cliente{
    Double abate;
    Double saldo = 0.0;

    Cliente(){
        this.abate = 0.005;
    }

    public void Deposita(Double valor) throws Exception{
        if(valor < 0){
            Formatter f = new Formatter();
            String valors = f.format("%.1f", valor).out().toString();
            throw new Exception("Nao e' possivel depositar/sacar valor negativo: " + valors + ".");
        }
        this.saldo += valor;
    }

    public void Saca(Double valor) throws Exception{
        Formatter f = new Formatter();

        String valorsnf = f.format("%.1f", valor).out().toString();
        f = new Formatter();

        String valors = f.format(new Locale("pt", "BR"), "%.2f", valor).out().toString();
        f = new Formatter();
        
        String saldos = f.format(new Locale("pt", "BR"), "%.2f", this.saldo).out().toString();
        
        if(saldo < valor){
            throw new Exception("Voce deseja sacar R$ " + valors + ", porem seu saldo e' de apenas R$ " + saldos + ".");
        }

        if(valor < 0){
            throw new Exception("Nao e' possivel depositar/sacar valor negativo: " + valorsnf + ".");
        }

        this.saldo -= (valor * (1 + abate));
    }

    public Double getSaldo(){
        return this.saldo;
    }
}