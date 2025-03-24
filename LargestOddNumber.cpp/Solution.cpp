#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    string largestOddNumber(string s){
        for(int i = s.size() - 1; i >=0; i--){
            if((s[i] - '0') % 2 != 0){
                return s.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main(){

    Solution soln;
    string s1 = "88443";
    string ans1 = soln.largestOddNumber(s1);

    string s2 = "874";
    string ans2 = soln.largestOddNumber(s2);

    cout << ans1 << endl;
    cout << ans2 << endl;


}