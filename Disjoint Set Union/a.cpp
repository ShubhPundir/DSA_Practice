#include <iostream>
#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        // Initially, each node is its own parent
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find the root of a set with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;  // Already in the same set

        // Attach smaller tree under larger tree
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    // Check if two elements are in the same set
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    DSU dsu(7); // Create 7 disjoint sets (0 through 6)

    dsu.unite(1, 2);
    dsu.unite(2, 3);
    dsu.unite(4, 5);

    cout << boolalpha;
    cout << "Are 1 and 3 connected? " << dsu.isConnected(1, 3) << endl; // true
    cout << "Are 1 and 4 connected? " << dsu.isConnected(1, 4) << endl; // false

    dsu.unite(3, 4);

    cout << "Are 1 and 4 connected after merging 3 and 4? " << dsu.isConnected(1, 4) << endl; // true

    return 0;
}
