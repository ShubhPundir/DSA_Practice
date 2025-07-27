#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countGoodNumbers(long long n){
        // definition of a good number is 
        // even place indices must be even numbers
        // odd place indices must be prime numbers
        long long even = (n + 1) / 2; // allowed are 2,4,6,8
        long long odd = n / 2; // allowed are 2,3,5,7
        long long mod = 1e9 + 7;

        return (int)((helper(5, even, mod) * helper(4, odd, mod) ) % mod );
        // ways to fill even position * ways to fill odd position
        // way to fill any position = (choices of numbers present) * (places to fill)
    }
private:
    long long helper(int base, int expo, int mod){
        long long ans = 1;
        while(expo > 0){
            if(expo % 2 == 0){
                expo /= 2;
                base = base * base;
            } else {
                expo--;
                ans = base * ans;
            }
        }

    }
};
int main(){
    Solution soln;
    int n = 4;
    cout << soln.countGoodNumbers(n);
}