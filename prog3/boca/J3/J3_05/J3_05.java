import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class J3_05{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        String pasta = s.nextLine();
        String nome_arquivo = pasta + "/" + java.util.UUID.randomUUID().toString() + ".txt";

        File arquivo;
        PrintWriter pw;
        try {
            arquivo = new File(nome_arquivo);
            pw = new PrintWriter(arquivo);
        } catch (Exception e) {
            System.out.println("Diretorio nao existe: " + pasta);
            
            return;
        }   

        int lim = s.nextInt();
        s.close();
        for(int a=0, b=1, i=0; i<lim; b+=a, a=b-a, i++) {
            pw.print(a + " ");
        }
        pw.println(); 
        pw.close();
        System.out.println(arquivo.length()); 
    }
}