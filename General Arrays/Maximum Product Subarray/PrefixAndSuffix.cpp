#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxProdSubarray(vector<int> nums){
        int prefix = 1, suffix = 1;
        int maxi = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            
            prefix *= nums[i];
            suffix *= nums[nums.size() - i - 1];

            maxi = max(maxi, max(prefix, suffix));
        }
        
        return maxi;
    }
};

int main(){
    vector<int> nums {-2, 3, 4, -1, 0, -2, 3, 1, 3};
    Solution soln;
    cout << "True\n";
    cout << soln.maxProdSubarray(nums);
}