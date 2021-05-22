#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int tab[8][8];

#define INF 0x3f3f3f3f 

typedef pair<int, int> iPair;

void add_edge(vector < pair <int, int> > adj[], int u, int v, int wt){ 
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); 
}

int dijkstra(vector<pair<int,int> > adj[], int V, int src, int dst){
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

void build_graph(vector<pair <int, int>> adj[], int i, int j){
    if(i+1 < 8 && j-2 > 0){
        add_edge(adj, i*j+j, (i+1)*(j-2)+j-2, i*(i+1)+j*(j-2));
        build_graph(adj, i+1, j-2);
    }
    if(i+2 < 8 && j-1 > 0){
        add_edge(adj, i*j+j, (i+2)*(j-1)+j-1, i*(i+2)+j*(j-1));
        build_graph(adj, i+2, j-1);
    }
    
    if(i+2 < 8 && j+1 < 8){
        add_edge(adj, i*j+j, (i+2)*(j+1)+j+1, i*(i+2)+j*(j+1));
        build_graph(adj, i+2, j+1);
    }

    if(i+1 < 8 && j+2 < 8){
        add_edge(adj, i*j+j, (i+1)*(j+2)+j+2, i*(i+1)+j*(j+2));
        build_graph(adj, i+1, j+2);
    }

    if(i-1 > 0 && j-2 > 0){
        add_edge(adj, i*j+j, (i-1)*(j-2)+j-2, i*(i-1)+j*(j-2));
        build_graph(adj, i-1, j-2);
    }
    if(i-2 > 0 && j-1 > 0){
        add_edge(adj, i*j+j, (i-2)*(j-1)+j-1, i*(i-2)+j*(j-1));
        build_graph(adj, i-2, j-1);
    }
    if(i-2 > 0 && j+1 < 8){
        add_edge(adj, i*j+j, (i-2)*(j+1)+j+1, i*(i-2)+j*(j+1));
        build_graph(adj, i-2, j+1);
    }
    if(i+1 < 8 && j+2 < 8){
        add_edge(adj, i*j+j, (i+1)*(j+2)+j+2, i*(i+2)+j*(j+2));
        build_graph(adj, i+1, j+2);
    }
}

int main(){

    int a, b, c ,d;
    cin >> a >> b >> c >> d;
    while(cin){
        vector<iPair> adj[64];
        build_graph(adj, a, b);
        int cost = dijkstra(adj, 8, a*b + b, c*d + d);
        if(cost == INF) cout << -1 << endl;
        else cout << cost << endl;
        cin >> a >> b >> c >> d;
    }

}