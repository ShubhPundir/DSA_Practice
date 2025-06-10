#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {


    vector<int> h = {30, 10, 60, 10, 60, 50};
    int n = h.size();

    vector<int> dp(n);        // dp[i] = min cost to reach stone i
    vector<int> from(n);      // from[i] = previous stone used to reach i

    dp[0] = 0;
    from[0] = -1;

    if (n > 1) {
        dp[1] = abs(h[1] - h[0]);
        from[1] = 0;
    }

    for (int i = 2; i < n; ++i) {
        int cost1 = dp[i-1] + abs(h[i] - h[i-1]);
        int cost2 = dp[i-2] + abs(h[i] - h[i-2]);

        if (cost1 < cost2) {
            dp[i] = cost1;
            from[i] = i-1;
        } else {
            dp[i] = cost2;
            from[i] = i-2;
        }
    }

    // Reconstruct path
    vector<int> path;
    for (int i = n-1; i != -1; i = from[i]) {
        path.push_back(i); // convert 0-based to 1-based index
    }

    reverse(path.begin(), path.end());

    // Output
    cout << "Minimum Cost: " << dp[n-1] << endl;
    cout << "Path: ";
    for (int idx : path) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
