#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums{2,3,4,7,11};
    int k = 5;
    int i = 0;
    int current = 1;
    int lol = 0;
    while(true){
        lol++;
        if(nums[i] != current){
            // current is not in nums[i], hence current is a missing element
            cout << current << endl;
            k--;
            if(k == 0){
                cout << "ANS:" << current << endl;
                break;
            }
            current++;
        } else {
            current++; i++;
        }
    }

    cout << "lol: " << lol; // N + k

    // TC: O(N+k)
}
