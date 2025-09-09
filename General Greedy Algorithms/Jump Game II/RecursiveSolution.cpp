#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int recursive(vector<int>& jumps, int index){
        if(index >= jumps.size() - 1){
            return 0;
        }

        int mini = INT_MAX;
        for(int i = 1; i <= jumps[index]; i++){         
            mini = min(mini, recursive(jumps, index + i) + 1);
            
        }
        return mini;
    }
    int minJumps(vector<int>& jumps){
        int min_jumps = recursive(jumps, 0);
        return min_jumps;
    }
};

int main(){
    vector<int> jumps = {2, 3, 1, 1, 4};
    Solution soln;
    cout << soln.minJumps(jumps);
}