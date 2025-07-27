#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<string> generate(int n){
        vector<string> result;
        helper(n, 0, result, "");
        return result;
    }

    void helper(int n, int i, vector<string>& result, string curr){
        if(i == n){
            result.push_back(curr);
            return;
        }
        
        helper(n, i + 1, result, curr + '0');
        
        helper(n, i + 1, result, curr + '1');
    }
};

int main(){
    Solution soln;
    int n = 3;
    vector<string> binaryStrings = soln.generate(n);
    cout << "Hello" << endl;
    for(auto s: binaryStrings){
        cout << s << "\n";
    }

    return 0;
}