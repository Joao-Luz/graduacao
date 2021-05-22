#include <iostream>

using namespace std;

int check_palindrome(string s){
    int same = 2;
    char last = s[0];
    for(int i = 0; i <= s.length()/2; i++){
        if(s[i] != s[s.length() -1 - i]) return 0;
        if(s[i] != last) same = 1;
    }
    return same;
}


int main(){
    string s;

    cin >> s;
    if(s.length() == 1){
        cout << 0 << endl;
        return 0;
    }
    int r = check_palindrome(s);
    if(r == 0) cout << s.length() << endl;
    else if(r == 1) cout << s.length() - 1 << endl;
    else if(r == 2) cout << 0 << endl;
    return 0;
    
}
