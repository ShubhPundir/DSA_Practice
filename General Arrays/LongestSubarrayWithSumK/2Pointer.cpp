#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
    int findSubarraysWithK(vector<int>& nums){
        int c = 0;
        int l = 0, r = nums.size() - 1;
        
        vector<int> preSum(nums.size(), 0);
        
        for(int i : nums){
            preSum[i] += nums[i];
        }

        while(l <= r){

        }
        

        return c;
    }
};
int main(){
    vector<int> nums = {1,2,9,3,3,1,4};
}