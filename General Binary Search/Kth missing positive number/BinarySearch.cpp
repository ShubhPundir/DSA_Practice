#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int bs(vector<int>& nums, int k){
        int n = nums.size() - 1;

        int low = 0, high = n - 1;

        while(low <= high){
            int mid = (low + high) / 2;
            int missing = nums[mid] - (mid + 1);
            if(missing < k){
                low = mid + 1;
            } else { 
                high = mid - 1;
            }
        }
        // till the end of this loop, it terminates and high and low are interchanged
        // high ... low
        // low = high + 1

        // return nums[high] + more
        // return nums[high] + (k - missing)
        // return nums[high] + (k - (nums[high] - high - 1))
        // return k + high + 1
        // can be k + low as well see Ln 21
        // as low crosses high
        return high + k + 1;
    }
};