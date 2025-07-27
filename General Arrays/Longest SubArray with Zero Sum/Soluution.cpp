#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestWithZero(vector<int>& nums){
        int maxi = 0;
        unordered_map<int, int> mpp; // this is for prefix sum
        // key is the sum and value is the position till we have found the said sum
        int sum = 0; // the sum so far
        
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0){
                maxi++;
            } else if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi, i - mpp[sum]);
            } else {
                mpp[sum] = i;
            }
        }

        return maxi;
    }
};

int main(){
    Solution soln;
    vector<int> nums {9, -3, 3, -1, 6, -5};
    int x = soln.longestWithZero(nums);
    cout << x;
}