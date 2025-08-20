#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ds;
        // ds --> [{y, x, val}]
        fillDS(root, ds, 0, 0);
        
        sort(ds.begin(), ds.end());

        vector<vector<int>> res;
        int prevCol = INT_MIN;

        for (auto x : ds) {
            int col = x[0];
            int val = x[2];
            if (col != prevCol) {
                res.push_back({});
                prevCol = col;
            }
            res.back().push_back(val);
        }

        return res;
    }
    void fillDS(TreeNode* root, vector<vector<int>>& ds, int y, int x){
        if(root == NULL) return;
        ds.push_back({y, x, root->val});
        fillDS(root->left, ds, y-1, x+1);
        fillDS(root->right, ds, y+1, x+1);

    }
};