#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n != 0){

        priority_queue<int, vector<int>, greater<int> > p_queue;

        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            p_queue.push(a);
        }

        int cost = 0;
        while(!p_queue.empty()){
            int a = p_queue.top();
            p_queue.pop();
            int b = p_queue.top();
            p_queue.pop();
            cost += (a + b);
            if(!p_queue.empty()) p_queue.push((a+b));
        }

        cout << cost << endl;

        cin >> n;
    }
}