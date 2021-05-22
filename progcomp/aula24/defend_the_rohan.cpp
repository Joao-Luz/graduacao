#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f3f 

int floydwarshall (int graph[][50], int V, int u, int v){
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }
    return dist[u][v];
}  

int main(){
    int t; cin >> t;

    for(int i = 0; i < t; i++){
        int n; cin >> n;
        int adj[n][50];

        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                int w; cin >> w;
                adj[j][k] = w;
            }
        }

        int r; cin >> r;
        int total = 0;
        for(int j = 0; j < r; j++){
            int u, v; cin >> u >> v;
            total += floydwarshall(adj, n, u-1, v-1);
        }

        cout << "Case #" << i+1 << ": " << total << endl;
    }
}