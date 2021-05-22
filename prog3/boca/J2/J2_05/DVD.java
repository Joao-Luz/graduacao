import java.util.Formatter;

public class DVD extends Produto{
    private int minutos;

    DVD(String nome, Double preco, int codigo, int minutos){
        super(nome, preco, codigo);
        this.minutos = minutos;
    }

    @Override
    public String toString(){
        Formatter f = new Formatter();
        String preco = f.format("%.2f", this.getPreco()).out().toString();
        return this.getNome() + " " + this.getCodigo() + " (R$ " + preco + ") - " + this.minutos + " minutos";
    }
}