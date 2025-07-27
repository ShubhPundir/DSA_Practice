#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countXORSubarrays(vector<int> nums, int k){
        int count = 0;
        unordered_map<int, int> prefixXOR;
        int xr = 0;
        prefixXOR[xr] = 1; // {0, 1}

        for(int i = 0; i < nums.size(); i++){
            xr = xr ^ nums[i];
            int x = xr ^ k;
            count += prefixXOR[x];
            prefixXOR[xr]++;
        }
        return count;
    }
};

int main(){
    vector<int> nums {4, 2, 2, 6, 4};
    // 4 ^ 2 = 6 as 100 ^ 010 gives 110 --> 6
    // count all subarrays like this
    // a ^ a = 0
    // a ^ 0 = a
    
    // if x ^ k = xr
    // x ^ k ^ k = xr ^ k
    // x = xr ^ k
    Solution soln;
    cout << soln.countXORSubarrays(nums, 6); // should return 4
}