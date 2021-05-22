#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f3f 

typedef pair<int, int> iPair;

void addEdge(vector < pair <int, int> > adj[], int u, int v, int wt){ 
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); 
}

int shortestPath(vector<pair<int,int> > adj[], int V, int src, int dst){
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
    vector<int> dist(V, INF); 

    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()){
        int u = pq.top().second; 
        pq.pop(); 
  
        for (auto x : adj[u]){ 
            int v = x.first; 
            int weight = x.second; 
  
            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    }
    return dist[dst];
}

int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector<iPair> adj[n];
        for(int j = 0; j < m; j++){
            int a, b, w;
            cin >> a >> b >> w;
            addEdge(adj, a, b, w);
        }
        int dist = shortestPath(adj, n, s, t);
        cout << "Case #" << i+1 << ": ";
        if(dist == INF) cout << "unreachable" << endl;
        else cout << dist << endl;
    }
}