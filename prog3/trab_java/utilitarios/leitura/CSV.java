package utilitarios.leitura;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class CSV{
    private FileReader arquivo;
    private BufferedReader scanner;
    private String[] cabecalho;
    private String[] atual;
    private final String regex = ";(?=(?:[^\"]*\"[^\"]*\")*(?![^\"]*\"))";

    public CSV(String nome_arquivo) throws Exception{
        try {
            this.arquivo = new FileReader(nome_arquivo);
            this.scanner = new BufferedReader(this.arquivo);
            this.cabecalho = this.scanner.readLine().split(regex);
            this.atual = this.scanner.readLine().split(regex);
        } catch (Exception e) {
            throw new FileNotFoundException();
        }
    }

    public String getColuna(String coluna){
        for(int i = 0; i < this.atual.length; i++){
            if(this.cabecalho[i].equals(coluna)){
                return this.atual[i]; 
            }
        }

        return null;

    }

    public String getColuna(int index) throws Exception{
        if(index < this.atual.length) return this.atual[index];
        
        throw new Exception("Coluna \"" + index + "\" Nao Encontrada");
    }


    public void proximaLinha(){
        try {
            String linha = this.scanner.readLine();
            this.atual = linha.split(regex);
        } catch (Exception e) {
            this.atual = null;
        }
    }

    public Boolean acabou(){
        return this.atual == null;
    }


}