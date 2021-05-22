public class Cliente{
    Double abate;
    Double saldo = 0.0;

    Cliente(){
        this.abate = 0.005;
    }

    public void Deposita(Double valor){
        this.saldo += valor;
    }

    public void Saca(Double valor){
        this.saldo -= (valor * (1 + abate));
    }

    public Double getSaldo(){
        return this.saldo;
    }
}