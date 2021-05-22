import java.util.Locale;

public class Filial {


    private int id;
    private double renda;
    private int qtd_vendas;
    private double media;

    Filial(int id){
        this.id = id;
        this.renda = 0;
        this.qtd_vendas = 0;
    }

    public void addVenda(double preco){
        this.renda += preco;
        this.qtd_vendas++;
        this.media = this.renda / this.qtd_vendas;
    }

    public void imprime(){
        System.out.printf(new Locale("pt", "BR"), "Filial %d: Total = R$ %.2f; Media = R$ %.2f\n", this.id, this.renda, this.media);
    }
}