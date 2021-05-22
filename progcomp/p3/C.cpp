#include <iostream>
#include <vector>

using namespace std;

int gov[10000];
vector<int>adj[10000];
int v[10000];
int connected;

void dfs(int u){
    connected++;
    v[u]=1;
    for(int i=0; i<adj[u].size(); i++){
        if(!v[adj[u][i]]) dfs(adj[u][i]);
    }
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        cin >> gov[i];
    }

    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int max_c = 0;
    int total = 0;
    int total_edge = 0;
    for(int i = 0; i < k; i++){
        connected = 0;
        dfs(gov[i]);
        max_c = max(max_c, connected);
        total += connected;
        total_edge += (connected * (connected - 1))/2;
    }
    n = n - total + max_c;
    total_edge = total_edge - ((max_c * (max_c-1))/2) + (n*(n-1))/2;
    total_edge -= m;

    cout << total_edge << endl;
}