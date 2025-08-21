#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int pow(int x, int n) {
        int ans = 1;
        while(n > 0){
            if(n % 2 == 0){
                x = x * x;
                n = n / 2;
            }
            if(n % 2 == 1){
                ans = x * ans;
                n = n - 1; 
            }
        }
        return ans;
    }
};

int main(){
    Solution soln;
    cout << soln.pow(2,10);
}