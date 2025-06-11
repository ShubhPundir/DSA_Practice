#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> memo;

int maxCost(int n){
    if(n == 1) return 0;
    if(n == 2) return 1;
    if (memo.find(n) != memo.end()) return memo[n]; // Return cached result if available
    
    int a = n/2;
    int b = n-a;
    int score = a*b;

    cout << "Stack sizes: " << a << ", " << b << ": " << score << endl;

    memo[n] =  score + maxCost(a) + maxCost(b);
    return memo[n];
}


int main(){
    int N = 20;
    cout << maxCost(10);
    return 0;
}