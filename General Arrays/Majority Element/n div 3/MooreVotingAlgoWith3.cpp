#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> boyer_moore (vector<int>& nums) {
        // could use hashmaps but not feasible withing O(1) space
        int major1 = 0, major2 = 0, count1 = 0, count2 = 0;

        for(int num: nums){
            if(num == major1)
                count1++;
            else if (num == major2)
                count2++;
            else if (count1 == 0){
                major1 = num;
                count1++;
            } else if (count2 == 0){
                major2 = num;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;

        for(int num: nums){
            if(num == major1)
                count1++;
            else if(num == major2)
                count2++;
        }

        vector<int> res;
        if(count1 > nums.size() / 3)
            res.push_back(major1);
        if(count2 > nums.size() / 3){
            res.push_back(major2);
        }

        return res;
    }
};

int main(){
    Solution soln;
    vector<int> nums {1,2,1,3,2,1,3,3,2,2,1,2};
    int num1 = -1, num2 = -1;
    vector<int> res = soln.boyer_moore(nums);
    if(res.size() == 2)
        cout << res[0] << ", " << res[1] << endl;  
    
    if(res.size() == 1)
        cout << res[0] << endl;  

    if(res.size() == 0)
        cout << "NO MAJORITY ELEMENT" << endl;    
    return 0;
}