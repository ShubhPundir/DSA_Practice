#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& arr){
        int n = arr.size();
        vector<int> leader;
        int max = arr[n-1];
        leader.push_back(max);

        for(int i = n-2; i>=0; i--){
            if(max < arr[i]){
                max = arr[i];
            }
            if(arr[i] >= max){
                leader.push_back(arr[i]);
            }
        }
        return leader;
    }
};
int main(){
    Solution sol;
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> ans = sol.leaders(arr);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}