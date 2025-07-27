#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    vector<string> generateParentheses(int n){
        vector<string> res;
        // logic is to start with the opening Parentheses and then closing

        // DRY RUN with n = 2
        dfs(0, 0, "", n, res);
        return res;
    }
    void dfs(int openP, int closeP, string s, int n, vector<string>& res){
        if(openP == closeP && openP + closeP == n * 2){
            res.push_back(s);
            return; // one path of tree covered
        }

        if(openP < n){
            // add all opening parentheses
            dfs(openP + 1, closeP, s + "(", n, res);
        }
        if(closeP < openP){
            dfs(openP, closeP + 1, s + ")", n, res);
        }
    }

};

int main(){
    Solution sol;
    int n = 2;
    vector<string> res = sol.generateParentheses(n);
    for(string s: res){
        cout << s << " , "; 
    }
    
}