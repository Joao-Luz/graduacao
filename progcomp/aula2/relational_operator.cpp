#include <iostream>
#include <string>

using namespace  std;

int main(){
    int t;

    cin >> t;
    for(int i = 0; i < t; i++){
        string a, b;
        
        cin >> a >> b;

        if(a == b) cout << '=';

        else if(a[0] == '-' && b[0] != '-') cout << '<';
        else if(a[0] != '-' && b[0] == '-') cout << '>';

        else if(a[0] == '-' && b[0] == '-' && a.length() != b.length()){
            if(a.length() > b.length()) cout << '<';
            else cout << '>';
        }

        else if(a[0] != '-' && b[0] != '-' && a.length() != b.length()){
            if(a.length() > b.length()) cout << '>';
            else cout << '<';
        }

        else{
            for(int i = 0; i < a.length(); i++){
                if(a[0] != '-' && b[0] != '-'){
                    if(a[i] > b[i]){
                        cout << '>';
                        break;
                    }
                    else if(a[i] < b[i]){
                        cout << '<';
                        break;
                    }
                    else continue;
                }

                if(a[0] == '-' && b[0] == '-'){
                    if(a[i] > b[i]){
                        cout << '<';
                        break;
                    }
                    else if(a[i] < b[i]){
                        cout << '>';
                        break;
                    }
                    else continue;
                }
            }
        }

        cout << endl;
    }

    return 0;
}