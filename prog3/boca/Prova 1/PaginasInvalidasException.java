public class PaginasInvalidasException extends Exception{
    private static final long serialVersionUID = 1L;

    PaginasInvalidasException(String titulo, int pagInicial, int pagFinal) {
        super("Artigo " + titulo + " informa dados de paginas inicial-final incorretos: " + pagInicial + "-" + pagFinal);
    }
}