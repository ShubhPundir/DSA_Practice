#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
void findParents(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front(); q.pop();

                if(temp->left){
                    q.push(temp->left);
                    parent[temp->left] = temp;
                }
                if(temp->right){
                    q.push(temp->right);
                    parent[temp->right] = temp;
                }
            }
        }
    }

    int burn(TreeNode* root, TreeNode* target) {
        int time = -1;  // Start from -1 since we count the initial node
        unordered_map<TreeNode*, TreeNode*> parent;
        
        findParents(parent, root);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;  // Mark target as visited initially

        while(!q.empty()){
            int size = q.size();
            time++;  // Increment time for each level

            for(int i = 0; i < size; i++){
                auto top = q.front(); q.pop();
                
                if(top->left && !visited[top->left]){
                    visited[top->left] = true;
                    q.push(top->left);
                }

                if(top->right && !visited[top->right]){
                    visited[top->right] = true;
                    q.push(top->right);
                }
                
                if(parent[top] && !visited[parent[top]]){
                    visited[parent[top]] = true;
                    q.push(parent[top]);
                }
            }
        }
 
        return time;
    }
};

// Helper function to create a tree node
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Create a sample tree
    //      1
    //    /   \
    //   2     3
    //  / \   /
    // 4   5 6
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    Solution solution;
    
    // Test case 1: Burn from node with value 2
    cout << "Time to burn tree from node 2: " << 
        solution.burn(root, root->left) << endl;    // Expected output: 2

    // Test case 2: Burn from leaf node 4
    cout << "Time to burn tree from node 4: " << 
        solution.burn(root, root->left->left) << endl;  // Expected output: 3

    // Clean up memory (important!)
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}