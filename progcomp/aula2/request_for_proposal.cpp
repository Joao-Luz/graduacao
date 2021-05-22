#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){

    int requirements, proposals;
    scanf(" %d %d", &requirements, &proposals);

    int rfp = 1;

    while(requirements != 0 && proposals != 0){
        double max_compliance = -1;
        double min_price = -1;
        string best_name;
        for(int i = 0; i < requirements; i++) scanf(" %*[^\n]\n");

        string name;
        for(int i = 0; i < proposals; i++){
            
            double price;
            int requirements_met;
            getline(cin, name);
            scanf(" %lf %d", &price, &requirements_met);

            cout << name;

            double compliance = (double)requirements_met / requirements;

            if(compliance > max_compliance){
                max_compliance = compliance;
                min_price = price;
                best_name = name;
            }
            else if (compliance == max_compliance){
                if(price < min_price || min_price == -1){
                    max_compliance = compliance;
                    min_price = price;
                    best_name = name;
                }
            }
            
            for(int j = 0; j < requirements_met; j++) scanf(" %*[^\n]\n");

        }

        cout << "RFP #" << rfp << endl << best_name << endl << endl;

        rfp++;
        scanf(" %d %d", &requirements, &proposals);
    }
	
}