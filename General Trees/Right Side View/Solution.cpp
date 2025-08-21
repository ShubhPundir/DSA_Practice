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
    vector<int> rightSideView(TreeNode* root) {
        // include logic of height to see any new values
        // perform a DFS to both right first and then left
        // prepare a map ds to not overwrite values already seen

        vector<int> results;
        map<int, int> mpp; // {pos, val}
        // mpp[0] = root;
        dfs(root, mpp, 0);
        // iterate through mpp to store into results
        
        for(auto x: mpp){
            results.push_back(x.second);
        }

        return results;
    }
    void dfs(TreeNode* root, map<int, int>& mpp, int height){
        if(root == nullptr) return;
        if(mpp.find(height) == mpp.end()){
            // new height
            mpp[height] = root->val;
        }
        dfs(root->right, mpp, height+1);
        dfs(root->left, mpp, height+1);
    }
};