#include <iostream>

using namespace std;

int main(){

    bool mat[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            char c;
            cin >> c;
            mat[i][j] = (bool)(c == '#');
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            int w = 0;
            int b = 0;
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    if(mat[i+k][j+l]) b++;
                    else w++;
                }
            }
            if(w >= 3 || b >= 3){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}