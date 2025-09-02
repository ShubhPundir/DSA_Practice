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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;

        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildingTheTree(inorder, 0, inorder.size() - 1, 
                                         postorder, 0, postorder.size() - 1, 
                                         inMap);

        return root;
    }
    TreeNode* buildingTheTree(vector<int>& inorder, int inStart, int inEnd, 
                              vector<int>& postorder, int postStart, int postEnd, 
                              map<int, int>& inMap){
    
        if(postEnd < postStart || inEnd < inStart) return nullptr;
        // starting from behind

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        // Recursively build the left subtree.
        // Inorder: from inStart to inRoot - 1
        // Postorder: from postStart to postStart + numsLeft - 1
        root->left = buildingTheTree(inorder, inStart, inRoot - 1, 
                           postorder, postStart, postStart + numsLeft - 1, 
                           inMap);
        
        // Recursively build the right subtree.
        // Inorder: from inRoot + 1 to inEnd
        // Postorder: from postStart + numsLeft to postEnd - 1
        root->right = buildingTheTree(inorder, inRoot + 1, inEnd, 
                            postorder, postStart + numsLeft, postEnd - 1, 
                            inMap);

        return root;
    }
};

