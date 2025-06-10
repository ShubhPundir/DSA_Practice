#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<int> searchRangeLinear(vector<int> nums, int target){
        // nums is sorted ascendingly

        int start = -1; int end = -1;
        for(int i = 0; i < nums.size(); i++){
            if(start == -1 && nums[i] == target){
                start = i;
            } else if(nums[i] == target){
                end = i;
            }
        }
        return {start,end};
    }
    vector<int> searchRangeLog(vector<int> nums, int target){
        vector<int> result = {-1, -1};
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        result[0] = left;
        result[1] = right;
        return result;
    }

    int binarySearch(vector<int> nums, int target, bool leftSearching){
        int l = 0; int r = nums.size() - 1;
        int idx = -1;

        while(l <= r){
            int mid = l + (r - l)/2;
            
            if(nums[mid] > target){
                r = mid - 1;
            } else if(nums[mid] < target){
                l = mid + 1;
            } else{
                idx = mid;
                if(leftSearching)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return idx;
    }
};

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    Solution sol;
    vector<int> x = sol.searchRangeLog(nums, 8);
    cout << x[0] << ","<< x[1] << endl;
}