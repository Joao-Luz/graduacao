#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main(){

    int n;
    cin >> n;
    int scenario = 1;

    while (n){
        
        cout << "Scenario #" << scenario << endl;

        unordered_map<int, queue<int>* > elems;
        for(int i = 0; i < n; i++){
            int qtd;
            cin >> qtd;
            queue<int>* q = new queue<int>;
            for(int j = 0; j < qtd; j++){
                int elem;
                cin >> elem;
                elems[elem] = q;
            }
        }

        queue< queue<int>* > team_queue;

        string command;
        cin >> command;
        while(command != "STOP"){
            if (command == "ENQUEUE"){
                int id;
                cin >> id;

                queue<int>* q = elems[id];
                if(q->empty()) team_queue.push(q);

                q->push(id);

            }
            else if (command == "DEQUEUE"){
                queue<int>* q = team_queue.front();

                if(q->empty()){
                    team_queue.pop();
                    q = team_queue.front();
                }

                int elem = q->front();
                q->pop();
                cout << elem << endl;
            }
            cin >> command;
        }

        cin >> n;
        cout << endl;
        scenario++;
    }
    

    return 0;
}