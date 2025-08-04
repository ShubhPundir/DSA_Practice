#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        // cout << "low: " << low << endl;
        // cout << "high: " << high << endl;
        int ans = -1;

        while(low <= high){
            int capacity = low + (high - low)/2;
            int days_req = findDays(weights, capacity);
            cout << "days_req: " << days_req << " with capacity: " << capacity << endl;
            if(days_req <= days){
                ans = capacity;
                high = capacity - 1;
            } else {
                low = capacity + 1;
            }
        }
        return ans;
    }

    int findDays(const vector<int>& weights, int capacity){
        // return the number of days needed to transfer all the weight with the current capacity
        int day = 1, load = 0;

        for(int i = 0; i < weights.size(); i++){
            if(load + weights[i] > capacity){
                day = day + 1;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return day;
    }
};

int main(){
    Solution soln;
    vector<int> weights {1,2,3,4,5,6,7,8,9,10};

    cout << soln.shipWithinDays(weights, 5);
}