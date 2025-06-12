#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // fix first pointer, and have a 2 pointer solution for the rest of the target
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1])
                continue; // to avoid duplicates

            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                int total = nums[i] + nums[j] + nums[k];
                if(total < 0){
                    j++;
                } else if (total > 0){
                    k--;
                } else {
                    // total = 0
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(nums[j] == nums[j-1] && j < k){
                        j++;
                    }
                }

            }
        }
        return res;
    }
};
int main(){
    Solution sol;
    vector<int> res = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = sol.threeSum(res);

    for(auto r: ans){
        for(auto i: r){ 
            cout << i << " ";
        }
        cout << endl;
    }
}