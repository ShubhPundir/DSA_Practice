#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int Hashing(vector<int> nums, int k){
        unordered_map<int, int> preSumMap;
        int sum = 0; 
        int maxLen = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(sum == k) {
                maxLen = max(maxLen, i + 1);
            }

            int rem = sum - k;
            if(preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            if(preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum] = i;
            }
        }
        return (maxLen > 0) ? maxLen : -1;
    }
};

int main(){
    Solution obj;
    vector<int> vec = {1, 2, 3, 1, 1, 1, 4, 2, 3, 5, 3};
    int k = 10;
    int result = obj.Hashing(vec, k);
    cout << "Length of the longest subarray with sum " << k << " is: " << result << endl;
    return 0;
}