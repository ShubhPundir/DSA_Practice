#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for(int i = 1; i <= s.size(); i++){
            // Check two conditions:
            // 1. start >= 0: Ensures that the potential starting position of 'w' is valid (not negative).
            // 2. dp[start]: Checks if the substring from s[0...start-1] (i.e., the part of 's'
            //    before the current word 'w') can itself be segmented into dictionary words.
            // 3. s.substr(start, w.length()) == w: Checks if the substring of 's' from 'start'
            //    with the length of 'w' is actually equal to the word 'w'.
            for(const string& w: wordDict){
                int start = i - w.length();
                if(start >= 0 && dp[start] && s.substr(start, w.length()) == w){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main(){
    Solution soln;
    cout << soln.wordBreak("leetcode", {"leet", "tc", "code"});

}