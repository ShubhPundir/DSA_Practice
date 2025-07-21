#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> res;
        vector<int> subset;
        helper(0, nums, res, subset);
        return res;
    }

    void helper(int index, vector<int>& nums, vector<vector<int>>& res, vector<int>& subset){
        // to be or not to be
        // to choose the number or not to
        
        if(index == nums.size()){
            res.push_back(subset);
            return;
        }

        helper(index + 1, nums, res, subset);
        
        
        subset.push_back(nums[index]);
        helper(index + 1, nums, res, subset);
        subset.pop_back();
    }
};

int main(){

    Solution soln;
    vector<int> nums {1,2,3};
    vector<vector<int>> res = soln.subsets(nums);

    for(auto x: res){
        cout << "[";
        for(auto y: x){
            cout << y <<  ", ";
        }
        cout << "]" << endl;
    }
}