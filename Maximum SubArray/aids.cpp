#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // window is of length k;
        int maxSum = 0, curSum = 0;
        for(int i = 0; i < k;i++){
            curSum += nums[i];
        }
        int n = nums.size();
        for(int i = k; i < n; i++){
            curSum = curSum + nums[i] - nums[i - k];
            maxSum = max(maxSum, curSum);
            // cout << sum << " " << i << "th run\n";
        }
        cout << maxSum << " " << k << "\n";
        return maxSum*1.0/k;
    }
};

int main(){

    Solution s;
    vector<int> nums = {1,12,-5,-6,50,3};
    cout << s.findMaxAverage(nums, 4);

    return 0;
}