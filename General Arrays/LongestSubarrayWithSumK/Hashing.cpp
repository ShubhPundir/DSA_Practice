#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution{
    public:
    int findSubarraysWithK(vector<int>& nums, int k){
        int len = 0;
        unordered_map<int,int> mpp;
        int preSum = 0;
        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            mpp[preSum] = i; // prefix Sum is still i;

            if(preSum == k)
                len = max(len, i);
            if(mpp.find(preSum - k) != mpp.end())
                len = max(len, i - mpp[preSum - k]);
            else
                mpp[preSum] = i;
        }

        return (len > 0) ? len : -1;
    }
};
int main(){
    vector<int> nums = {1,2,3,1,1,1,1,4,2,3};
    Solution sol;
    cout << sol.findSubarraysWithK(nums,3); 
}