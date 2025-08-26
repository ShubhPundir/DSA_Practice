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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        long long res = 1;
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while(!q.empty()){
            long long cnt = q.size();
            long long start = q.front().second;
            long long end = q.back().second;

            res = max(res, end - start + 1);

            for(int i = 0; i < cnt; i++){
                pair<TreeNode*, int> p = q.front();
                // we will use it while inserting it's children
                // left child --> 2 * idx + 1;
                // right child --> 2 * idx + 2;

                long long idx = (long long) p.second - start;
                q.pop();

                // if left child exists
                if(p.first->left != NULL)
                    q.push({p.first->left, (long long) 2 * idx + 1});

                // if right child exists
                if(p.first->right != NULL)
                    q.push({p.first->right, (long long) 2 * idx + 2});
            }
        }
        return res;
    }
};