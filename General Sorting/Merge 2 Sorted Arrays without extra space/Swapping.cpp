#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void merge2sorted(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size(); int m = nums2.size();
        int left = n - 1; int right = 0;
        while(right < m && left >= 0){
            if(nums1[left] > nums2[right]){
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            } else {
                break;
            }
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
    }
};

int main(){
    Solution soln;
    vector<int> nums1 {1,4,7,8};
    vector<int> nums2 {0,3,3,4};

    soln.merge2sorted(nums1, nums2);

    cout << "NUMS1:" << endl;
    for(auto it: nums1)
        cout << it << " ";
    
    cout << endl << "NUMS1: " << endl;
    for(auto it: nums2)
        cout << it << " ";
        
    
}