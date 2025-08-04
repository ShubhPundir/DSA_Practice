#include <bits/stdc++.h>
using namespace std;

// find out when the (minimum distance between cows  ) are maximum
//                   (this only happens when adjacent)
// first and  last cows should be put on the extremes
// 0th index, nth index


// intuition: place cows on the basis of minimum distance between last set cow is at least x, where x is starting from 1 to ...
//            here, all the cows will have minimum distance between them at least x


// max possible answer: maximum distance between any two adjacnet barns --> (max - min) --> [barns[n-1] - barns[0]]. IDEAL FOR 2 COWS

class Solution{
    bool canWePlace(const vector<int>& barns, int cows, int dist){
        int cntCows = 1, last = barns[0];

        for(int i = 1; i < barns.size(); i++){
            if(barns[i] - last >= dist){
                cntCows++;
                last = barns[i];
            }
        }
        if(cntCows >= cows) return true;
        
        return false;
    }
public:
    int aggresiveCowsLinear(vector<int>& barns, int cows){
        sort(barns.begin(), barns.end());
        int maxi = INT_MIN, mini = INT_MAX;
        int high = barns.back() - barns.front();
        int ans = -1;

        for(int i = 1; i < high; i++){
            if(canWePlace(barns, cows, i) == true){
                ans = i;
            } else {
                ans = i - 1;
                break;
            }
        }
        cout << ans << endl;

        return 1;
    }
    int aggressiveCowsBS(vector<int>& barns, int cows) {
        // Sort the barn positions to easily check distances
        sort(barns.begin(), barns.end());

        int low = 1;
        int high = barns.back() - barns.front();
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canWePlace(barns, cows, mid)) {
                // If we can place all cows with this distance,
                // it might be our answer. We try for a larger distance.
                ans = mid;
                low = mid + 1;
            } else {
                // If we can't place all cows, the distance is too large.
                // We need to try a smaller distance.
                high = mid - 1;
            }
        }
        cout << ans << endl;
        return ans;
    }
};
int main(){
    vector<int> barns {0,3,4,7,9,10};
    Solution soln;
    cout << "LINEAR SEARCH ANSWER\n";
    soln.aggresiveCowsLinear(barns, 4);
    cout << "====================\nBINARY SEARCH ANSWER"  << endl;
    soln.aggressiveCowsBS(barns, 4);
}
