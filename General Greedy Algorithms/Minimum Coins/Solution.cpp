#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minCoins(const vector<int> coins, int value){
        vector<int> result;
        for(int i = coins.size() - 1; i >= 0; i--){
            while (value >= coins[i]){
                value -= coins[i];
                result.push_back(coins[i]);
            }
        }
        for(auto i: result){
            cout << " " << i;
        }
        cout << endl;
        return result.size();
    }
};

int main(){
    Solution soln;
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    cout << soln.minCoins(coins, 50);

}