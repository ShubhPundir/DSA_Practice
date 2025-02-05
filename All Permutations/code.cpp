#include <iostream>
#include <vector>

void backtrack(std::vector<int>& nums, int start) {
    if (start == nums.size()) {
        for (int num : nums) std::cout << num << " ";
        std::cout << std::endl;
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        std::swap(nums[start], nums[i]); // Swap to create a new permutation
        backtrack(nums, start + 1);      // Recurse with the next index
        std::swap(nums[start], nums[i]); // Backtrack
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    backtrack(nums, 0);
    return 0;
}
