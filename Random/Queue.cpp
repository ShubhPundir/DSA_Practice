#include <queue>
#include <iostream>
using namespace std;

void showQ( queue<int> Q){
    // queue<int> copy = const_cast<queue<int>>(Q);
    queue<int> copy = Q;

    while(!copy.empty()){
        cout << "\t" << copy.front();
        copy.pop();
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    showQ(q);
}