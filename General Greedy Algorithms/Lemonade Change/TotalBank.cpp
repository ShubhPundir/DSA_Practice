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
            }
        }
        return true;
    }

};

