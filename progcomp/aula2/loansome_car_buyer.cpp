#include <iostream>

using namespace std;

int main(){

	int t, r;
	double dp, l;
	cin >> t >> dp >> l >> r;

	while(t > 0){

		double p = l / t;
		double val = dp + l;

		double m, dep, ldep, lm;
		cin >> m >> dep;

		ldep = dep;
		lm = m;

		val -= val * ldep;

		bool done = false;
		if(l < val){
			cout << "0 months" << endl;
			done = true;
		}

		lm++;

		for(int i = 0; i < (r - 1); i++){
			cin >> m >> dep;

			if(!done){
				for(int j = lm; j < m; j++){
					val -= val * ldep;
					l -= p;

					if(l < val){
						cout << j << (j == 1 ? " month" : " months") << endl;
						done = true;
						break;
					}
				}
			}

			lm = m;
			ldep = dep;
		}

		if(!done){
			for(int i = lm; i <= t; i++){
				val -= val * ldep;
				l -= p;

				if(l < val){ 
					cout << i << (i == 1 ? " month" : " months") << endl;
					break;
				}
			}
		}
		
		cin >> t >> dp >> l >> r;
	}
	return 0;
}