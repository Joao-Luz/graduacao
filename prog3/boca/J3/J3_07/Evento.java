import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

public class Evento{
    String nome;
    Date data;
    String dia_da_semana;

    public String getNome() {
        return this.nome;
    }

    public Date getData() {
        return this.data;
    }

    public String getDia_da_semana() {
        return this.dia_da_semana;
    }

    Evento(String nome, String data, Locale l){

        try {
            this.nome = nome;
            SimpleDateFormat df = new SimpleDateFormat("dd/MM/yyyy");
            this.data = df.parse(data);
            df = new SimpleDateFormat("EEEE", l);
            this.dia_da_semana = df.format(this.data).toString();
        } catch (Exception e) {
            return;
        }
    }

    
}