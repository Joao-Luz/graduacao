public class Produto{
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
}