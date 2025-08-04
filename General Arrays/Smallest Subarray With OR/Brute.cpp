#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ans(nums.size());

        for(int i = 0; i < nums.size(); i++){
            int orMax = 0;
            int orCur = 0;
            // step 1: Find the maximum possible bitwise OR for subarrays starting at i
            for(int j = i; j < nums.size(); j++){
                orCur = orCur | nums[j];
            }
            orMax = orCur;

            // step 2: finding the smallest length that comes closest to the maximum possible OR
            int current_or_for_length = 0;
            for (int j = i; j < nums.size(); ++j) {
                current_or_for_length |= nums[j];
                if (current_or_for_length == orMax) {
                    ans[i] = (j - i + 1); // Length of the subarray
                    break; // Found the smallest length
                }
            }
        }

        return ans;
    }
};

int main(){
    vector<int> nums{1,0,2,1,3};
    Solution soln;
    vector<int> ans = soln.smallestSubarrays(nums);
    for(auto a: ans){
        cout << a << " ";
    }

    return 0;
}