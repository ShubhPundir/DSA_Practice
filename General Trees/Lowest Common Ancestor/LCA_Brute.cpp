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
    bool dfsPath(TreeNode* root, int& target, vector<int>& path){
        if(root == nullptr) return false;

        path.push_back(root->val);

        if(root->val == target) return true;

        if(dfsPath(root->left, target, path) || dfsPath(root->right, target, path)){
            return true;
        }

        path.pop_back();
        return false;

    }
    vector<int> getPath(TreeNode* root, int target){
        vector<int> path;
        dfsPath(root, target, path);
        return path;
    }
    int lca(TreeNode* root, int a, int b){
        // 1st Approach: Brute Force
        // get path from root -> a and root -> b
        // last element to match in the above paths
    
        // TC: O(N) + O(N) --> paths + O(N) --> Matching paths
        // SC: O(N) + O(N)

        vector<int> path_a = getPath(root, a);
        vector<int> path_b = getPath(root, b);

        cout << "Path_a: ";
        int i = 0; 
        for(i = 0; i < path_a.size(); i++){
            cout << path_a[i] << " ";    
        }
        cout << endl;
        
        cout << "Path_b: ";
        for(i = 0; i < path_b.size(); i++){
            cout << path_b[i] << " ";    
        }
        cout << endl;
        
        return -1;

    
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
    cout << soln.lca(root, 4, 7);




}