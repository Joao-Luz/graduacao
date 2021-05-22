#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n>> k;
        long long p = n * (k/(n-1));
        int r = k % (n-1);
        if(r != 0)
            cout << p+r << endl;
        else
            cout << p-1 << endl;
    }
    return 0;
}