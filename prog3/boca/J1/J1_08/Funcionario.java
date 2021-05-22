import java.util.Date;

public class Funcionario{

    String nome;
    Double salario;
    String data_adm;

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setSalario(Double salario){
        this.salario = salario;
    }

    public void setData_adm(String data){
        this.data_adm = data;
    }

    public String getNome(){
        return this.nome;
    }

    public Double getSalario(){
        return this.salario;
    }

    public String getData_adm(){
        return this.data_adm;
    }

    Funcionario(String nome, Double salario, String data){
        this.setNome(nome);
        this.setSalario(salario);
        this.setData_adm(data);
    }
}