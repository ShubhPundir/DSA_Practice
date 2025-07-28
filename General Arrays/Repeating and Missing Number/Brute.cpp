#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    pair<int, int> brute(vector<int> nums, int n){
        pair<int, int> res{-1, -1};

        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] == i)
                    count++;
            }
            if(count >= 2) res.first = i;
            else if(count == 0) res.second = i;
        }

        return res;
    }
};