import java.util.Scanner;
import java.lang.String;

public class J2_05{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = Integer.parseInt(s.nextLine());
        Produto[] produtos = new Produto[n];
        Produto P = null;

        for(int i = 0; i < n + 1; i++){
            String line = s.nextLine();
            String[] linha = line.split(",");
            int codigo = Integer.parseInt(linha[1]);
            String nome = linha[2];
            Double preco = Double.parseDouble(linha[3]);
            String info = linha[4];
            Produto produto = new Produto(nome, preco, codigo);
            
            if(linha[0].charAt(0) == 'C'){
                produto = new CD(nome, preco, codigo, Integer.parseInt(info));
            }

            if(linha[0].charAt(0) == 'D'){
                produto = new DVD(nome, preco, codigo, Integer.parseInt(info));
            }

            if(linha[0].charAt(0) == 'L'){
                produto = new Livro(nome, preco, codigo, info);
            }

            if(i < n) produtos[i] = produto;
            else P = produto;
        }

        for(int i = 0; i<produtos.length; i++){
            if(P.equals(produtos[i])){
                System.out.println(i);
                return;
            }
        }
        System.out.println("Produto nao encontrado.");
    }

}