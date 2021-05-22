import java.util.Formatter;

public class Livro extends Produto{
    private String autor;

    Livro(String nome, Double preco, String autor){
        super(nome, preco);
        this.autor = autor;
    }

    @Override
    public String toString(){
        Formatter f = new Formatter();
        String preco = f.format("%.2f", this.getPreco()).out().toString();
        return this.getNome() + " (R$ " + preco + ") - " + this.autor;
    }
}