import java.io.PrintStream;
import java.util.Scanner;

public class J3_06{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        PrintStream out;
        
        try {
            out = new PrintStream(System.out, true, "UTF-8");    
        } catch (Exception e) {
            return;
        }

        Evento e = new Evento(s.nextLine(), s.nextLine());
        out.println(e.imprime());
    }
}