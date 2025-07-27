#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int All(vector<int> nums, int k){
        unordered_map<int, int> preSumMap;
        int sum = 0; 
        int maxLen = 0;
        int right = 0, left = 0;

        while(right <= nums.size()){
            while(sum > k){
                sum -= nums[left];
                left++;
            }
            if(sum == k){
                maxLen = max(maxLen, right-left+1);
            }
            right++;
            if(right < nums.size())
                sum += nums[right];
        }

        return (maxLen > 0) ? maxLen : -1;
    }
};

int main(){
    Solution obj;
    vector<int> vec = {1, 2, 3, 1, 1, 1, 4, 2, 3, 5, 3};
    int k = 10;
    int result = obj.All(vec, k);
    cout << "Length of the longest subarray with sum " << k << " is: " << result << endl;
    return 0;
}