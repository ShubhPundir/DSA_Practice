#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int sqrt(int x){
        int low = 0;
        int high = x / 2;
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(mid*mid <= x){
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
    cout << soln.sqrt(37);

}