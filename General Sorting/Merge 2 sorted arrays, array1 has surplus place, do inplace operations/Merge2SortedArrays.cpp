#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void merge2sortedArrays(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int nidx = n - 1;
        int midx = m - 1;
        int right = m + n - 1;

        while(right >= 0){
            if(nums1[midx] > nums2[nidx]){
                nums1[right] = nums1[midx];
                midx--;
            } else {
                nums1[right] = nums2[nidx];
                nidx--;
            }
            right--;
        }
        
    }
};

int main(){
    Solution soln;
    vector<int> nums1 = {1,2,5,0,0,0};
    vector<int> nums2 = {2,3,6};

    soln.merge2sortedArrays(nums1, 3, nums2, 3);

    for(auto i: nums1)
        cout << i << " ";
    cout << endl;
    return 0;
}