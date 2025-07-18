#include <iostream>
#include <queue>
using namespace std;

const int V = 5;
int adj[V][V] = {
    {0, 1, 1, 0, 0},  // Node 0
    {1, 0, 0, 1, 1},  // Node 1
    {1, 0, 0, 0, 0},  // Node 2
    {0, 1, 0, 0, 0},  // Node 3
    {0, 1, 0, 0, 0}   // Node 4
};

bool visited[V];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < V; ++i) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    // Initialize visited array
    for (int i = 0; i < V; ++i)
        visited[i] = false;

    int startNode = 0;
    cout << "BFS traversal from node " << startNode << ": ";
    bfs(startNode);
    cout << endl;

    return 0;
}
