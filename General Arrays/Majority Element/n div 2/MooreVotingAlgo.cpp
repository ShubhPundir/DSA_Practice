#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore voting algo
        int major = nums[0], count = 1;

        for(int i = 1; i < nums.size(); i++){
            if(count == 0){
                major = nums[i]; count = 1;
            } else if(nums[i] == major){
                count++;
            } else {
                count--;
            }
        }
        cout << "count before re initializing :" << count << endl;

        count = 0;
        for(int i: nums){
            if(i == major)
                count++;
        }
        cout << "major element: " << major << endl;
        cout << "count: " << count << endl;
        cout << "nums.size(): " << nums.size() << endl;


        return count > nums.size()/2 ? major : -1;
    }
    
    int hashMap(vector<int>& nums){
        unordered_map<int,int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]] += 1;
        }

        for(auto x: mpp){
            cout << x.first << "-" << x.second << endl;
            if(x.second > nums.size() / 2){
                return x.first;
            }
        }

        return -1;
    }
};


int main(){
    Solution soln;
    vector<int> nums {2,2,1,1,1,2,2};
    // cout << "result of funciton: " << soln.majorityElement(nums);
    cout << "result of funciton: " << soln.hashMap(nums);
}