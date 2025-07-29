#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void counter(vector<int>& nums, int& count, int low, int mid, int high){
        // [low ... mid]
        // [mid+1 ... high]
        // for sorting take a temp array
        vector<int> temp;
        int left = low, right = mid + 1;
        while(left <= mid && right <= high){
            if(nums[left] > nums[right]){
                count += mid - left + 1;
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
    int countInversions(vector<int>& nums){
        int count = 0;
        divide(nums, count, 0, nums.size() - 1);
        return count;
    }
};

int main(){
    Solution soln;
    vector<int> nums {5, 3, 2, 4, 1};

    cout << soln.countInversions(nums);
}