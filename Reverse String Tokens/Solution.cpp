#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    vector<string> tokenizeString(string s){
        vector<string> result;
        string temp;
        for(auto c: s){
            if(c == ' '){
                result.push_back(temp);
                temp = "";
                continue;
            }
            temp +=c;
        }

        result.push_back(temp);
        return result;
    }
    string reverseWords(string s){
        
    }
};

int main(){

    string s = "THis is a string .";
    Solution soln;
    vector<string> arr = soln.tokenizeString(s);

    for(auto a: arr) cout << a << endl;


}