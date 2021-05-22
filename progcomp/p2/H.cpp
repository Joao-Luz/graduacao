#include <iostream>

using namespace std;

int res[100000];

int main(){
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == s[i-1]) sum++;
        res[i] = sum;
    }

    int n; cin >> n;

    while(n-->0){
        int li, ri; cin >> li >> ri;
        cout << (res[ri-1] - res[li-1] )<< endl;
    }
}