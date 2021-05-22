import java.util.ArrayList;

public class Empresa{

    String nome, cnpj;
    int nDep;
    ArrayList<Departamento> departamentos;

    Empresa(String nome, String cnpj){
        this.nome = nome;
        this.cnpj = cnpj;
        this.departamentos = new ArrayList<Departamento>();
    }

    public void addDepartamento(Departamento dep){
        this.departamentos.add(dep);
        this.nDep++;
    }

    public Departamento removeDepartamento(int index){
        Departamento returnValue = this.departamentos.get(index);
        this.departamentos.remove(index);
        this.nDep--;
        return returnValue;
    }

    public Departamento getDepartamento(int index){
        return this.departamentos.get(index);
    }

    public String getNome(){
        return this.nome;
    }

    public int getNDep(){
        return this.nDep;
    }
}