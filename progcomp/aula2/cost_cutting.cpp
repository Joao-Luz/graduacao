#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        vector<int> s;
        int a, b, c;

        cin >> a >> b >> c;
        s.push_back(a);
        s.push_back(b);
        s.push_back(c);

        sort(s.begin(), s.end());

        cout << "Case " << i+1 << ": " << s[1] << endl;
        
    }

    return 0;
}