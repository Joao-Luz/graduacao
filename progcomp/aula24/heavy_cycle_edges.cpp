#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
#define INF 0x3f3f3f3f 

const int MAX = 1000;
int id[MAX], heavy[25000], h, n, m;
pair <long long, pair<int, int> > p[MAX];

void initialize(){
    h = 0;
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x){
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y){
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[]){
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < m;++i){
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y)){
            minimumCost += cost;
            union1(x, y);
        }
        else heavy[h++] = cost;
    }
    return minimumCost;
}

int main(){
    cin >> n >> m;
    while(n != 0 || m != 0){
        initialize();
        for(int i = 0; i < m; i++){
            int u, v, w; cin >> u >> v >> w;
            p[i] = make_pair(w, make_pair(u, v));
        }
        sort(p, p + m);
        kruskal(p);
        if(h == 0) cout << "forest" << endl;
        else{
            for(int j = 0; j < h; j++){
                cout << heavy[j];
                if(j < h-1) cout << " ";
            }
            cout << endl;
        }
        cin >> n >> m;
    }

}