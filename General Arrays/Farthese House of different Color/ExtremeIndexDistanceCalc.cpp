#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        // the first color --> color[0] can be compared with all other colors to find a farthest different color from the start;
        // the last color --> color[n-1] can be compared with all other colors to find a farthest different color from the end;

        int ans1 = INT_MIN, ans2 = INT_MIN;
        int n = colors.size();

        int k = 1;
        while(k < n){
            if(colors[0] != colors[k]) ans1 = max(ans1, k);

            if(colors[k] != colors[n-1]) ans2 = max(ans2, n-k-1);

            k++;
        }
        return max(ans1, ans2);
    }
};

int main(){
    Solution sol;
    vector<int> colors = {1,1,1,1,3,312,44,1};
    int ans = sol.maxDistance(colors);
    cout << ans;
}