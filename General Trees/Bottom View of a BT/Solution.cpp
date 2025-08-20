#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int x): val(x), left(nullptr), right(nullptr) {};
};

class Solution{
public:
    vector<int> topView(Node* root){
        // top view are for those with a single parent
        // imagine it with coordinates of x = 0 as root, and + and - both sides
        vector<int> results;
        bfs(root, results);
        return results;
    }
    void bfs(Node* root, vector<int>& results){
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        map<int, int> mpp; // pos, val
        mpp[0] = root->val;
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            Node* node = it.first; int pos = it.second;

            
            mpp[pos] = node->val;
            

            if(node->left != nullptr){
                q.push({node->left, pos - 1});
            }
            if(node->right != nullptr){
                q.push({node->right, pos + 1});
            }
        }
        for(auto it : mpp){
            results.push_back(it.second);
        }
    }

};

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(11);
    root->right->left = new Node(9);

    Solution solution;

    // Get the top view traversal
    vector<int> topView =
                    solution.topView(root);

    // Print the result
    cout << "Bottom View Traversal: "<< endl;
    for(auto node: topView){
        cout << node << " ";
    }

    return 0;
}