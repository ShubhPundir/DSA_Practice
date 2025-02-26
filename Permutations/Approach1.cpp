#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void make_permutations(vector<int>& nums, vector<int>& current, vector<vector<int>>& result){
        if(nums.size() == current.size()){
            result.push_back(current);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(find(current.begin(), current.end(), nums[i]) != current.end())
                continue;
            current.push_back(nums[i]);
            make_permutations(nums, current, result);
            current.pop_back();
        }
    }
};

int main(){
    Solution soln;
    vector<int> nums = {1,2,3};
    vector<int> current;
    vector<vector<int>> result;
    soln.make_permutations(nums, current, result);
    for(auto x: result){
        for(auto y: x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}