abstract class Quadrilateros implements Formas{

    private Double l1, l2, l3, l4;

    public Double getL1() {
        return this.l1;
    }

    public void setL1(Double l1) {
        this.l1 = l1;
    }

    public Double getL2() {
        return this.l2;
    }

    public void setL2(Double l2) {
        this.l2 = l2;
    }

    public Double getL3() {
        return this.l3;
    }

    public void setL3(Double l3) {
        this.l3 = l3;
    }

    public Double getL4() {
        return this.l4;
    }

    public void setL4(Double l4) {
        this.l4 = l4;
    }

    Quadrilateros(Double l1, Double l2, Double l3, Double l4){
        this.l1 = l1;
        this.l2 = l2;
        this.l3 = l3;
        this.l4 = l4;
    }

    @Override
    public Double calculaPerimetro(){
        return (this.l1 + this.l2 + this.l3 + this.l4);
    }
}