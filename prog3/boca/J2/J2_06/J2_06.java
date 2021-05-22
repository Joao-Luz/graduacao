import java.util.Locale;
import java.util.Scanner;

public class J2_06{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Cliente c = null;

        char tipo = s.nextLine().charAt(0);

        if(tipo == 'C') c = new Cliente();
        else c = new ClienteEspecial();

        

        for(String[] line = s.nextLine().split(" "); line[0].charAt(0) != '.'; line = s.nextLine().split(" ")){
            if(line[0].charAt(0) == '+'){
                c.Deposita(Double.parseDouble(line[1]));
            }
            if(line[0].charAt(0) == '-'){
                c.Saca(Double.parseDouble(line[1]));
            }

            System.out.printf(new Locale("pt", "BR"), "R$ %.2f\n", c.getSaldo());
        }
    }
}