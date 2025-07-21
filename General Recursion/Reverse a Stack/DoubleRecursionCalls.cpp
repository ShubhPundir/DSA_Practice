#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void printStack(stack<int> s){
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
    void insertAtBottom(stack<int>& st, int topElement){
        if(st.empty()){
            st.push(topElement);
            return;
        }

        int temp = st.top();
        st.pop();
        insertAtBottom(st, topElement);
        st.push(temp);
    }
    void reverseStack(stack<int>& st){
        if(st.empty())
            return;
        
            
        // recursion step: Pop the top, reverse the rest of the stack 
        // and then insert original at the bottom

        int topElement = st.top(); st.pop();
        reverseStack(st);
        insertAtBottom(st, topElement);
    }
};

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    Solution soln;
    cout << "Printing stack before any operations: \n";
    soln.printStack(st);

    soln.reverseStack(st);

    cout << " Printing stack after any operations: \n";
    soln.printStack(st);

}