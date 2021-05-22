#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
    int k;
    cin >> k;

    for(int i = 0; i < k; i++){
        int n;
        cin >> n;

        unordered_map<int, int> stamps;
        vector< unordered_set<int> > collections;
        int unique_stamps = 0;
        for(int j = 0; j < n; j++){
            int m;
            cin >> m;
            unordered_set<int> collection;
            for(int l = 0; l < m; l++){
                int stamp;
                cin >> stamp;
                collection.insert(stamp);
            }
            for(auto s : collection){
                if(stamps.find(s) == stamps.end()){
                    stamps[s] = 1;
                    unique_stamps++;
                } 
                else{
                    stamps[s]++;
                    unique_stamps--;
                }
            }
            collections.push_back(collection);
        }

        cout << "Case " << i+1 << ":";
        for(auto collection : collections){
            int unique = 0;
            for(auto s : collection){
                if(stamps[s] == 1) unique++;
            }
            double share = 0;
            if(unique_stamps > 0) share = 100*(double)unique/unique_stamps;
            cout << " " << fixed << setprecision(6) << share << "%";
        }
        cout << endl;
    }
}