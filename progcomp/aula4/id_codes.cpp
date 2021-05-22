#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int colCount[100];

int main(){

    string code;
    cin >> code;
    while (code != "#"){
        
        bool done = false;
        vector< pair<char, int> > seen;
        for(int i = code.length() - 1; i >= 0; i--){
            for(auto s : seen){
                if(s.first > code[i]){
                    int idx = s.second;
                    char aux = code[i];
                    code[i] = code[idx];
                    code[idx] = aux;

                    sort(code.begin() + i + 1, code.end());
                    done = true;
                    break;
                } 
            }
            if(done) break;

            seen.push_back(make_pair(code[i], i));
        }
        if(done) cout << code << endl;
        else cout << "No Successor" << endl;

        cin >> code;
    }
    

    return 0;
}