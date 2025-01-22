#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size(), cols = isWater[0].size();
        // cout << rows << " " << cols;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(isWater[i][j] == 1){
                    isWater[i][j] = 0;
                }
            }
        }
        
        return isWater;
    }
};

int main(){
    Solution hehe;

    vector<vector<int>> isWater = {{0,0},{0,1}};
    hehe.highestPeak(isWater);

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << isWater[i][j] << " ";
        }
        cout << "\n";
    }
}