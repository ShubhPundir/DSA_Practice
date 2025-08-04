#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = high;
        // guaranteed to be an answer
        while(low <= high){
            int mid = low + (high - low) / 2;
            int sum = 0;
            for(auto num: nums){
                sum += (num + mid - 1) / mid; // ceil operation
                // or sum += ceil(num * 1.0 / mid * 1.0). but num/mid should return a float answer 
            }
            if(sum <= threshold){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};