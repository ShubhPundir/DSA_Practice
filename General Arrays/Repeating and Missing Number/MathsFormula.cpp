#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    pair<int, int> mathsFormula(vector<int> nums, int n){
        pair<int, int> res{-1, -1};
        // summation of first n natural numbers = n * (n + 1) / 2
        // summation of squares first n natural numbers =  n * (n + 1) * (2 * n + 1) / 6

        long long SN = (n * (n + 1) ) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1) )/ 6;
        // S - Sn = x - y
        // S2 - S2n = x2 - y2;

        long long S = 0, S2 = 0;
        for(auto num: nums){
            S += (long long) (num);
            S2 += (long long) (num * num);
        }
        int val1 = S - SN; // x - y
        int val2 = S2 - S2N;
        val2 = val2 / val1; // x + y

        res.first = (val1  + val2 )/ 2;
        res.second = res.first - val1;
        return res;
    }
};