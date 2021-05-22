#include <iostream>

using namespace std;

int main(){

    int c1, c2, r1, r2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    int mat[2][2];

    for(int i = 1; i < 10; i++){
        mat[0][0] = i;
        for(int j = 1; j < 10; j++){
            if(j == i) continue;
            mat[1][0] = j;
            for(int k = 1; k < 10; k++){
                if(k == j || k == i) continue;
                mat[0][1] = k;
                for(int l = 1; l < 10; l++){
                    if(l == j || l == i || l == k) continue;
                    mat[1][1] = l;

                    if(mat[0][0] + mat[1][0] == c1 &&
                       mat[0][1] + mat[1][1] == c2 &&
                       mat[0][0] + mat[0][1] == r1 &&
                       mat[1][0] + mat[1][1] == r2 &&
                       mat[0][0] + mat[1][1] == d1 &&
                       mat[0][1] + mat[1][0] == d2
                       ){
                           cout << mat[0][0] << " " << mat[0][1] << "\n" << mat[1][0] << " " << mat[1][1] << endl;
                           return 0;
                       }
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}