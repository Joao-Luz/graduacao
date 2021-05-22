public class Aluno{
    Double nota1, nota2, nota3, media;

    Boolean aprovado;

    String nome;

    Aluno(String nome, Double nota1, Double nota2, Double nota3){
        this.nota1 = nota1;
        this.nota2 = nota2;
        this.nota3 = nota3;

        this.media = (nota1 + nota2 + nota3)/3.0;

        this.nome = nome;

        this.aprovado = this.media >= 7.0;
        }

    public Double getNota1(){
        return this.nota1;
    }

    public Double getNota2(){
        return this.nota2;
    }

    public Double getNota3(){
        return this.nota3;
    }

    public Double getMedia(){
        return this.media;
    }

    public String getNome(){
        return this.nome;
    }

    public Boolean getAprovado(){
        return this.aprovado;
    }

}