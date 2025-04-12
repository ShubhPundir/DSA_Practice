#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> tree;
vector<int> color;
int white = 0, black = 0;

void dfs(int node, int parent, int currentColor) {
    color[node] = currentColor;
    if (currentColor == 0)
        white++;
    else
        black++;

    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, 1 - currentColor);
        }
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    tree.assign(n + 1, {});
    color.assign(n + 1, -1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, -1, 0);

    // Total different-color pairs: white * black
    // Direct edges (n - 1) must be subtracted
    cout << white * black - (n - 1) << "\n";

    return 0;
}
