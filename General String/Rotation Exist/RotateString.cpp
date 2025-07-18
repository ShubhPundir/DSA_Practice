#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool string_rotate(string s, string goal){
        if(s.length() != goal.length()) return false;

        if(s.empty() || goal.empty()) return true;

        string doubled_s = s + s;
        return doubled_s.find(goal) != string::npos;
    }
};

int main(){
    Solution soln;
    cout << std::boolalpha << soln.string_rotate("abc", "cab");
    return 0;
}