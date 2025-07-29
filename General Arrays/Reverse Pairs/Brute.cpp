#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countReversePairs(vector<int>& nums){
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] > 2 * nums[j])
                    count++;
            }
        }

        return count;
    }
};

int main(){
    Solution soln;
    vector<int> nums {40, 25, 19, 12, 9, 6, 2};

    cout << soln.countReversePairs(nums);
}