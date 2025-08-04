#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums{2,3,5,7,11};
    int k = 5;
    int i = 0;
    for(i = 0; i < nums.size(); i++){
        int number_of_missing_numbers = nums[i] - (i + 1);
        // (i + 1) is what the number *should* be if there were no missing positive integers up to this point.
        // The difference (nums[i] - (i + 1)) tells us how many positive integers are missing *before or at* nums[i].

        if(number_of_missing_numbers >= k)
            break;
    }

    // TC: O(N)
    cout << i + k;
}

// DRY RUN:
// at i = 0, nums[i] is 2, number of numbers missing before this = 1. --> 2 - (i + 1)
// at i = 1, nums[i] is 3, number of numbers missing before this = 1. --> 3 - (1 + 1)
// at i = 2, nums[i] is 5, number of numbers missing before this = 2. --> 5 - (2 + 1)
// at i = 3, nums[i] is 7, number of numbers missing before this = 3. --> 7 - (3 + 1)
// at i = 4, nums[i] is 11, number of numbers missing before this = 6. --> 11 - (4 + 1)
// 6 > k (5)
// hence i + k --> 4 + 5 = 9
// 
// MISSING NUMBERS = [1,3,6,8,9,10,12...]
//                            ♦