#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());

        vector<int> count(maxValue - minValue + 1, 0);

        for (int num : nums) {
            count[num - minValue]++;
        }

        int remaining = k;
        for (int i = count.size() - 1; i >= 0; i--) {
            remaining -= count[i];

            if (remaining <= 0) {
                return i + minValue;
            }
        }

        return -1; // This line should not be reached        
    }
};
