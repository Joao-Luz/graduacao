#include <iostream>
#include <random>

using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    
    double av = 0.0;
    int t = 10000000;
    for(int i = 0; i < t; i++){
        int qtd = 0;
        double sum = 0.0;
        while(sum < n){
            int r = rand()%(b+1) + a;
            sum += r;
            qtd++;
        }
        av += (double)qtd/t;
    }
    cout << av << endl;
    
}