#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

string lowerString(string s){
    string lower;
    lower.assign(s);
    for(int i = 0; i < s.length(); i++){
        lower[i] = tolower(lower[i]);
    }

    return lower;
}

int main(){

    string s;
    getline(cin, s);

    unordered_map<string, int> ignore;
    while(s != "::"){
        ignore[s] = 1;
        getline(cin, s);
    }

    map<string, int> keywords;
    vector<string> titles;
    getline(cin, s);
    while (cin){
        int pos;
        titles.push_back(lowerString(s));
        int i = 0;
        string cpy;
        cpy.assign(s);
        while((pos = cpy.find(" ")) != string::npos){
            string w = cpy.substr(0, pos);
            if(ignore.find(lowerString(w)) == ignore.end()) keywords[lowerString(w)] = 1;
            cpy.erase(0, pos + 1);
        }
        if((ignore.find(lowerString(cpy)) == ignore.end())) keywords[lowerString(cpy)] = 1;
        getline(cin, s);
    }

    for(auto keyword : keywords){
        for(auto title : titles){
            int pos;
            int last = 0;
            string aux;
            aux.assign(title);
            while((pos = lowerString(aux).find(keyword.first, last)) != string::npos){
                for(int i = 0; i < keyword.first.length(); i++){
                    aux[i + pos] = toupper(aux[i + pos]);
                }
                last = pos + 1;
                cout << aux << endl;
                aux.assign(title);
            }
        }
    }

    return 0;
}