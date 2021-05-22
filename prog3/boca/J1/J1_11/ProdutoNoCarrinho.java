public class ProdutoNoCarrinho{
    Double preco;
    int qtd;
    Produto produto;

    public Double getPreco() {
        return this.preco;
    }

    public void setPreco(Double preco) {
        this.preco = preco;
    }

    public int getQtd() {
        return this.qtd;
    }

    public void setQtd(int qtd) {
        this.qtd = qtd;
    }

    public Produto getProduto() {
        return this.produto;
    }

    public void setProduto(Produto produto) {
        this.produto = produto;
    }
    
    
    ProdutoNoCarrinho(Produto produto, int qtd){
        this.produto = produto;
        this.qtd = qtd;
        this.preco = produto.getPreco() * qtd;
    }

    ProdutoNoCarrinho(String nome, Double preco, int qtd){
        Produto produto = new Produto(nome, preco);
        this.produto = produto;
        this.qtd = qtd;
        this.preco = produto.getPreco() * qtd;
    }
}