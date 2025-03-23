#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int subarraySum(vector<int>& nums, int k){
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int preSum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            int remove = preSum - k;
            count += mpp[remove];
            mpp[preSum] += 1;
        }
        return count;
    }        
};

int main(){
    Solution soln;
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    int x = soln.subarraySum(nums, k);

    cout << x << " ";
}