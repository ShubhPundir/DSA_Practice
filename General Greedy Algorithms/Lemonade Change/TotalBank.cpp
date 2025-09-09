#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bank = 0;
        for(int i = 0; i < bills.size(); i++){
            int change = bills[i] - 5;
            if(bank < change){
                return false;
            } else {
                bank += bills[i] - change;
                // bank += bills[i] - bills[i] + 5;
            }
        }
        return true;
    }

};

int main(){
    Solution soln;
    cout << boolalpha;
    vector<int> bills = {5, 10, 5, 20};
    cout << soln.lemonadeChange(bills);
}