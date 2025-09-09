#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
    
    bool solve(string& s, int index, int openCount) {
        // Base cases
        if (index == s.length()) {
            return openCount == 0;
        }
        
        // Invalid case: more closing brackets than opening
        if (openCount < 0) return false;
        
        // To prevent stack overflow from too many open brackets
        if (openCount > s.length() - index) return false;
        
        // Check if this state was already computed
        if (dp[index][openCount] != -1) {
            return dp[index][openCount] == 1;
        }
        
        bool result = false;
        
        if (s[index] == '(') {
            result = solve(s, index + 1, openCount + 1);
        }
        else if (s[index] == ')') {
            result = solve(s, index + 1, openCount - 1);
        }
        else { // s[index] == '*'
            // Try all three possibilities for '*'
            result = solve(s, index + 1, openCount + 1) ||  // as '('
                    solve(s, index + 1, openCount - 1) ||  // as ')'
                    solve(s, index + 1, openCount);        // as empty
        }
        
        // Store the result in dp table (1 for true, 0 for false)
        dp[index][openCount] = result ? 1 : 0;
        return result;
    }

public:
    bool checkValidString(string s) {
        int n = s.length();
        // Initialize dp table with -1 (uncomputed)
        dp.assign(n, vector<int>(n + 1, -1));
        return solve(s, 0, 0);
    }
};

int main() {
    Solution sol;
    vector<string> testCases = {
        "(**)",     // valid - true
        "(*)",      // valid - true
        "(*))",     // valid - true
        ")(",       // invalid - false
        "(((**)",   // invalid - false
        "(()*)",    // valid - true
        "**((",     // invalid - false
        "***))"     // valid - true
    };

    for(const string& s : testCases) {
        cout << "String: " << s << " is " 
             << (sol.checkValidString(s) ? "valid" : "invalid") << endl;
    }
    return 0;
}