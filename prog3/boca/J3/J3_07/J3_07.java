import java.io.PrintStream;
import java.util.Locale;
import java.util.ResourceBundle;
import java.util.Scanner;

public class J3_07{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        ResourceBundle rb;
        PrintStream out;
        String lingua = s.next();
        String local = s.next();
        s.nextLine();

        Locale l = new Locale(lingua, local);
        String key = s.nextLine();
        
        
        try {
            out = new PrintStream(System.out, true, "UTF-8");
            rb = ResourceBundle.getBundle("mensagens", l);    
        } catch (Exception e) {
            return;
        }
        
        String msg = rb.getString(key);
        Evento e = new Evento(msg, s.nextLine(), l);
        msg = rb.getString("text.occurredin");

        out.println(e.getNome() + " -" + msg + " " + e.getDia_da_semana());
    }
}