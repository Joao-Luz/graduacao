import java.util.Scanner;

public class J1_10{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int lim = s.nextInt();

        for(int a=0, b=1, i=0; i<lim; b+=a, a=b-a, i++) {
			System.out.print(a + " ");
        } 
        System.out.println(); 
    }
}