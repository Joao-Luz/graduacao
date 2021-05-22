import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
import java.util.Locale;


public class J1_08{
    public static void main(String[] args) {
        Locale loc = new Locale("pt", "BR");
        Scanner s = new Scanner(System.in);
        Empresa emp = new Empresa(s.next(), s.next());
        int nDep = s.nextInt();

        for(int i = 0; i < nDep; i++){
            Departamento dep = new Departamento(s.next());
            int nFunc = s.nextInt();
            for(int j = 0; j < nFunc; j++){
                String nome = s.next();
                Double salario = s.nextDouble();
                String data = s.next();
                Funcionario func = new Funcionario(nome, salario, data);
                dep.addFuncionario(func);
            }
            emp.addDepartamento(dep);
        }

        for(int i = 0; i < emp.getDepartamento(0).getNFunc(); i++){
            Funcionario func = emp.getDepartamento(0).getFuncionario(i);
            Double novoSalario = func.getSalario();
            novoSalario *= 1.1;
            func.setSalario(novoSalario);
        }

        Funcionario func = emp.getDepartamento(0).getFuncionario(0);
        emp.getDepartamento(0).removeFuncionario(0);
        emp.getDepartamento(1).addFuncionario(func);

        for(int i = 0; i < emp.getNDep(); i++){
            Departamento dep = emp.getDepartamento(i);
            Double custo = 0.0;
            for(int j = 0; j < dep.getNFunc(); j++){
                func = dep.getFuncionario(j);
                custo += func.getSalario();
            }
            System.out.printf(loc, "%s R$ %.2f\n", dep.getNome(), custo);

            s.close();
        }
    }
}