#include <iostream>

using namespace std;

#define MAX(A, B) A > B ? A : B

int b[100000];
int sum, n, t;
int l;

int main(){
    
    cin >> n >> t;

    for(int i = 0, j = 0; i < n; i++){
        cin >> b[i];
        sum += b[i];
        while(sum > t){
            sum -= b[j++];
        }
        l = MAX(l, (i - j) + 1);
    }
    cout << l << endl;
    return 0;
}
