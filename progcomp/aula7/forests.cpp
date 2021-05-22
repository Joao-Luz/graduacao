#include <iostream>
#include <sstream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    while(n-- > 0){
        int p, t;
        cin >> p >> t;

        cin.ignore();
        
        set< set<int> > opinions;
        unordered_map<int, set<int> > people;

        string line;
        while(getline(cin, line) && !line.empty()){
            stringstream s(line);
            int i, j;
            s >> i >> j;

            people[i].insert(j);
        }
        int no_opinion = 0;
        for(int i = 0; i < p && !no_opinion; i++) if(people.find(i + 1) == people.end()) no_opinion = 1;
        for(auto p : people){
            opinions.insert(p.second);
        }
        cout << opinions.size() + no_opinion << endl << (n > 0 ? "\n" : "");
    }
}