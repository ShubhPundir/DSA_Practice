#include <bits/stdc++.h>
using namespace std;

// input = ["eat","tea","tan","ate","nat","bat"]
// output = [["bat"],["tan","nat"],["eat","tea","ate"]]
class Solution{
    // first line of thinking was to make an individual hashmap of 26 characters for each 
    // or an array of 26 characters, --> [map, vector<string>] but that would take too much space
    // as we have to make a cover map as well
    // O(N * M) where N is length of input array and M is the average length of each string
    // but O(2 * N) would be the space complexity

    // second train of thought says that we should sort each string
    // O(N * M * log(M))
    // but O(N) would be the space complexity

        vector<vector<string>> groupAnagramsSorted(vector<string>& strs){
            unordered_map<string, vector<string>> mpp;

            for(string& s: strs){
                string key = s;
                sort(key.begin(), key.end());
                mpp[key].push_back(s);
            }

            vector<vector<string>> result;
            for(auto& m : mpp){
                result.push_back(m.second);
            }
        }
};

int main(){

}