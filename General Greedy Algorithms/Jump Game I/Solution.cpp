#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // jump to the next maximum index
        int maxReach = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > maxReach) return false; // we are stuck at index i
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};

int main(){
    cout << boolalpha;
    Solution soln;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << soln.canJump(nums1) << endl;    
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << soln.canJump(nums2);
}