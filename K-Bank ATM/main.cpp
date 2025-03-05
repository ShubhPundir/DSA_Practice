#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

const int MAXN = 100000;
vector<bool> is_prime(MAXN + 1, true);

// Function to preprocess primes using Sieve of Eratosthenes
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAXN; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

// Function to check if a number is valid (i.e., not prime)
bool is_valid(int num) {
    return !is_prime[num];
}

// Function to find the minimum cost of transforming A to B
int min_cost(int A, int B) {
    if (A == B) return A; // If already same, cost is just A
    if (!is_valid(A) || !is_valid(B)) return -1; // If A or B are prime, return -1

    queue<pair<int, int>> q; // {current number, cost}
    unordered_set<int> visited;
    q.push(make_pair(A, A));
    visited.insert(A);
    
    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        int curr = front.first;
        int cost = front.second;
        
        string s = to_string(curr);
        int len = s.size();
        
        for (int i = 0; i < len; ++i) {
            for (int d = -1; d <= 1; d += 2) { // Only +1 or -1 operations
                if ((s[i] == '0' && d == -1) || (s[i] == '9' && d == 1))
                    continue;
                
                string next_s = s;
                next_s[i] += d;
                int next_num = stoi(next_s);
                
                if (next_num == B) return cost + next_num;
                
                if (is_valid(next_num) && visited.find(next_num) == visited.end()) {
                    visited.insert(next_num);
                    q.push(make_pair(next_num, cost + next_num));
                }
            }
        }
    }
    return -1; // If no valid transformation is found
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifndef ONLINE_JUDGE 
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    
    sieve(); // Precompute prime numbers
    
    int t;
    cin >> t;
    while (t--) {
        int A, B;
        cin >> A >> B;
        cout << min_cost(A, B) << "\n";
    }
    return 0;
}
