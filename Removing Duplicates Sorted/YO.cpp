#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int n = nums.size();

        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                cout << i << ":" << nums[i] << endl;
                nums[k] = nums[i];
                k++;
            }
        }
        cout << "------------------------\n";
        return k;
    }
};
int main(){
    Solution s;
    //                   i
    //                   k
    vector<int> vec = {0,0,1,1,1,2,2,3,3,4};
    int k =  s.removeDuplicates(vec);
    cout << k << endl;

    for(int i = 0; i < k; i++){
        cout << vec[i] << " ";
    }

}