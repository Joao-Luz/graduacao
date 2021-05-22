import java.util.Scanner;

public class P1_2019_1_Questao03{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        PPG ppg = new PPG();

        int qtd = s.nextInt();
        s.nextLine();

        for(int i = 0; i < qtd; i++){
            String tipo = s.nextLine();
            String titulo = s.nextLine();
            String[] paginas = s.nextLine().split("-");
            int pagInicial = Integer.parseInt(paginas[0]);
            int pagFinal = Integer.parseInt(paginas[1]);
            String veiculo = s.nextLine();
            String qualis = s.nextLine();
            Artigo artigo = new Artigo(tipo, titulo, pagInicial, pagFinal, veiculo, qualis);
            
            ppg.addArtigo(artigo);
        }

        System.out.println("Total de paginas produzidas: " + ppg.getQtdPags());
        System.out.printf("Media por tipo: curto %.2f / longo %.2f / periodico %.2f\n", ppg.getMedia_curtos(), ppg.getMedia_longos(), ppg.getMedia_periodicos());
        System.out.println("Publicacoes por Qualis: " + ppg.getQtd_A1() + 
                           " x A1; " + ppg.getQtd_A2() + 
                           " x A2; " + ppg.getQtd_B1() + 
                           " x B1; " + ppg.getQtd_B2() + 
                           " x B2; " + ppg.getQtd_B3() + 
                           " x B3; " + ppg.getQtd_B4() + 
                           " x B4; " + ppg.getQtd_B5() + 
                           " x B5; " + ppg.getQtd_C() + " x C;");
    }
}