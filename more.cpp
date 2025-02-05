#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int left = 0, currSum = 0;

        for(int right=0; right<nums.size(); right++){
            currSum += nums[right];
            
            while(currSum >= target){
                if(right - left + 1 < minLen)
                    minLen = right - left + 1;
                
                currSum -= nums[left];
                left++;
            }
        }

        return minLen != INT_MAX ? minLen : 0;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,3,1,2,4,3};
    s.minSubArrayLen(7, nums);
    return 0;
}
