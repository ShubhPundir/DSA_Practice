#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestSubsequence(string s){
        unordered_set<char> charSet;
        int left = 0, maxi = 0;

        for(int right = 0; right < s.length(); right++){
            if(charSet.find(s[right]) != charSet.end()){
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[left]);
            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};