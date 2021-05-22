#include <iostream>

using namespace std;

#define MAX(A, B) A > B ? A : B

int res[101];


int main(){
    res[0] = 100;
    int n, max = 100;
    cin >> n;

    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        res[i+1] = res[i] + c;
        max = MAX(res[i+1], max);
    }
    cout << max << endl;
}