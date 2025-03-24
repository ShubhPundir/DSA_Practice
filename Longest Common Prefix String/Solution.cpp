#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string> arr){
        string any = arr[0];
        string prefix = "", tryPrefix = "";
        for(int i = 0; i < any.size(); i++){
            tryPrefix += any[i];
            // try if prefix exists for all strings inside the array
            for(string s: arr){
                if(s.substr(0, i+1) != tryPrefix){
                    return prefix;
                }
            }
            prefix = tryPrefix;
        }
        return prefix;
    }
};

int main(){

    Solution soln;

    vector<string> arr = {"flower", "flow", "fly"};
    string ans = soln.longestCommonPrefix(arr);

    cout << ans << endl;


}