#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // two pointer approach
        int start = 0, end = nums.size() - 1;
        int cur = 0;
        while (cur <= end) {
            if (nums[cur] == 0) {
                swap(nums[cur], nums[start]);
                start++;
                cur++;
            } else if (nums[cur] == 1) {
                cur++;
            } else {
                swap(nums[cur], nums[end]);
                end--;
            }
        }
    }
};

int main() {
    Solution soln;
    vector<int> nums = {2, 0, 1};
    // vector<int> nums = {2, 0, 2, 1, 1, 0};
    soln.sortColors(nums);
    for (auto x : nums)
        cout << x << " ";
    return 0;
}