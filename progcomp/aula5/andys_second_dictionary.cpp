#include <iostream>
#include <set>

using namespace std;

int main(){
    char s[201];
    int idx = 0;

    set<string> words;
    char c;
    cin.get(c);
    while(cin){
        bool make_word = false;
        while((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            make_word = true;
            s[idx] = tolower(c);
            idx++;
            cin.get(c);
            if(c == '-'){
                cin.get(c);
                if(c == '\n') cin.get(c);
                else{
                    s[idx] = '-';
                    idx++;
                }
            }
        }
        if(make_word){
            s[idx] = '\0';
            string word = s;
            words.insert(word);
            idx = 0;
        }
        cin.get(c);
    }

    for(auto w : words){
        cout << w << endl;
    }
}