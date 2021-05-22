import java.util.Scanner;

public class J2_08{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = Integer.parseInt(s.nextLine());

        for(int i = 0; i < n; i ++){
            String[] linha = s.nextLine().split(",");
            char tipo = linha[0].charAt(0);
            Formas forma = null;

            if(tipo == 'C'){
                forma = new Circulo(Double.parseDouble(linha[1]));
            }

            if(tipo == 'Q'){
                forma = new Quadrado(Double.parseDouble(linha[1]));
            }

            if(tipo == 'R'){
                forma = new Retangulo(Double.parseDouble(linha[1]), Double.parseDouble(linha[2]));
            }

            System.out.println(forma.toString());
        }
    }
}