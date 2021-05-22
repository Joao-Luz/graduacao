
public class Produto implements Comparable{
    private String nome;
    private Double preco;
    private int codigo;

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Double getPreco() {
        return this.preco;
    }

    public void setPreco(Double preco) {
        this.preco = preco;
    }

    Produto(String nome, Double preco){
        this.nome = nome;
        this.preco = preco;
    }

    public int getCodigo(){
        return this.codigo;
    }

    @Override
    public int compareTo(Object o){
        Produto p = (Produto) o;

        if(this.preco - p.getPreco() < 0) return 1;
        else if(this.preco - p.getPreco() > 0) return -1;
        else return this.nome.compareToIgnoreCase(p.getNome());

    }
}