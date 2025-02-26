#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> next_permutation(vector<int> nums){
        int index = -1;
        for(int i=0; i<nums.size()-2; i++){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1)
        {
            reverse(nums.begin(), nums.end());
            return nums;
        }  
        for(int i=nums.size()-1; i>index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end());
        return nums;
        
        
    }
};

int main() {
    Solution soln;
    vector<int> nums = {2,1,5,4,3,0};
    vector<int> next = soln.next_permutation(nums);
    
    next_permutation(nums.begin(), nums.end());
    for(auto x: nums)
        cout << x << " ";

    cout<< endl;
    
    for(auto x: next)
        cout << x << " ";
    return 0;
}