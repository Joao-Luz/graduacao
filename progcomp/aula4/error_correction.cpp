#include <iostream>

using namespace std;

int colCount[100];

int main(){

    int n;
    cin >> n;
    
    while(n){
        for(int i = 0; i < n; i++) colCount[i] = 0;
        int errCol = -1;
        int errLin = -1;

        bool corrupt = false;

        for(int i = 0; i < n; i++){
            
            int linCount = 0;
            for(int j = 0; j < n; j++){
                int v;
                cin >> v;
                if(v){
                    linCount++;
                    colCount[j]++;
                }
                
                if(i == (n-1) && colCount[j] % 2 != 0){
                    if(errCol != -1) corrupt = true;
                    else errCol = j;
                }
            }
            
            if(linCount % 2 != 0){
                if(errLin != -1) corrupt = true;
                else errLin = i;
            }
        }

        if(corrupt) cout << "Corrupt" << endl;
        else if(errCol == -1 && errLin == -1) cout << "OK" << endl;
        else cout << "Change bit (" << errLin + 1 << "," << errCol + 1 << ")" << endl;

        cin >> n;
    }

    return 0;
}