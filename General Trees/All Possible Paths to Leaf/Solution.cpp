#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }
    void getPath(TreeNode* root, vector<vector<int>>& path, vector<int>& curr){
        // cout << root->val << '-';
        curr.push_back(root->val);
        
        if(isLeaf(root)){
            path.push_back(curr);
            return;
        }

        getPath(root->left, path, curr);
        curr.pop_back();
        getPath(root->right, path, curr);
        
    }
public:
    vector<vector<int>> solve(TreeNode* root){
        vector<vector<int>> path;

        if(root == nullptr) return {};
        
        vector<int> curr {};
        getPath(root, path, curr);

        return path;
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;


    cout << "Started all paths calculations"<<endl;
    vector<vector<int>> allPaths = sol.solve(root);
    cout << "Completed all paths calculations"<<endl;

    for(auto x: allPaths){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
    