#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


class Solution {
public:
    pair<int, vector<int>> threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<int> triplets = {nums[0], nums[1], nums[2]};
        int result = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(target - sum) < abs(target - result)){
                    result = sum;
                    triplets[0]= nums[0];
                    triplets[1] = nums[l];
                    triplets[2] = nums[r];
                }
                if(sum == target)   return {result, triplets};
                else if(sum < target) l++;
                else r--;
            }
        }
        return {result, triplets};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,-1,3,9};
    auto result =  sol.threeSumClosest(nums, 2);
    cout << "Closest sum: " << result.first << endl;
    cout << "Triplet: ";
    for (int x : result.second)
        cout << x << " ";
    cout << endl;
    return 0;
}