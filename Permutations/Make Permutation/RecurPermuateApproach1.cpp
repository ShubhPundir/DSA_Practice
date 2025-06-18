#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void recurPermute(vector<int>& soFar, vector<int>& nums, vector<vector<int>>& ans, int freq[]){
        if(soFar.size() == nums.size()){
            ans.push_back(soFar);
            return;
        }
        for(int i = 0 ; i < nums.size(); i++){
            if(freq[i] == 0){
                soFar.push_back(nums[i]);
                freq[i] = 1; // mark as visited
                recurPermute(soFar, nums, ans, freq); // goes into the DFS tree
                freq[0] = 0; // unmark
                soFar.pop_back(); // unmark
            }
        }
    }
    public:
    vector<vector<int>> permute(vector<int> &nums){
        vector<vector<int>> ans;
        vector<int> soFar;
        int freq[nums.size()];
        for (int i = 0; i < nums.size(); i++)
            freq[i] = 0;
        recurPermute(soFar, nums, ans, freq);
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,3};
    obj.permute(nums);
}