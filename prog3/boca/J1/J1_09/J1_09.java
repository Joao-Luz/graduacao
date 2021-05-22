import java.util.Scanner;

public class J1_09{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Double mediaTurma = 0.0;

        int qtd = s.nextInt();

        Aluno[] alunos = new Aluno[qtd];

        for(int i = 0; i< qtd; i++){
            Aluno temp = new Aluno(s.next(), s.nextDouble(), s.nextDouble(), s.nextDouble());
            alunos[i] = temp;
            mediaTurma += temp.getMedia();
        }

        mediaTurma /= qtd;

        System.out.println("Nome,Nota,Situacao,Media");

        for(Aluno temp : alunos){
            String situacao = temp.getAprovado() ? "Aprovado" : "Prova Final";
            String media = temp.getMedia() > mediaTurma ? "Acima" : temp.getMedia() < mediaTurma ? "Abaixo" : "Na Media";
            System.out.printf("%s,%.1f,%s,%s\n", temp.getNome(), temp.getMedia(), situacao, media);
        }
    }
}