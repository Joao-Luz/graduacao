#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int main(){
    int t;
    cin >> t;

    while(t != 0){
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < t; i++){
            int x, y;
            cin >> x >> y;

            if(x == n || y == m) cout << "divisa";
            else if(x > n && y > m) cout << "NE";
            else if(x > n && y < m) cout << "SE";
            else if(x < n && y < m) cout << "SO";
            else if(x < n && y > m) cout << "NO";

            cout << endl;

        }

        cin >> t;
    }

    
    return 0;
}