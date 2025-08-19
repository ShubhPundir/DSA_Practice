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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // If the root is null, return an empty result.
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> results;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Determine the correct index to place the node value based on the direction.
                int index = leftToRight ? i : levelSize - 1 - i;
                currentLevel[index] = node->val;

                // Push children to the queue for the next level.
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            results.push_back(currentLevel);

            // Flip the direction for the next level.
            leftToRight = !leftToRight;
        }

        return results;
    }
};