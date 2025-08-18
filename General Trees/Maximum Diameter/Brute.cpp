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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        findMax(root, maxi);
        return maxi;
    }
    void findMax(TreeNode* root, int& maxi){
        if(root == NULL){
            return;
        }
        int lH = dfsHeight(root->left);
        int rH = dfsHeight(root->right);
    
        maxi = max(maxi, lH + rH);
        findMax(root->left, maxi);
        findMax(root->right, maxi);
    }
    int dfsHeight(TreeNode* root){
        if(root == NULL) return 0;

        int lH = dfsHeight(root->left);
        int rH = dfsHeight(root->right);

        // maxi = max(maxi, lH + rH);
        return 1 + max(lH, rH);
    }
};