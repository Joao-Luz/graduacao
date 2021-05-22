import java.util.ArrayList;

public class Departamento{

    ArrayList<Funcionario> funcionarios;
    String nome;
    int nFunc;
    Double custo;

    Departamento(String nome){
        this.nome = nome;
        this.funcionarios = new ArrayList<Funcionario>();
        this.nFunc = 0;
    }

    public void addFuncionario(Funcionario func){
        this.funcionarios.add(func);
        this.nFunc++;
    }

    public Funcionario removeFuncionario(int index){
        Funcionario returnValue = this.funcionarios.get(index);
        this.funcionarios.remove(index);
        this.nFunc--;
        return returnValue;
    }

    public Funcionario getFuncionario(int index){
        return this.funcionarios.get(index);
    }

    public String getNome(){
        return this.nome;
    }

    public int getNFunc(){
        return this.nFunc;
    }
}