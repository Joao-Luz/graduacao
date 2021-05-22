#include <iostream>

using namespace std;

int main(){
    string s;
    string hello = "hello";
    char ant = 0;
    cin >> s;
    int k = 0;
    for(int i = 0; i < s.length() - 5; i++){
        if(s[i] == ant || ant == 0) continue;
        else if(s[i] == hello[k]) k++;
        else break;
        ant = s[i];
    }
    if(k == 6) cout << "YES" << endl;
    else cout << "no" << endl;

    return 0;
}