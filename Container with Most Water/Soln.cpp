#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    cout << "Haello ";
    // vector<int> height = {1,8,6,2,5,4,8,3,7};
    vector<int> height = {4,1,3,1};
    int left = 0;
    int right = height.size() - 1;

    int maxWater = 0;

    while (left < right)
    {
        int distance = right - left;
        int currWater = distance * min(height[right],height[left]);
        maxWater = max(maxWater,currWater);

        if(height[right] < height[left]){
            right--;
        } else {
            left ++;
        }
    }

    cout << maxWater;
    
    
}