#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0 ;
        // 0th and last index are neither hill nor valley
        // adjacent should not be equal when comparing

        int left = 0;

        for(int i = 1; i < nums.size() - 1; i++){
            if(nums[i] != nums[i+1]){
                if((nums[i] > nums[left] && nums[i] > nums[i + 1]) || 
                   (nums[i] < nums[left] && nums[i] < nums[i + 1])) {
                    count++;
                }
                left = i;
            }
        }
        return count;
    }
};


int main(){
    vector<int> nums {2,4,1,1,6,5};
    // vector<int> nums {6,6,5,5,4,1};
    Solution soln; cout << soln.countHillValley(nums);
    return 0;

}