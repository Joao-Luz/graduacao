#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    while(cin){
        int n, m;
        cin >> n >> m;
        unordered_map<int, vector<int> > indices;

        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            indices[a].push_back(i);
        }

        while(m --> 0){
            int k, v;
            cin >> k >> v;
            if(indices.find(v) == indices.end()){
                cout << 0 << endl;
                continue;
            }
            vector<int> index = indices[v];
            if(k > index.size()){
                cout << 0 << endl;
                continue;
            }
            cout << index[k-1] + 1 << endl;
        }
    }
    
}