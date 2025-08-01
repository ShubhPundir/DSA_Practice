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
    }
    int nthRoot(int target, int n){
        int ans = -1;

        int low = 1, high = target;

        while(low <= high){
            int mid = (low + high) / 2;
            int nth = poww(mid, n);

            if(nth <= target){
                ans = mid;
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
    cout << soln.nthRoot(16, 2);
}