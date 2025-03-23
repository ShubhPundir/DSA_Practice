#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void check(string s){
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(!st.empty() && st.top() == '(' && s[i] == ')'){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        if(st.empty()){
            cout << "Valid Parentheses";
        } else {
            cout << "Invalid Parentheses";
        }
    }
};

int main(){
    Solution soln;
    string s = "(()())";
    soln.check(s); 
}