#include <iostream>
#include <vector>

using namespace std;

int main(){

  

  int n;
  cin >> n;

  while (n--){
    int o = 0;
    int t = 0;
    int qtd;
    cin >> qtd;

    while(qtd--){

      char c;
      cin >> c;
      if(c == '(') o++;
      else if(c == ')'){
        if(o > 0) o--;
        else t--;
      }
    }

    cout << -t << endl;
  }
}