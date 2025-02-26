#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxProfit(vector<int>& prices){
        int profit = 0, buy = prices[0];

        for(int i=1; i<prices.size();i++){
            if(prices[i] < buy)
                buy = prices[i];
            else
                profit = max(profit, prices[i] - buy);
        }
        return profit;
    }
};

int main(){
    Solution soln;
    vector<int> prices = {7,1,5,3,6,4};
    cout << soln.maxProfit(prices) << endl;
    return 0;
}
