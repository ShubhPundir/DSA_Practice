#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1]) {
                // We are on a decreasing slope or at a peak.
                // The peak could be 'mid' or to its low.
                high = mid;
            } else {
                // nums[mid] < nums[mid + 1]
                // We are on an increasing slope.
                // The peak must be to the high of 'mid
                low = mid + 1;
            }
        }

        return low;        
    }
};