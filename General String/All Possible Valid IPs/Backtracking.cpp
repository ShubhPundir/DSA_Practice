#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool check(string s){
        if(s.size() == 1) return true;

        if(s[0] == '0' || s.size() > 3) return false;

        if(stoi(s) > 255) return false;

        return true;
    }
    vector<string> restoreIPAddresses(string s){
        vector<string> ans;
        backtrack(0, 0, "", s, ans);
        return ans;
    }
    void backtrack(int start, int dots, string current, string s , vector<string>& ans){
        int n = s.length();

        if(dots == 4){
            if(start == n)
                ans.push_back(current.substr(0, current.length() - 1));
            return;
        }

        if(start == n)
            return;

        for(int i = 1;  i <=3; i++){

            if(start + i > n)
                break;

            string sub = s.substr(start, i);
            if(check(sub)){
                backtrack(start + i, dots + 1, current + sub + ".", s, ans);
            }
        }
    }
};

int main(){
    Solution soln;
    vector<string> res = soln.restoreIPAddresses("25525511202");

    for(auto s: res){
        cout << s << endl;
    }

}