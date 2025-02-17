#include <iostream>
#include <vector>
using namespace std;

int main(){
    int R = 2, C = 2;
    vector<vector<int>> height(R, vector<int>(C, R + C));

    cout << height.size() << " " << height[0].size();
    
    return 0;
}