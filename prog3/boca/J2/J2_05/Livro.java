import java.util.Formatter;

public class Livro extends Produto{
    private String autor;

    Livro(String nome, Double preco, int codigo, String autor){
        super(nome, preco, codigo);
        this.autor = autor;
    }

    @Override
    public String toString(){
        Formatter f = new Formatter();
        String preco = f.format("%.2f", this.getPreco()).out().toString();
        return this.getNome() + " " + this.getCodigo() + " (R$ " + preco + ") - " + this.autor;
    }
}