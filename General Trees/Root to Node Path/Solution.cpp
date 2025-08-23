#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    bool getPath(TreeNode* root, const int& target, vector<int>& path){
        if(root == nullptr) return false;
        
        path.push_back(root->val);

        if(root->val == target){
            return true;
        }
        
        if(getPath(root->left, target, path) || getPath(root->right, target, path)){
            return true;
        }

        path.pop_back();
        return false;

    }
public:
    vector<int> solve(TreeNode* root, int targetLeafValue){
        vector<int> path;

        if(root == nullptr) return {};
        
        getPath(root, targetLeafValue, path);

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

    int targetLeafValue = 7;

    vector<int> path = sol.solve(root, targetLeafValue);

    cout << "Path from root to leaf with value " <<
        targetLeafValue << ": ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }

    return 0;
}
    