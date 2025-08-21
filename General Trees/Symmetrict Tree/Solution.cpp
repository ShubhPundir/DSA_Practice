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
    bool isSymmetric(TreeNode* root) {
        return function(root->left, root->right);
    }
    bool function(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2){
            // both nullptr
            return true;
        }
        if(!t1 || !t2){
            // one is nullptr, other isn't
            return false;
        }
        return (t1->val == t2->val) && function(t1->left, t2->right) && function(t1->right, t2->left);
    }
};

