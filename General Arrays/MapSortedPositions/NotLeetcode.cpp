#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    vector<int> original = {4, 10, 9, 120, 0, -9, 3};

    vector<int> sorted = original;
    sort(sorted.begin(), sorted.end(), greater<int>());
    // {120, 10, 9, 4, 3, 0, -9}

    // Create a map from value to its index in sorted array
    unordered_map<int, int> valueToIndex;
    for (int i = 0; i < sorted.size(); ++i) {
        // Only insert if not already inserted (handles duplicates)
        if (valueToIndex.find(sorted[i]) == valueToIndex.end()) { // not found
            valueToIndex[sorted[i]] = i;
        }
    } // {{120: 0}, {10: 1}, {9:2}, {4:3}, {3:4}, {0:5}, {-9:6}}

    // Map each element in the original to its index in the sorted
    vector<int> mapping;
    for (int val : original) {
        mapping.push_back(valueToIndex[val]);
    } // 3, 1, 2, 0, 5, 6, 4

    // Output the result
    cout << "Mapping from original to sorted indexes:\n";
    for (int index : mapping) {
        cout << index << " ";
    }
    std::cout << "\n";

    return 0;

}