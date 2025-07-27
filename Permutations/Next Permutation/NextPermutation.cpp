#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> next_permutation(vector<int> nums){
        int index = -1;

        // Function to find the "Dip Point" (first decreasing element from the right)
        for(int i=0; i<nums.size()-2; i++){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        // 2 1 5 4 3 0
        // 1 is the dip point at nums[1] < nums[2] ==> 1 < 5
        if(index == -1)
        {
             /*
                Step 2: Find the dip point in the array.
                - If no dip point is found, it means the array is in descending order
                (i.e., the last permutation), so we reverse the entire array
                to get the first permutation.
            */
            reverse(nums.begin(), nums.end());
            return nums;
        }

        /*
            Step 3: Find the smallest number (from the right side) that is 
            larger than nums[index], and swap them.
            - This ensures the permutation is the "next greater" one.
        */
        for(int i=nums.size()-1; i>index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        // 2 1 5 4 3 0 turned into
        // 2 3 5 4 1 0


        /*
            Step 4: Reverse the elements after the dip point.
            - This ensures the numbers are in the lowest possible order 
              (ascending), making it the next smallest lexicographic permutation.
        */
        reverse(nums.begin() + index + 1, nums.end());
        return nums;
        // 2 3 5 4 1 0 turned into
        // 2 3 0 1 4 5
        
    }
};

int main() {
    Solution soln;
    vector<int> nums = {2,1,5,4,3,0};
    vector<int> next = soln.next_permutation(nums);
    
    // std::next_permutation(nums.begin(), nums.end());
    for(auto x: nums)
        cout << x << " ";

    cout<< endl;
    
    for(auto x: next)
        cout << x << " ";
    return 0;
}