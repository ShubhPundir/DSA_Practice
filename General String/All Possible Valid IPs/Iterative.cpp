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
        int n = s.size();
        
        vector<string> ans;
        if(n > 12) return ans;

        for(int i = 1; i <= 3; i++){ // string part 1
            for(int j = 1; j <= 3; j++){ // string part 2
                for(int k = 1; k <= 3; k++){ // string part 3
                    // divding the s into substrings
                    if(i + j + k < n && i + j + k + 3 >= n){
                        string a = s.substr(0, i);
                        string b = s.substr(i, j);
                        string c = s.substr(i + j, k);
                        string d = s.substr(i + j + k);
                    
                        if(check(a) && check(b) && check(c) && check(d)){
                            ans.push_back(a + "." + b + "." + c + "." + d);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution soln;

    vector<string> res = soln.restoreIPAddresses("0000");
    for(auto s: res){
        cout << s << " " << endl;
    }
    if(res.empty())
        cout << "EMPTY";
    return 0;
}