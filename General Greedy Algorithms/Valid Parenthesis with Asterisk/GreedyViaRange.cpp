#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool function(string s){
        int min = 0, max = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                min += 1; max += 1;
            } else if(s[i] == ')'){
                min -= 1; max -= 1;
            } else {
                if(min - 1 < 0){
                    min = min - 0;
                } else {
                    min = min - 1;
                }

                max += 1;
            }
            if(min < 0) min = 0;
            if(max < 0) return false;
        }

        return (min == 0);
    }
};


int main(){
    Solution sol;
    vector<string> testCases = {
        "(**)",     // valid - true
        "(*)",      // valid - true
        "(*))",     // valid - true
        ")(",       // invalid - false
        "(((**)"    // invalid - false
    };

    for(const string& s : testCases){
        cout << "String: " << s << " is " 
             << (sol.function(s) ? "valid" : "invalid") << endl;
    }
    return 0;
}
