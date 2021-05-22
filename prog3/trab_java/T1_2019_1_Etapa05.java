import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

import utilitarios.capes.Relatorio;
import utilitarios.leitura.CSV;

//";(?=([^\"]*\"[^\"]*\")*[^\"]*$)"

public class T1_2019_1_Etapa05{
    public static void main(String[] args) {
        Locale.setDefault(new Locale("pt", "PT"));

        Scanner s = new Scanner(System.in);
        String diretorio = s.nextLine();
        String nomes[] = new String[7];
        for(int i = 0; i < 7; i ++) nomes[i] = s.nextLine();
        String[] inputs = s.nextLine().split(" ");
        s.close();
        
        
        try {
            Relatorio rel = new Relatorio();
            for(int i = 0; i < 7; i++){ 
                String caminho_completo = diretorio + nomes[i];
                CSV csv = null;
    
                csv = new CSV(caminho_completo);
    
    
                rel.setCsv(csv);
                while(!rel.acabou()){
                    rel.update();
                    rel.proximaLinha();
                }
            }
            
            rel.executaComando(inputs);
            
        }catch (FileNotFoundException e) {
            System.out.println("Erro de I/O");
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}