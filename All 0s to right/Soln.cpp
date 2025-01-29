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