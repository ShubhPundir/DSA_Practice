#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

class UnionFind {
    private:
        vi p, rank, setSize, maxSet, minSet;
        int numSets;
    public:
        UnionFind(int N){
            // the goal here is to create N singleton sets

            p.assign(N, 0); // set parent of each element to itself
            for(int i = 0; i < N; i++)
                p[i] = i;

            // the height of all trees are zero:
            rank.assign(N, 0);

            // the sizes of the individual sets are 1
            setSize.assign(N, 1);

            // initialize maxSet and minSet
            maxSet.assign(N, 0);
            minSet.assign(N, 0);
            for(int i = 0; i < N; i++) {
                maxSet[i] = i;
                minSet[i] = i;
            }

            numSets = N;
        }

        // returns the representative element of the set that i belongs to 
        int findSet(int i){
            if(p[i] == i)
                return i;
            else
                return p[i] = findSet(p[i]);
        }

        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j){
            if(isSameSet(i,j))
                return;
        
            int x = findSet(i);
            int y = findSet(j);

            if(rank[x] > rank[y])
                swap(x,y);
            
            p[x] = y;

            if(rank[x] == rank[y])
                rank[y]++;
            
            setSize[y] += setSize[x];
            maxSet[y] = max(maxSet[y], maxSet[x]);
            minSet[y] = min(minSet[y], minSet[x]);
            numSets--;
        }

        int sizeOfSet(int i){
            return setSize[findSet(i)];
        }

        int numDisjointSets(){
            return numSets;
        }

        int maxInSet(int i){
            return maxSet[findSet(i)];
        }

        int minInSet(int i){
            return minSet[findSet(i)];
        }
};
int main(){

    int n, m;
    cin >> n >> m;

    UnionFind dsu(n+1);

    while(m--){
        string s;
        cin >> s;

        int x, y;
        cin >> x >> y;

        if(s == "union")
            dsu.unionSet(x,y);
        else if(s == "isSameSet"){
            if(dsu.isSameSet(x,y))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }


    return 0;
}