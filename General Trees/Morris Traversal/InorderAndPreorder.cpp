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

vector<int> getInorder(TreeNode* root){
    vector<int> inorder;
    TreeNode* cur = root;

    while(cur != NULL){
        if(cur->left == NULL){
            inorder.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = cur; // creation of thread
                cur = cur->left;
            } else {
                prev->right = NULL; // cut the thread
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }      

    return inorder;
}

vector<int> getPreorder(TreeNode* root){
    vector<int> preorder;
    TreeNode* cur = root;

    while(cur != NULL){
        if(cur->left == NULL){
            preorder.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = cur; // creation of thread
                preorder.push_back(cur->val);
                cur = cur->left;
            } else {
                prev->right = NULL; // cut the thread
                cur = cur->right;
            }
        }
    }      

    return preorder;
}


// TC: Amortized O(N) + O(N)
// SC: O(1)