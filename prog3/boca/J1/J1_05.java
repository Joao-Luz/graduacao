import java.lang.reflect.Array;
import java.util.Scanner;

public class J1_05{
    public static void main(String[] args) {
        int[] vec = new int[10];
        int raz = 0;

        Scanner s = new Scanner(System.in);
        for(int i = 0; i<10; i++){
            vec[i] = s.nextInt();

            if(i >= 1) {
                if(i > 1 && (vec[i] - vec[i - 1] != raz)){
                    System.out.println("Nao");
                    return;
                }
                raz = vec[i] - vec[i-1];
            }
        }
        System.out.println("Sim " + vec[0] + " " + raz);
    }
}