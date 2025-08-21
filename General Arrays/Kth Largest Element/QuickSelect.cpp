#include <bits/stdc++.h>
using namespace std;

class Solution{
    /*
        Quickselect is a selection algorithm to find the 
        k-th smallest (or k-th largest) element in an unordered list. 
        It's a variation of the Quicksort algorithm. 
        Instead of sorting both partitions, Quickselect only recursively calls itself 
        on the partition that contains the desired element.
    
        1: Choose a pivot: Select an element from the array (e.g., the last element).
        2: Partition: Rearrange the array such that elements smaller than the pivot are to its left, 
        and elements greater than the pivot are to its right. The pivot will be at its final sorted position.
        3: Compare:
            If the pivot's index is n - k (for k-th largest), you've found your element.
            If the pivot's index is less than n - k, the k-th largest element is in the right partition.
            If the pivot's index is greater than n - k, the k-th largest element is in the left partition.
        Recurse: Apply the process to the relevant sub-array.
    */
private:
    int partition(vector<int> nums, int left, int right){
        int pivot = nums[right];
        int i = left;
        
        for(int j = left; j < right; j++){
            if(nums[j] < pivot){
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[right]);
        return i;
    }
public:
    int findKLargest_quickselect(vector<int> nums, int k){
        int left = 0;
        int right = nums.size() - 1;
        // the kth largest element will be at index (n - k) if the array were sorted in ASC order
        int target_index = nums.size() - k;

        while(left <= right){
            int pivotIndex = partition(nums, left, right);
            
            if(pivotIndex == target_index)
                return nums[target_index];
            else if (pivotIndex < target_index){
                left = pivotIndex + 1;
            } else {
                right = pivotIndex - 1;
            }
        }
    }

};

int main(){

}