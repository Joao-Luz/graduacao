#include <iostream>

using namespace std;

int g[1000];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> g[i];
    }

    int max = -1;
    for(int i = 0; i < n; i++){
        int l = 1;
        int ant = g[i];
        for(int k = i - 1; k > -1; k--){
            if(g[k] <= ant) l++;
            else break;
            ant = g[k];
        }
        ant = g[i];
        for(int k = i + 1; k < n; k++){
            if(g[k] <= ant) l++;
            else break;
            ant = g[k];
        }
        if(l > max) max = l;
    }

    cout << max << endl;
}
