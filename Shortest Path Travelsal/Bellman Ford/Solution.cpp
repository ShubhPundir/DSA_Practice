#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void bellmanFord(vector<vector<int>> &graph, int V, int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    // Step 1: Relax all edges (V - 1) times
    for (int k = 0; k < V - 1; k++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Step 2: Check for negative-weight cycles
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                cout << "Graph contains a negative weight cycle\n";
                return;
            }
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << i << "\t" << "INF" << endl;
        else
            cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 6, INF, 7, INF},
        {INF, 0, 5, 8, -4},
        {INF, -2, 0, INF, INF},
        {INF, INF, -3, 0, 9},
        {2, INF, 7, INF, 0}
    };

    int src = 0;
    bellmanFord(graph, V, src);

    return 0;
}
