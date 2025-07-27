#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    static vector<string> possibleWords(string s){
        vector<string> res;
        
        if(s.empty())
            return res;

        unordered_map<char,string> digits2Letters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        dfs(0, digits2Letters, "", res, s);

        return res;
    }
    // dfs(start_index, digitMap, combinationString)
    static void dfs(int index, unordered_map<char,string> digits2Letters, string comb, vector<string>& res, string s){
        if(index == s.size()){
            res.push_back(comb);
            return;
        }

        string letters = digits2Letters.at(s[index]);

        for(char letter: letters){
            dfs(index + 1, digits2Letters, comb + letter, res, s);
        }
    }
};

int main(){
    string s = "23";
    vector<string> words = Solution::possibleWords(s);
    for(string word: words){
        cout << word << endl;
    }
}