#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> init(vector<int>& start, vector<int>& end){
        vector<vector<int>> nums;

        for(int i = 0; i < start.size(); i++){
            nums.push_back({start[i], end[i], i+1});
        }

        sort(nums.begin(), nums.end(), [] (const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        return nums;
    }

    int meetings(vector<vector<int>> nums){
        int cnt = 1, last_ends = nums[0][1];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i][0] >= last_ends){
                cnt++;
                last_ends = nums[i][1];
            }
        }
        return cnt;
    }
};


int main(){
    Solution soln;
    vector<int> start {0, 3, 1, 5, 5, 8};
    vector<int> end {5, 4, 2, 9, 7, 9 };

    // greedy --> faster meetings
    // make a data structure based on (start, end, postition) and sort it according to the ending times
    vector<vector<int>> nums = soln.init(start, end);

    cout << "Sorted meetings (start, end, original_index):" << endl;
    for (const auto& meeting : nums) {
        cout << "(" << meeting[0] << ", " << meeting[1] << ", " << meeting[2] << ")" << endl;
    }

    cout << "NUMBER OF MEETINGS: " << soln.meetings(nums);


}