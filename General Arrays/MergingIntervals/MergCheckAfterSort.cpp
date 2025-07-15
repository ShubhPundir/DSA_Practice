#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        // {{1,3}, {1,7}, {2,6}, {2,10}, {4,9}, {5,8}}
        for(int i = 0; i < nums.size(); i++){
            if(ans.empty() || nums[i][0] > ans.back()[1]){
                // no overlap or cold start
                ans.push_back(nums[i]);
            } else {
                // overlap
                ans.back()[1] = max(ans.back()[1], nums[i][1]);
            }
        }    
        return ans;
    }
};

int main(){
    Solution solm;
    vector<vector<int>> nums = {{1, 3}, {2, 6}, {5, 8}, {2, 10}, {1, 7}, {4, 9}};
    
    vector<vector<int>> ans = solm.merge(nums);
    for(auto a: ans){
        for(auto i: a){
            cout << i << "-";
        }
        cout << ",";
    }
    


}