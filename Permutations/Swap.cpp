#include <bits/stdc++.h>
using namespace std;

void permute(vector<int>& nums, int idx, int r) {
    if (idx == r) {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        for (int i = idx; i <= r; i++) {
            swap(nums[idx], nums[i]);
            permute(nums, idx + 1, r);
            swap(nums[idx], nums[i]); // backtrack
        }
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    permute(nums, 0, nums.size() - 1);
    return 0;
}