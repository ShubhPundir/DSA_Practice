#include <bits/stdc++.h>
using namespace std;

const int V = 5; // Number of vertices
int adj[V][V] = {
    {0, 1, 1, 0, 0},  // Node 0
    {1, 0, 0, 1, 1},  // Node 1
    {1, 0, 0, 0, 0},  // Node 2
    {0, 1, 0, 0, 0},  // Node 3
    {0, 1, 0, 0, 0}   // Node 4
};

bool visited[V];

void dfs_iterative(int start) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            // Push adjacent unvisited nodes (in reverse order for consistent output with recursive DFS)
            for (int i = V - 1; i >= 0; --i) {
                if (adj[node][i] == 1 && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }
}

int main() {
    // Initialize visited array
    for (int i = 0; i < V; ++i)
        visited[i] = false;

    int startNode = 0;
    cout << "Iterative DFS traversal from node " << startNode << ": ";
    dfs_iterative(startNode);
    cout << endl;

    return 0;
}