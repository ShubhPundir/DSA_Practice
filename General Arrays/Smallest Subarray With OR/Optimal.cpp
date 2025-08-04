#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> smallestSubarrays(vector<int> nums){
        vector<int> ans(nums.size());
        // We initialize a vector nearest of size 32 to -1, 
        // representing the most recent position where each bit was set (from the right).
        // We iterate from right to left (n - 1 to 0) so we can build nearest for every bit as we move.
        vector<int> nearest(32, -1);


    }
};

int main(){

}