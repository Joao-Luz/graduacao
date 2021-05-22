#include <iostream>
#include <set>

using namespace std;

char palmat[40][40];
set<int> mat[40][40];
int l, c;

int in(string s, char car, int* check){
    for(int i = 0; i < s.length(); i++){
        if(check[i]) continue;
        if(car == s[i]){
            check[i] = 1;
            return 1;
        }
    }
    return 0;
}


void checklines(string pal, int idx){
    int len = pal.length();

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            
            //vertical
            bool incol = true;
            int check[40] = {0};
            for(int k = 0; k < len; k++){
                if(k + i > l) {incol = false; break;};
                if(!in(pal, palmat[i+k][j], check)){
                    incol = false;
                    break;
                }
            }
            if(incol){
                for(int k = 0; k < len; k++){
                    mat[i+k][j].insert(idx);
                }
            }

            //horizontal
            bool inrow = true;
            int check1[40] = {0};
            for(int k = 0; k < len; k++){
                if(k + j > c) {inrow = false; break;};
                if(!in(pal, palmat[i][j+k], check1)) inrow = false;
            }
            if(inrow){
                for(int k = 0; k < len; k++){
                    mat[i][j+k].insert(idx);
                }
            }

            //diagonald
            bool india = true;
            int check2[40] = {0};
            for(int k = 0; k < len; k++){
                if(k + j > c || k + i > l) {india = false; break;};
                if(!in(pal, palmat[i+k][j+k], check2)) india = false;
            }
            if(india){
                for(int k = 0; k < len; k++){
                    mat[i+k][j+k].insert(idx);
                }
            }


            //diagonale
            bool indiae = true;
            int check3[40] = {0};
            for(int k = 0; k < len; k++){
                if(j - k < 0 || i + k > l){indiae = false; break;};
                if(!in(pal, palmat[i+k][j-k], check3)) indiae = false;
            }
            if(indiae){
                for(int k = 0; k < len; k++){
                    mat[i+k][j-k].insert(idx);
                }
            }
        }
    }
}

int main(){

    cin >> l >> c;

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cin >> palmat[i][j];
        }
    }


    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string pal;
        cin >> pal;
        checklines(pal, i);
    }

    
    int sum = 0;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(mat[i][j].size() > 1){
                sum++;
            }
        }
    }
    cout << sum << endl;
}