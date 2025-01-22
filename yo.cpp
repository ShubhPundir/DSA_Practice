#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    unordered_map<int, pair<int, int>> positionMap;

    // Adding key-value pairs
    positionMap[1] = {10, 20}; // Key 1 maps to pair (10, 20)
    positionMap[2] = {30, 40}; // Key 2 maps to pair (30, 40)

    // Accessing elements
    for (const auto& [key, value] : positionMap) {
        cout << "Key: " << key << ", Value: (" << value.first << ", " << value.second << ")\n";
    }
    // works for c++17 and higher

    return 0;
}
