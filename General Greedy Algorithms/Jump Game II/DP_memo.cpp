#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int recursive(vector<int>& jumps, int index, vector<int>& dp){
        if(index >= jumps.size() - 1){
            return 0;
        }
        if(dp[index] != -1) return dp[index];

        int mini = INT_MAX;
        for(int i = 1; i <= jumps[index]; i++){         
            mini = min(mini, recursive(jumps, index + i, dp) + 1);
        }
        return dp[index] = mini;
    }
    int minJumps(vector<int>& jumps){
        vector<int> dp(jumps.size(), -1);
        int min_jumps = recursive(jumps, 0, dp);
        return min_jumps;
    }
};

int main(){
    vector<int> jumps = {2, 3, 1, 1, 4};
    Solution soln;
    cout << soln.minJumps(jumps);
}