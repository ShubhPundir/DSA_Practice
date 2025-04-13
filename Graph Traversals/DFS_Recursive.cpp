#include <bits/stdc++.h>
using namespace std;

const int V = 5; // Number of vertices
int adj[V][V] = {
    {0, 1, 1, 0, 0},  // Connections from node 0
    {1, 0, 0, 1, 1},  // Connections from node 1
    {1, 0, 0, 0, 0},  // Connections from node 2
    {0, 1, 0, 0, 0},  // Connections from node 3
    {0, 1, 0, 0, 0}   // Connections from node 4
};

bool visited[V];

void dfs(int node){
    visited[node] = true;
    cout << node << " ";

    for(int neighbour = 0; neighbour < V; neighbour++){
        if(adj[neighbour][node] == 1 && !visited[neighbour]){
            dfs(neighbour);
        }
    }
}


int main() {
    // Initialize visited array
    for (int i = 0; i < V; ++i)
        visited[i] = false;

    int startNode = 0;
    cout << "DFS traversal from node " << startNode << ": ";
    dfs(startNode);
    cout << endl;

    return 0;
}