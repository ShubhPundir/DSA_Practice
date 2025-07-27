#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        
        priority_queue<int> pq(nums.begin(), nums.end());
        int maxa = 0;

        while(!pq.empty()){
            int temp = pq.top(); pq.pop();
            if(pq.empty()) break;
            maxa = max(maxa, temp - pq.top());
        }
        return maxa;

    }
};

int main(){
    Solution soln;
    vector<int> nums = {3,6,9,1};
    cout << soln.maximumGap(nums);
}