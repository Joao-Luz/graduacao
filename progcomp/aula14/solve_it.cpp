#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double p, double q, double r, double s, double t, double u, double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main(){
    int p, q, r, s, t, u;
    cin >> p >> q >> r >> s >> t >> u;
    while(cin){
        double lo = 0.0;
        double hi = 1.0;
        double er = 0.0000001;
        int it = 100;
        bool found = false;

        while (it--){
            double x = (hi - lo)/2 + lo;
            double res = f(p, q, r, s, t, u, x);
            if(res < -er){
                hi = x;
                continue;
            }
            else if(res > er){
                lo = x;
                continue;
            }
            else if(res <= er && res >= -er){
                cout << setprecision(4) << fixed <<  x << endl;
                found = true;
                break;
            }
            
        }
        if(!found) cout << "No solution" << endl;
        cin >> p >> q >> r >> s >> t >> u;
    }
    return 0;
}