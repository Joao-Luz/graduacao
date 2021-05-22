#include <iostream>

#define STAY_HOME 500001

using namespace  std;

int main(){

    int n, b, h, w;
    cin >> n >> b >> h >> w;

    while(cin){

        int min = STAY_HOME;

        for(int i = 0; i < h; i++){
            int p;
            cin >> p;

            bool available = false;
            for(int j = 0; j < w; j++){
                int a;
                cin >> a;
                if(a >= n) available = true;
            }
            if(!available) continue;

            if(p * n > b) continue;

            if(p < min) min = p;
        }
        if(min == STAY_HOME) cout << "stay home" << endl;
        else cout << min * n << endl;

        cin >> n >> b >> h >> w;
    }
    
    return 0;
}