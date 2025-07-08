#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> grid;
    vector<vector<string>> result;

    bool QueenCanPlaced(int row, int col, int n) {
        // check column
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 'Q') return false;
        }

        // check left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j] == 'Q') return false;
        }

        // check right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (grid[i][j] == 'Q') return false;
        }

        return true;
    }

    void helper(int row, int n) {
        if (row == n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                string res = "";
                for (int j = 0; j < n; j++) {
                    res += grid[i][j];
                }
                temp.push_back(res);
            }
            result.push_back(temp);
            return;
        }


        for (int col = 0; col < n; col++) {
            if (QueenCanPlaced(row, col, n)) {
                grid[row][col] = 'Q';
                helper(row + 1, n);
                grid[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        grid.resize(n, vector<char>(n, '.'));
        helper(0, n);
        return result;
    }
};

int main(){
    int n = 4;
    Solution soln;
    vector<vector<string>> res = soln.solveNQueens(n);

    for(auto x: res){
        for(auto s: x){
            cout << s << endl;
        }
        cout << "-------\n";
    }
}