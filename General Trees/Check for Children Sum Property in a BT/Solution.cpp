#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};
/*
    Children Sum Property in a binary tree states that for every node, 
    the sum of its children's values (if they exist) should be equal to the node's value. 
    If a child is missing, it is considered as having a value of 0.
*/

class Solution{
public:
    bool checkOnlyForChildrenSumProperty(TreeNode* root){
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return true;
        }

        int child_sum = 0;
        if (root->left != nullptr) {
            child_sum += root->left->val;
        }
        if (root->right != nullptr) {
            child_sum += root->right->val;
        }

        // Check if the current node's value equals the sum of its children.
        // Then, recursively check the left and right subtrees.
        return (root->val == child_sum) && 
               checkOnlyForChildrenSumProperty(root->left) && 
               checkOnlyForChildrenSumProperty(root->right);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    Solution soln;
    cout << soln.checkOnlyForChildrenSumProperty(root);

}