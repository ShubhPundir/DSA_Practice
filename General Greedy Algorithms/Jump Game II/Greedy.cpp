#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minJumps(vector<int>& jumps){
        // do not create individual calls, rather create a range with number of min jumps, one can come at the place
        int jump = 0, l = 0, r = 0;
        while(r < jumps.size() - 1){
            int farthest = 0;
            for(int i = l; i < r + 1; i++){
                farthest = max(farthest, jumps[i] + i);
            }
            
            l = r + 1; r = farthest;
            jump++;
        }
        return jump;
    }
};

int main(){
    vector<int> jumps = {2, 3, 1, 1, 4};
    Solution soln;
    cout << soln.minJumps(jumps);
}