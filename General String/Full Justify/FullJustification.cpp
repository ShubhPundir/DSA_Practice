#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // each word's length <= maxWidth and >=0
        
        int n = words.size();
        vector<string> ans;
        int i = 0;

        while(i < n){
            int j = i;
            int lineLen = 0, totalChars = 0;

            while(j < n && lineLen + words[j].length() + (j-i) <= maxWidth){
                lineLen += words[j].length();
                totalChars += words[j].length(); // this does not constitute the gaps
                j++;
            } // j - i represents the number of words 
            
            int spaces = maxWidth - totalChars; // total spaces to distribute
            int gaps = j - i - 1; // no. of gaps
            string line = "";

            if(j == n || gaps == 0){
                for(int k = i; k < j; k++){
                    line += words[k];
                    if(k != j - 1) // condition except for last word
                        line += " "; // adding a single space between words
                }
            
                while(line.size() < maxWidth)
                    line += " ";
            } else {
                int spaceEach = spaces / gaps;
                int extra = spaces % gaps;
                
                for(int k = i; k < j; k++){
                    line += words[k];
                    if(k != j - 1){
                        // condition except for last word
                        int toAdd = spaceEach + (extra > 0 ? 1 : 0);
                        line += string(toAdd, ' ');
                        if(extra > 0) extra--;
                    }
                }
            }
            ans.push_back(line);
            i = j; // jump to next line
        }

        return ans;
    }
};

int main(){
    Solution soln;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> justified = soln.fullJustify(words, 16);

    for(auto line : justified){
        cout << line << endl;
    }
}