#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Total number of nodes
#define V 7

// BFS to find path with positive capacity
bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

// Ford-Fulkerson Algorithm
int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    vector<vector<int>> rGraph = graph; // Residual graph
    vector<int> parent(V); // Store path
    int max_flow = 0; // Initially 0

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;

        // Find minimum capacity along the path
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // Update residual capacities
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    // Graph capacity matrix (7x7)
    vector<vector<int>> graph(V, vector<int>(V, 0));

    // Filling based on given graph
    graph[0][1] = 7;  // 1 -> 2
    graph[0][2] = 10; // 1 -> 3
    graph[1][2] = 1;  // 2 -> 3
    graph[1][4] = 5;  // 2 -> 5
    graph[2][3] = 2;  // 3 -> 4
    graph[2][5] = 7;  // 3 -> 6
    graph[3][4] = 3;  // 4 -> 5
    graph[3][5] = 2;  // 4 -> 6
    graph[4][6] = 10; // 5 -> 7
    graph[5][6] = 4;  // 6 -> 7

    int source = 0; // node 1
    int sink = 6;   // node 7

    cout << "The maximum possible flow is " << fordFulkerson(graph, source, sink) << endl;

    return 0;
}
