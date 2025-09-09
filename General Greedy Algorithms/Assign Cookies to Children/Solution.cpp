#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int happyChildren = 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int i = 0, j = 0; // i is child's greed and j is cookie index

        while(j < s.size() && i < g.size()){
            if(s[j] >= g[i]){
                i++; // next child
                happyChildren++;
            }
            j++;
        }


        return happyChildren;
    }
};


int main(){
    Solution soln;
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 4};

    cout << soln.findContentChildren(g, s);

    return 0;
}