#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &nums){
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for(int num: numSet){
            if(numSet.find(num+1) == numSet.end()){
                // did not find a num+1 in the set
                // starting from reverse
                int len = 1;
                while(numSet.find(num-len) != numSet.end()){
                    // num - len is found in the set
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};

int main()
{
    Solution s;
    vector<int> arr{100, 4, 200, 3, 2, 1};
    int max = s.longestSubsequence(arr);
    cout << max << endl;
}
