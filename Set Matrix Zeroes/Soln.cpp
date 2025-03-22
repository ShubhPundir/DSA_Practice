#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void solve(vector<vector<int>>& nums){
        int rows = nums.size();
        int cols = nums[0].size();
        vector<int> rowMark(rows, 0);
        vector<int> colMark(cols, 0);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(nums[i][j] == 0){
                    rowMark[i] = 1;
                    colMark[j] = 1;
                }
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(rowMark[i] || colMark[j]){
                    nums[i][j] = 0;
                }
            }
        }
    }

    void mostOptimal(vector<vector<int>>& nums){
        int rows = nums.size();
        int cols = nums[0].size();
        // vector<int> rowMark(rows, 0);
        // vector<int> colMark(cols, 0);
        int col0 = 1;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(nums[i][j] == 0){
                    nums[i][0] = 0;
                    if(j != 0)
                        nums[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(nums[i][j] != 0){
                    // check for col
                    if(nums[0][j] == 0 || nums[i][0] == 0){
                        nums[i][j] = 0;
                    }
                }
            }
        }

        if(nums[0][0] == 0){
            for(int j = 0; j < cols; j++){
                nums[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i = 0; i < rows; i++){
                nums[i][0] = 0;
            }
        }
    }
    
};

int main(){
    Solution obj;
    vector<vector<int>> vec = { {1,0,1,1},
                                {1,1,0,1},
                                {0,1,1,1}};
    
    obj.mostOptimal(vec);
    // cout << "Length of the longest subarray with sum " << k << " is: " << result << endl;
    return 0;
}