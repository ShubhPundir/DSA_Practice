#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void merge2sorted(vector<int> nums1, vector<int> nums2){
        // we take extra space lol
        int n = nums1.size() + nums2.size();
        vector<int> nums3{n, 0};
        
        int idx1 = 0, idx2 = 0, idx3 = 0;
        while(idx1 < nums1.size() && idx2 < nums2.size()){
            if(nums1[idx1] <= nums2[idx2]){
                nums3[idx3] = nums1[idx1];
                idx1++; idx3++;
            } else {
                nums3[idx3] = nums2[idx2];
                idx2++; idx3++;
            }
        }
        while(idx1 < nums1.size()){
            nums3[idx3++] = nums1[idx1++];
        }
        while(idx2 < nums2.size()){
            nums3[idx3++] = nums2[idx2++];
        }

        for(int i = 0; i < n ; i++){
            if(i < nums1.size()) nums1[i] = nums3[i];
            else nums2[i - nums1.size()] =  nums3[i];
        }
    
    }
};

int main(){
    Solution soln;
}