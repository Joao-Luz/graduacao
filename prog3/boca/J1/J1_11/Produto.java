public class Produto{
    Double preco;
    String nome;

    Produto(String nome, Double preco){
        this.preco = preco;
        this.nome = nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }    

    public void setPreco(Double preco){
        this.preco = preco;
    }

    public String getNome(){
        return this.nome;
    }    

    public Double getPreco(){
        return this.preco;
    }
}