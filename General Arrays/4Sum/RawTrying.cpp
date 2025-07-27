#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i = 0; i < nums.size() - 3; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates of i
            for(int j = i + 1; j < nums.size() - 2; j++){
                if (j > i + 1 && nums[j] == nums[j-1]) continue; // skip duplicates of j                
                
                int l = j + 1;
                int r = nums.size() - 1;
                
                // two pointer
                while(l < r){
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum > target){
                        r--;
                    } else if(sum < target){
                        l++;
                    } else {
                        // sum = target
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++; r--;
                        while(l < r && nums[l] == nums[l - 1]) l++;
                        while(l < r && nums[r] == nums[r - 1]) r--;
                    }
                }
            }
        }

        return result;
    }
};

int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    // post sort = {-2,-1,0,0,1,2}
    // solutions --> [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    Solution soln;
    vector<vector<int>> res = soln.fourSum(nums, 0);

    for(auto arr : res){
        for(auto i: arr)
            cout << i << " ";
        cout << endl;
    }
    
}