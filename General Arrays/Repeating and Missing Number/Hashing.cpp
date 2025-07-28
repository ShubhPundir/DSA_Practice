#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    pair<int, int> hashing(vector<int> nums, int n){
        pair<int, int> res{-1, -1};
        vector<int> hash (6, 0);

        for(int i = 0; i < n; i++){
            hash[nums[i]]++;
        }

        for(int i = 0; i < n; i++){
            if(hash[i] >= 2) res.first = hash[i];
            else if(hash[i] == 0) res.second = hash[i];
        }

        return res;
    }
};