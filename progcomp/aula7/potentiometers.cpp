#include <iostream>
#include <unordered_map>
#include<vector>
#include<cstdlib>

using namespace std;

#define LSOne(S) ((S) & -(S))                    // the key operation

typedef long long ll;                            // for extra flexibility
typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree {                              // index 0 is not used
private:
  vll ft;                                        // internal FT is an array
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }      // create an empty FT

  void build(const vll &f) {
    int m = (int)f.size()-1;                     // note f[0] is always 0
    ft.assign(m+1, 0);
    for (int i = 1; i <= m; ++i) {               // O(m)
      ft[i] += f[i];                             // add this value
      if (i+LSOne(i) <= m)                       // i has parent
        ft[i+LSOne(i)] += ft[i];                 // add to that parent
    }
  }

  FenwickTree(const vll &f) { build(f); }        // create FT based on f

  FenwickTree(int m, const vi &s) {              // create FT based on s
    vll f(m+1, 0);
    for (int i = 0; i < (int)s.size(); ++i)      // do the conversion first
      ++f[s[i]];                                 // in O(n)
    build(f);                                    // in O(m)
  }

  ll rsq(int j) {                                // returns RSQ(1, j)
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }

  int select(ll k) {                             // O(log m)
    int p = 1;
    while (p*2 < (int)ft.size()) p *= 2;
    int i = 0;
    while (p) {
      if (k > ft[i+p]) {
        k -= ft[i+p];
        i += p;
      }
      p /= 2;
    }
    return i+1;
  }
};

int main(){
    int n;
    cin >> n;
    int c = 1;

    while(n){
        cout << "Case " << c << ":" << endl;
        vector<ll> ptmtrs(n+1);
        FenwickTree ft(n);
        for(int i = 1; i <= n; i++){
            cin >> ptmtrs[i];
            ft.update(i, ptmtrs[i]);
        }

        string cmd;
        cin >> cmd;
        while(cmd != "END"){
            ll x, y;
            cin >> x >> y;
            if(cmd == "M"){
                cout << ft.rsq(x, y) << endl;
            }
            else if(cmd == "S"){
                ll diff = y - ptmtrs[x];
                ft.update(x, diff);
                ptmtrs[x] = y;
            }

            cin >> cmd;
        }

        cin >> n;
        if(n) cout << endl;
        c++;
    }
}