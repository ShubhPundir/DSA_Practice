#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int maxi = INT_MIN, curSum = 0;
        
        for(int i=0; i<nums.size(); i++){
            curSum += nums[i];

            maxi = max(maxi, curSum);
            
            if(curSum<0) curSum = 0;
        }

        return maxi;
    }
};

int main(){
    Solution soln;
    vector<int> nums =  {-2,-5,-4};
    //  {-2,1,-3,4,-1,2,1,-5,4};
    cout << soln.maxSubArray(nums) << endl;
    return 0;
}