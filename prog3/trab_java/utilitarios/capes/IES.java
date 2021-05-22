package utilitarios.capes;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class IES implements Comparable<IES>{
    private String nome;
    private String sigla;
    private Map<String, PPG> ppgs;
    private int qtdPpgs = 0;

    @Override
    public int compareTo(IES o) {
        return (this.sigla + this.nome).compareTo(o.sigla + o.nome);
    }

    @Override
    public boolean equals(Object o){
        IES ies = (IES) o;
        return (this.nome + this.sigla).equals(ies.getNome() + ies.getSigla());
    }
    
    public int getQtdPpgs() {
        return this.qtdPpgs;
    }


    public IES(String nome, String sigla) {
        this.nome = nome;
        this.sigla = sigla;
        this.ppgs = new HashMap<>();
    }

    /**
     * Metodo que checa se a instituicao possui o PPG {@code}ppg{@code} e, caso nao possua, cadastra o mesmo na instituicao.
     * @param ppg a ser checado
     */
    public void checaPpg(PPG ppg){
        if(!ppgs.containsKey(ppg.getCodigo())){
            ppgs.put(ppg.getCodigo(), ppg);
        }
    }

    /**
     * Metodo que imprime os PPGs da intituicao ordenados pelo nome.
     */
    public void imprimePpgs(){
        ArrayList<PPG> listaPpgs = new ArrayList<>();
        System.out.println(this.nome + " (" + this.sigla + "):");
        for(PPG iter : this.ppgs.values()) listaPpgs.add(iter);
        Collections.sort(listaPpgs, new ComparadorNome());
        for(PPG iter : listaPpgs) iter.imprimeSimples();
    }

    public String getNome(){
        return this.nome;
    }

    public String getSigla() {
        return this.sigla;
    }

}