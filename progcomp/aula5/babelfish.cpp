#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

int main(){
    char s[100];

    unordered_map<string, string> dict;
    while(scanf("%[^\n ]%*c", s) == 1){
        string word = s;
        scanf("%s%*c", s);
        string translate = s;

        dict[translate] = word;
    }
    
    string word;
    cin >> word;
    while(cin){
        if(dict.find(word) == dict.end()) cout << "eh" << endl;
        else cout << dict[word] << endl;

        cin >> word;
    }
    return 0;
}