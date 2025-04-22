#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool canMeet(double t, const vector<int>& pos, const vector<int>& speed) {
    double left = -1e18, right = 1e18;
    int n = pos.size();

    for (int i = 0; i < n; ++i) {
        double l = pos[i] - speed[i] * t;
        double r = pos[i] + speed[i] * t;
        left = max(left, l);
        right = min(right, r);
    }

    return left <= right; // intersection is non-empty
}

double findMinTime(const vector<int>& pos, const vector<int>& speed) {
    double low = 0.0, high = 1e9;
    double ans = high;

    for (int i = 0; i < 100; ++i) { // binary search with precision
        double mid = (low + high) / 2.0;
        if (canMeet(mid, pos, speed)) {
            ans = mid;
            high = mid;
        } else {
            low = mid;
        }
    }

    return ans;
}

int main() {
    int n = 3;
    vector<int> pos = {0, 10, 20};
    vector<int> speed = {1, 1, 1};

    double result = findMinTime(pos, speed);
    cout << fixed << setprecision(7) << result << endl;
}
