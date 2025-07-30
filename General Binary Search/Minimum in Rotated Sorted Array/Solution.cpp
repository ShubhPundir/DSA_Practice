#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimum(vector<int> nums){
        int low = 0, high = nums.size() - 1;

        // ONLY UNIQUES in nums
        // the sorted half may or may not have the answer
        // leftmost element in the sorted is always the minimum
        int mini = INT_MAX;
        while (low <= high){
            int mid = low - (low - high) / 2;
            if(nums[low] <= nums[mid] && nums[mid] <= nums[high]){
                mini = min(mini, nums[low]);
                // entire array is sorted
            }
            if(nums[low] <= nums[mid]){
                // left is the sorted array
                // [low ... mid]
                mini = min(mini, nums[low]);
                low = mid + 1; // eliminate the rest poriton of the array
            } else {
                // right is the sorted array
                // [mid ... high]
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }
    
        return mini;
    }
};

int main(){
    Solution soln;
    vector<int> nums {4,5,6,7,9,10,12,15,16,18,-3,0,3};
    cout  << "ANS: " << soln.minimum(nums);
    return 0;
}