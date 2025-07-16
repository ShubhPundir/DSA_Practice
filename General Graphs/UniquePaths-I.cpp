#include <bits/stdc++.h>
using namespace std;

class Solution{
    int countPaths(int i, int j, int n, int m, vector<vector<int>>& dp){
        if(i == (n - 1) && j == (m - 1)) return 1;
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1) 
            return dp[i][j];
        else
            dp[i][j] = countPaths(i + 1, j, n, m, dp) + countPaths(i, j + 1, n, m, dp) ;
    }
    public: int uniquePaths(int n, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int num = countPaths(0, 0, n, m, dp);
        return num;
    }
};

int main(){
    Solution soln;
    int count = soln.uniquePaths(3,7);
    cout << count;
}