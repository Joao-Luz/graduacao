import java.util.Scanner;

public class J3_01{
    
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = Integer.parseInt(s.nextLine());
        String[] lista = new String[n];

        for(int i = 0; i < n; i++){
            lista[i] = s.nextLine();
        }

        int pos = Integer.parseInt(s.nextLine());

        try {
            System.out.println("Elemento na posicao " + pos + " :" + lista[pos]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Posicao " + pos + " esta fora dos limites do vetor.");
        }

    }
}