#include <iostream>

using namespace std;

int sum_dig(int num){
    int sum = 0;
    while(num > 0){
        sum += num%10;
        num /= 10;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int num = 10;
    for(int i = 0; i < n; i++){
        num+=9;
        while(sum_dig(num) != 10) num+=9;
    }
    cout << num << endl;
}