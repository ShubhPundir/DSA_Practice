// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // cout << "Hello";
    // vector<int> li = {1,2,3,4,5,6};
    vector<int> li = {4,2,1,3};
    int n = li.size();
    int cost = 0;

    for(int i=0; i< n-1; i++){
        int min_idx = i;
        for(int j = i + 1; j < n; j++){
            if(li[min_idx] > li[j])
                min_idx = j;
        }

        // Reverse the subarray from i to min_pos manually
        for (int left = i, right = min_idx; left < right; ++left, --right) {
            swap(li[left], li[right]);
        }

        // Add the cost of the operation
        cost += min_idx - i + 1;
    }

    cout << cost;
}