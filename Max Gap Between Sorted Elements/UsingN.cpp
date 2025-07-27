#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maximumGap(vector<int>& nums){
        int n = nums.size();
        if (n < 2) return 0;

        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        if(min_val == max_val) return 0;
        // the maximum gap must lie between the buckets as 
        // The gap between them must be less than or equal to bucketSize 
        // (because they lie within a bucket of that size).
        // The maximum gap is the difference between the min of current bucket and 
        // the max of previous non-empty bucket.
    
        int bucket_size = max(1, (max_val - min_val) / (n - 1));
        int bucket_count = (max_val - min_val) / bucket_size + 1;

        vector<int> bucket_min(n, INT_MAX);
        vector<int> bucket_max(n, INT_MIN);
        vector<bool> bucket_used(n, false);
        // so the values are sorted in buckets, 
        // but we only know the maximum and minimum of each bucket
        for(int num: nums){
            int idx = (num - min_val) / bucket_size;
            bucket_min[idx] = min(bucket_min[idx], num);
            bucket_max[idx] = max(bucket_max[idx], num);
            bucket_used[idx] = true;
        }

        int prevMax = min_val;
        int maxGap = 0;
        
        for(int i = 0; i < bucket_count; i++){
            if(!bucket_used[i]) continue;
            
            maxGap = max(maxGap, bucket_min[i] - prevMax);
            // maxGap would always be min of current bucket - maximum of last bucket
            // reason being gap would always be greater than bucketSize
            // so it is not possible that it would be max of current bucket - min of current bucket
            // cause the above value would always be less than bucketSize

            prevMax = bucket_max[i];
        }
        return maxGap;
    }
};