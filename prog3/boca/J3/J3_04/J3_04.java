

import java.io.File;

import java.util.Scanner;

public class J3_04{
    public static void main(String[] args) {

        

        Scanner s = new Scanner(System.in);

        String nome_arquivo = s.nextLine();
        Scanner arquivo;
        
        s.close();

       try {
            arquivo = new Scanner(new File(nome_arquivo));
       } catch (Exception e) {
           return;
       } 

        Filial[] filiais = new Filial[4];
        for(int i = 0; i < 4; i++) filiais[i] = new Filial(i + 1); 

        while(true){
            String[] info = arquivo.nextLine().split(",");
            int index = Integer.parseInt(info[0]) - 1;
            filiais[index].addVenda(Double.parseDouble(info[1]));
            if(!arquivo.hasNext()) break;
        }
        arquivo.close();
        for(Filial iter : filiais) iter.imprime();

    }
}