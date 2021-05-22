import java.util.Formatter;

public class CD extends Produto{
    private int faixas;

    CD(String nome, Double preco, int codigo, int faixas){
        super(nome, preco, codigo);
        this.faixas = faixas;
    }

    @Override
    public String toString(){
        Formatter f = new Formatter();
        String preco = f.format("%.2f", this.getPreco()).out().toString();
        return this.getNome() + " " + this.getCodigo() + " (R$ " + preco + ") - " + this.faixas + " faixas";
    }
}