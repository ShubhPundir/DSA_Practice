#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool recursiveCheck(string& s, int index, int openCount) {
        // Base case: reached end of string
        if (index == s.length()) {
            return openCount == 0;  // valid if all brackets are matched
        }
        
        if (s[index] == '(') {
            return recursiveCheck(s, index + 1, openCount + 1);
        }
        else if (s[index] == ')') {
            if (openCount <= 0) return false;  // no matching opening bracket
            return recursiveCheck(s, index + 1, openCount - 1);
        }
        else {  // s[index] == '*'
            // Case 1: use * as opening bracket '('
            if (recursiveCheck(s, index + 1, openCount + 1)) return true;
            
            // Case 2: use * as closing bracket ')'
            if (openCount > 0 && recursiveCheck(s, index + 1, openCount - 1)) return true;
            
            // Case 3: ignore * (treat as empty)
            return recursiveCheck(s, index + 1, openCount);
        }
    }

public:
    bool checkValidString(string s) {
        return recursiveCheck(s, 0, 0);
    }
};

int main() {
    Solution sol;
    vector<string> testCases = {
        "(**)",     // valid - true
        "(*)",      // valid - true
        "(*))",     // valid - true
        ")(",       // invalid - false
        "(((**)"    // valid - true
    };

    for(const string& s : testCases) {
        cout << "String: " << s << " is " 
             << (sol.checkValidString(s) ? "valid" : "invalid") << endl;
    }
    return 0;
}