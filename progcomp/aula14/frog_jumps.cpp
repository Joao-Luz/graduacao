#include <iostream>
#include <sstream>

using namespace std;

#define MAX(A, B) A > B ? A : B

int t;
char c;
int m = 1;

int main(){
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        stringstream ss(s);
        int count = 1;
        ss.get(c);
        while(ss){
            if(c == 'R'){
                m = MAX(m, count);
                count = 1;
            }
            else if(c == 'L'){
                count++;
            }
            ss.get(c);
        }
        m = MAX(m, count);
        cout << m << endl;
        m = 1;
    }
    return 0;
}
