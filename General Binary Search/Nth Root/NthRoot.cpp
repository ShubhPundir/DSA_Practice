#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int poww(int mid, int n){
        long long ans = 1;
        while(n > 0){
            if(n % 2 == 1){
                ans = ans * mid;
                n = n - 1;
            } else {
                mid = mid * mid;
                n = n / 2;
            }
        }
        return int(ans);
    } // but we don't really need the actual answer, only if if == m, >= m or <= m

    int func(int mid, int n, int target){
        long long ans = 1;

        for(int i = 1; i <= n; i++){
            ans *= mid;
            if(ans > target) return 2;
        }
        if(ans == target) return 1;
        return 0;
    }
    // return 1 if == target
    // return 0 if < target
    // return 2 if > target
    int nthRoot(int target, int n){
        int ans = -1;

        int low = 1, high = target;

        while(low <= high){
            int mid = (low + high) / 2;
            // int nth = poww(mid, n);
            int midN = func(mid, n, target);

            if(midN == 1){
                ans = mid;
                high = mid - 1;
            } else if(midN == 0){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main(){
    Solution soln;
    cout << soln.nthRoot(17, 2);
}