#include <iostream>

using namespace std;

string sheet[999][18278];

void resolve(string s){

    s = s.substr(1);
    int res = 0;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find("+")) != std::string::npos) {
        token = s.substr(0, pos);

        

        s.erase(0, pos + 1);
    }

}

int main(){

    int n; cin >> n;

    for(int i = 0; i < n; i++){

        int l, c; cin >> l >> c;
        for(int j = 0; j < l; j++){
            for(int k = 0; k < c; k++){
                cin >> sheet[j][k];
            }
        }

        for(int j = 0; j < l; j++){
            for(int k = 0; k < c; k++){
                if(sheet[j][k][0] == '=') resolve(sheet[j][k]);
                else cout << sheet[j][k] << " ";
            }
        }
    }




}