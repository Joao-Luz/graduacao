import java.lang.reflect.Constructor;

public class J1_06{

    public static class Matrix{

        Constructor(int i,int j){
            this.lin = i;
            this.col = j;
            this.mat = new Double[i][j];
        }

        public void setZero(){
            for(int i = 0; i< this.lin; i++){
                for(int j = 0; j < this.col; j++){
                    this.mat[i][j] = 0;
                }
            }
        }

        public Matrix mult(Matrix m){
            result = new Matrix(this.lin, m.col);

            result.setZero();
            
            for (int i = 0; i < result.lin; i++) {
                for (int j = 0; j < result.col; j++) {
                    for (int k = 0; k < this.col; k++) {
                        result.mat[i][j] += this.mat[i][k] * m.mat[k][j];
                    }
                }
            }
            return result;
        }
    }

    public static void main(String[] args) {
        
    }
}