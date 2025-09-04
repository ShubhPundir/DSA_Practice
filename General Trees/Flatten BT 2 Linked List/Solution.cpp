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

void flattenInplace(TreeNode* root){
    // Right Left Root
    // Reverse Post Order
    TreeNode* prev = nullptr;
    flatten(root, prev);
}

void flatten(TreeNode* node, TreeNode*& prev){
    if(node == NULL) return;
    flatten(node->right, prev);
    flatten(node->left, prev);

    node->right = prev;
    node->left = NULL;
    prev = node;
}