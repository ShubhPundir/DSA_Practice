#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int greedySplit(int n) {
    if (n == 1) return 0; // Can't split further

    if(dp[n] != -1) return dp[n];

    int a = n / 2;
    int b = n - a;

    return dp[n] =  a * b + greedySplit(a) + greedySplit(b);
}

int main(){
    dp.assign(20+1,-1);
    cout << greedySplit(20);
}