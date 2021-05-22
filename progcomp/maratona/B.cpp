#include <iostream>

using namespace std;

int mat[10][10];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int d, l, r, c;
        cin >> d >> l >> r >> c;

        if(d){
            if(c + l - 1 > 9 || c < 0) cout << "N" << endl;
            for(int j = c; j < c + l - 1; j++) mat[r][j] = 1;
        }
        else{
            if(r + l - 1 > 9 || r < 0) cout << "N" << endl;
            for(int j = r; j < r + l - 1; j++) mat[j][c] = 1;
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(mat[i][j] >= 2) cout << "N" << endl;
        }
    }
    cout << "Y" << endl;
}