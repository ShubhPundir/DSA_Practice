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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parent;
        
        findParents(parent, root);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);

        while(k-- && !q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto top = q.front(); q.pop();

                visited[top] = true;
                
                if(top->left && !visited[top->left]){
                    q.push(top->left);
                }
                
                if(top->right && !visited[top->right]){
                    q.push(top->right);
                }

                if(parent[top] && !visited[parent[top]]){
                    q.push(parent[top]);
                }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }


        return ans;
    }
};