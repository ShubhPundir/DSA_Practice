#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> generate(int numRows){
        if(1 == numRows)
            return {{1}};
        else if ( 2 == numRows)
            return {{1}, {1,1}};

        vector<vector<int>> result;
        // initialize array
        for(int i = 0; i < numRows; i++){
            vector<int> arr (i+1,1); // each vector of size i and all values = 1
            result.push_back(arr);
        }

        for(int i = 2; i < numRows; i++){
            for(int j = 1; j < result[i].size() - 1; j++){
                result[i][j] = result[i - 1][j-1] + result[i - 1][j];
            }
        }

        return result;
    }
};

int main(){
    Solution soln;
    vector<vector<int>> result = soln.generate(5);
    for(auto x : result){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }
}