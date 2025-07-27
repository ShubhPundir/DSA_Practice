#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            if(mpp.find(sum - k) != mpp.end()){
                count += mpp[sum - k];
            }
            mpp[sum]++;
        }
        return count;
    }
};
int main(){

    Solution soln;
    vector<int> nums {1,2,3};
    int k = 3;
    cout << soln.subarraySum(nums, k);
}