#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};

class Solution{
public:
    
    TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b){
        if(root == nullptr || root == a || root == b) return root;

        TreeNode* left_ = lca(root->left, a, b);
        TreeNode* right_ = lca(root->right, a, b);
    
        if(left_ == NULL)
            return right_;
        else if(right_ == NULL)
            return left_;
        else
            return root;
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
    TreeNode* lca = soln.lca(root, root->left->left, root->left->right->right);
    cout << "LCA: " << lca->val;



}