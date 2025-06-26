#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int x, int y, int m, int n)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    void dfs(vector<vector<char>>& board, string &word, int index, vector<vector<int>> &vis, bool &flag, int x, int y)
    {
        if(index == word.length() - 1)
        {
            flag = true;
            return;
        }
        int m = board.size();
        int n = board[0].size();
        vis[x][y] = 1;
        if(isValid(x+1, y, m, n) && board[x+1][y] == word[index + 1] && !vis[x+1][y])
            dfs(board, word, index + 1, vis, flag, x+1, y);
        if(isValid(x-1, y, m, n) && board[x-1][y] == word[index + 1] && !vis[x-1][y])
            dfs(board, word, index + 1, vis, flag, x-1, y);
        if(isValid(x, y+1, m, n) && board[x][y+1] == word[index + 1] && !vis[x][y+1])
            dfs(board, word, index + 1, vis, flag, x, y+1);
        if(isValid(x, y-1, m, n) && board[x][y-1] == word[index + 1] && !vis[x][y-1])
            dfs(board, word, index + 1, vis, flag, x, y-1);
        vis[x][y] = 0;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size();
        int n = board[0].size();
        bool flag = false;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(flag)
                    return true;
                if(board[i][j] == word[0])
                    dfs(board, word, 0, vis, flag, i, j);
            }
        }
        return flag;
    }
};

int main(){
    Solution soln;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    cout << soln.exist(board, "ABCCED");
}