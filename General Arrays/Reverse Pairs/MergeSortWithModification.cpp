// in sorted array limits
// [left array] and [right array]
// [6 13 21 25] and [1 2 3 4 4 5 9 11 13]
// if [1 2] from right array form a pair with 6, it will form a pair with the rest of all elements in the left array
// hence for checking with 13, we don't need to check [1 2] again, we start from 3 onwards

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void counter(vector<int>& nums, int& count, int low, int mid, int high){
        // [low ... mid]
        // [mid+1 ... high]
        // for sorting take a temp array
        vector<int> temp;
        
        // Count reverse pairs
        int rightPtr = mid + 1;
        for(int leftPtr = low; leftPtr <= mid; leftPtr++){
            while (rightPtr <= high && (long long)nums[leftPtr] > 2LL * nums[rightPtr]){ // Use long long to prevent overflow
                rightPtr++;
            }
            count += (rightPtr - (mid + 1)); // Number of elements in right half that satisfy the condition
        }
        // example:  [6 13 21 25] and [1 2 3 4 4 5 9 11 13]
        
        int left = low, right = mid + 1;
        // sort only
        while(left <= mid && right <= high){
            if(nums[left] > nums[right]){
                temp.push_back(nums[right]);
                // as [low...mid] is sorted
                right++;
            } else {
                temp.push_back(nums[left]);
                left++;
            }
        }
        
        // Copy remaining elements from left half, if any
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        // Copy remaining elements from right half, if any
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        // Copy sorted elements from temp back to original array
        for(int k = low; k <= high; k++){
            nums[k] = temp[k - low];
        }
    }
    void divide(vector<int>& nums, int& count, int low, int high){
        if(low >= high) return;
        int mid = (low + high) / 2;
        divide(nums, count, low, mid); // left half
        divide(nums, count, mid + 1, high); // right half
        counter(nums, count, low, mid, high);
    }
    int countReversePairs(vector<int>& nums){
        int count = 0;
        divide(nums, count, 0, nums.size() - 1);
        return count;
    }
};

int main(){
    Solution soln;
    vector<int> nums {40, 25, 19, 12, 9, 6, 2};

    cout << soln.countReversePairs(nums);
}