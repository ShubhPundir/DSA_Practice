#include <bits/stdc++.h>
using namespace std;

const int V = 5; // Number of vertices
const int INF = numeric_limits<int>::max();

// Adjacency matrix with weights (0 means no edge unless self-loop)
// int graph[V][V] = {
//     {0, 10, 3, 0, 0},
//     {10, 0, 1, 2, 0},
//     {3, 1, 0, 8, 2},
//     {0, 2, 8, 0, 7},
//     {0, 0, 2, 7, 0}
// };
int graph[V][V] = {
    {0, 1, 10, 0, 0},
    {0, 0, 0, 2, 0},
    {0, 0, 0, -10, 0},
    {0, 0, 0, 0, 3},
    {0, 0, 0, 0, 0}
};

int minDistance(int dist[], bool visited[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; ++v) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int src) {
    int dist[V];       // Shortest distances from src to each node
    bool visited[V];   // Whether the node is finalized

    // Initialize all distances as infinite and visited as false
    for (int i = 0; i < V; ++i) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0; // Distance to self is 0

    for (int count = 0; count < V - 1; ++count) {
        int u = minDistance(dist, visited);
        visited[u] = true; 

        for (int v = 0; v < V; ++v) {
            if (
                !visited[v] && 
                graph[u][v] &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print shortest distances
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "To node " << i << ": " << dist[i] << endl;
    }
}
// ---- MODIFIED DIJKSTRA (no DecreaseKey, allow duplicates) ----
void modifiedDijkstra(int src) {
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src}); // {distance, node}

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Ignore stale entries
        if (d > dist[u]) continue;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v]) {
                int weight = graph[u][v];
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    cout << "\nModified Dijkstra (with priority queue):\n";
    for (int i = 0; i < V; ++i) {
        cout << "To node " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int startNode = 0;
    dijkstra(startNode);
    return 0;
}
