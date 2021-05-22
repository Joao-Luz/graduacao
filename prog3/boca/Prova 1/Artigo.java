public class Artigo{

    private String tipo;
    private int tipo_id;
    private String titulo;
    private int pagInicial;
    private int pagFinal;
    private String veiculo;
    private String qualis;
    private int qtdPags;
    private boolean validade;

    public Artigo(String tipo, String titulo, int pagInicial, int pagFinal, String veiculo, String qualis){
        this.tipo = tipo;
        this.tipo_id = converteTipo();
        this.titulo = titulo;
        this.pagInicial = pagInicial;
        this.pagFinal = pagFinal;
        this.veiculo = veiculo;
        this.qualis = qualis;
        try {
            this.qtdPags = validaPags();
            this.validade = true;
        } catch (PaginasInvalidasException e) {
            this.qtdPags = 0;
            this.validade = false;
            System.out.println(e.getMessage());
        }
    }

    private int validaPags() throws PaginasInvalidasException{
        int qtdPags = this.pagFinal - this.pagInicial + 1;
        if(qtdPags < 0 || qtdPags > 50) throw new PaginasInvalidasException(this.titulo, this.pagInicial, this.pagFinal);
        return qtdPags;
    }

    private int converteTipo(){
        if(this.tipo.equals("trabalhoCompletoEmCongresso")) return 1;
        if(this.tipo.equals("resumoExpandidoEmCongresso") || this.tipo.equals("resumoEmCongresso")) return 2;
        if(this.tipo.equals("artigoEmPeriodico")) return 3;
        return -1;
    }

    public String getTipo() {
        return this.tipo;
    }

    public String getTitulo() {
        return this.titulo;
    }

    public int getPagInicial() {
        return this.pagInicial;
    }

    public int getPagFinal() {
        return this.pagFinal;
    }

    public String getVeiculo() {
        return this.veiculo;
    }

    public String getQualis() {
        return this.qualis;
    }

    public int getTipo_id(){
        return this.tipo_id;
    }

    public int getQtdPags(){
        return this.qtdPags;
    }

    public boolean valido(){
        return this.validade;
    }

}