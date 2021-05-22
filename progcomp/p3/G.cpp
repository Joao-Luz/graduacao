#include <iostream>
#include <vector>

using namespace std;

int c[100000];
int m;
int total;
vector<int> adj[100000];

void dfs(int v, int pr, int cats){
    if(cats > m) return;
    int rest = 1;

    for(int i = 0; i < adj[v].size(); i++){
        if(adj[v][i] != pr){
            rest = 0;
            int cat = c[adj[v][i]];
            dfs(adj[v][i], v, cats*cat + cat);
        }
    }
    total+=rest;
}

int main(){
    int n; cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, c[0]);
    cout << total << endl;
}