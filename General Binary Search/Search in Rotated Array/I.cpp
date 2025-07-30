#include <bits/stdc++.h>
using namespace std;

// only unique values
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = (right + left)/2;
            if(nums[mid] == target){
                return mid;
            } else if (nums[left] <= nums[mid]){ // left part is sorted
                if(nums[left] <= target && target <= nums[mid]){ // target lies in sorted left part
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { // right part is sorted
                if(nums[mid] <= target && target <= nums[right]){ // target lies in sorted right part
                    left = mid + 1;
                } else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};