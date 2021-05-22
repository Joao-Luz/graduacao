import java.util.Arrays;
import java.util.Scanner;
import java.lang.String;

public class J2_07{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = Integer.parseInt(s.nextLine());
        Produto[] produtos = new Produto[n];

        for(int i = 0; i < n; i++){
            String line = s.nextLine();
            String[] linha = line.split(",");
            String nome = linha[1];
            Double preco = Double.parseDouble(linha[2]);
            String info = linha[3];
            Produto produto = new Produto(nome, preco);
            
            if(linha[0].charAt(0) == 'C'){
                produto = new CD(nome, preco, Integer.parseInt(info));
            }

            if(linha[0].charAt(0) == 'D'){
                produto = new DVD(nome, preco, Integer.parseInt(info));
            }

            if(linha[0].charAt(0) == 'L'){
                produto = new Livro(nome, preco, info);
            }

            produtos[i] = produto;
        }

        Arrays.sort(produtos);

        for(Produto p : produtos) System.out.println(p.toString());
    }

}