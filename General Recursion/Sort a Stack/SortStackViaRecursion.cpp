#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    void insertCorrect(stack<int>& s, int elem){

        if(s.empty() || s.top() < elem){
            s.push(elem);
            return;
        }


        int temp  = s.top(); s.pop();
        insertCorrect(s, elem);
        s.push(temp);

    }

    void sort(stack<int>& s){
        // logic is to take out the last element and sort the rest of the stack
        // yep THIS IS THE LEAP OF FAITH we take in recursion
        // and then we insert the top element in the correct place
        
        int topElem = s.top(); s.pop();

        sort(s);

        insertCorrect(s, topElem);
    
    }
};

int main(){
    stack<int> s;
    s.push(51);
    s.push(10);
    s.push(0);
    s.push(-10);
    s.push(34);

    Solution soln;
    soln.sort(s);
}