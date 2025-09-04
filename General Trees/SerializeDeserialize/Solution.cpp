#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ser = "";
        // using level order

        if(root == NULL) return ser;


        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            if(curNode == nullptr) ser.append("#,");
            else ser.append(to_string(curNode->val) + ",");

            if(curNode != nullptr){
                q.push(curNode->left);
                q.push(curNode->right);
            }    
        }
        
        // Remove the trailing comma if the string is not empty
        if (!ser.empty()) {
            ser.pop_back(); 
        }
        
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                node->left = nullptr;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#"){
                node->right = nullptr;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));