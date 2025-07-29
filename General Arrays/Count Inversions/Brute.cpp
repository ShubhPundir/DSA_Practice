#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countInversions(vector<int>& nums){
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] > nums[j])
                    count++;
            }
        }

        return count;
    }
};

int main(){
    Solution soln;
    vector<int> nums {5, 3, 2, 4, 1};

    cout << soln.countInversions(nums);
}