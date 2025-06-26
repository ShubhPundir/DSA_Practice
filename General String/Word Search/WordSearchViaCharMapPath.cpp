#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // can start from anywhere
        // let's look at a series of starting points

        int n = board.size(); int m = board[0].size();
        // n is our number of rows
        // m is our number of columns

        function<bool(int, int, int)> backtrack = [&](int i, int j, int k){
            if(k == word.length())
                return true;
            if(i < 0 || i >= n || j <0 || j >= m || board[i][j] != word[k])
                return false;
            
            char temp = board[i][j]; // marking is as visited by temporaritly marking as null
            board[i][j] = '\0'; // null character, ascii value = 0
            if(backtrack(i+1, j, k+1) || backtrack(i-1, j, k+1) || 
            backtrack(i, j+1, k+1) || backtrack(i, j-1, k+1)){
                return true;
            }
            board[i][j] = temp;
            return false;
        };

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(backtrack(i,j,0)){
                    return true;
                }
            }
        }
        return false;

    }
};

int main(){
    Solution soln;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    cout << soln.exist(board, "ABCCED");
}