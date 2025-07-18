#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isIsomorphic(string s, string t){
        if(s.length() != t.length()) return false;

        vector<int> indexS (128, 0); // like a hashmap for count of 128 valid ascii characters and their count
        vector<int> indexT (128, 0);

        for(int i = 0; i < s.length(); i++){
            if(indexS[s[i]] != indexT[t[i]]){
                return false;
                // check if the pattern of code is matching so far
            }

            indexS[s[i]] = i + 1;
            indexT[t[i]] = i + 1;
        }

        return true;
    }
};

int main(){
    Solution soln;
    cout << boolalpha << soln.isIsomorphic("amvaa","12311");
}