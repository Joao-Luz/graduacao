import java.util.ArrayList;

public class CarrinhoDeCompras{
    ArrayList<ProdutoNoCarrinho> produtos;
    Double preco;
    int qtd;

    CarrinhoDeCompras(int qtd){
        this.qtd = qtd;
        this.produtos = new ArrayList<ProdutoNoCarrinho>();
        this.preco = 0.0;
    }

    public void adicionar(String nome, Double preco, int qtd){
        ProdutoNoCarrinho produto = new ProdutoNoCarrinho(nome, preco, qtd);
        this.produtos.add(produto);
        this.qtd++;
        this.preco += (preco * qtd);
    }

    public void imprimir(){
        System.out.println("No Carrinho:");

        for(ProdutoNoCarrinho produto : this.produtos){
            System.out.printf("* %dx %s = R$ %.2f\n", produto.getQtd(), produto.getProduto().getNome(), produto.getPreco());
        }
        System.out.printf("Total: R$ %.2f\n", this.preco);
    }

    public int getQtd() {
        return this.qtd;
    }

    public void setQtd(int qtd) {
        this.qtd = qtd;
    }


    public Double getPreco() {
        return this.preco;
    }

    public void setPreco(Double preco) {
        this.preco = preco;
    }
}