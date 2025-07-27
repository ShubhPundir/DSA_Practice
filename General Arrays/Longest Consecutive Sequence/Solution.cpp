#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestSequence(vector<int> nums){
        int longest = 1;
        unordered_set<int> st;
        for(int num : nums){
            st.insert(num);
        }
        
        for(auto it: st){
            if(st.find(it - 1) == st.end()){ // we don't find it - 1 in the array
                // hence we starting from the element with no predecessor
                int cnt = 1; int x = it;

                while(st.find(x + 1) != st.end()){
                    // we find x + 1 in the array
                    x = x + 1;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }

        
        return longest;
    }
};

int main(){
    Solution soln;
    vector<int> nums {1,2,3,102,102,2023,103,101,100,98,99,84};
    cout << soln.longestSequence(nums);
}