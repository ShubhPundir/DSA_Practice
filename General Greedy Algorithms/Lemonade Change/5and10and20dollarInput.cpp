#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int b5 = 0, b10 = 0;

        for(auto ele: bills){
            if (ele == 5) b5++;
            else if (ele == 10){
                if(b5 > 1){
                    b5--; b10++;
                } else {
                    return false;
                }
            } else {
                // ele = 20
                if(b5 >= 1 && b10 >= 1){
                    b5--; b10--;
                } else if(b5 >= 3 && b10 == 0){
                    b5 -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;

    }
};