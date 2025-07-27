#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] != 0){
                swap(nums[right], nums[left++]);
            }
        }
        // 0 1 0 3 12
        // l
        // r

        // 0 1 0 3 12, no swap, l = 0, r = 1
        // 1 0 0 3 12, swap, l = 1, r = 2
        // 1 0 0 3 12, no swap, l = 1, r = 3
        // 1 3 0 0 12, swap, l = 2, r = 4
        // 1 3 12 0 0, swap, l = 3, r = 5
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,0,3,12};
    s.moveZeroes(nums);

    for(auto i: nums){
        cout << i << " ";
    }
}