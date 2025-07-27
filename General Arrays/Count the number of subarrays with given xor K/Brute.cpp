#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countXORSubarrays(vector<int> nums, int k){
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int xorr = 0;
            for(int j = i; j < nums.size(); j++){
                xorr = xorr ^ nums[j];
                if(xorr == k){
                    count ++ ;
                }
            }
        }

        return count;
    }

};

int main(){
    vector<int> nums {4, 2, 2, 6, 4};
    // 4 XOR 2 = 6 as 100 XOR 010 gives 110 --> 6
    // count all subarrays like this
    Solution soln;
    cout << soln.countXORSubarrays(nums, 6); // should return 4
}