#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

void dfsTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    // Print the data of the current node
    std::cout << root->data << " ";
    // Recursively call for the left subtree
    dfsTraversal(root->left);
    // Recursively call for the right subtree
    dfsTraversal(root->right);
}

// --- Breadth-First Search (BFS) Traversal ---
// This traversal explores the tree level by level.
// It's an iterative approach using a queue.
void bfsTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    // Create a queue and push the root node
    std::queue<Node*> q;
    q.push(root);

    // Loop until the queue is empty
    while (!q.empty()) {
        // Get the node at the front of the queue
        Node* curr = q.front();
        q.pop();

        // Print the data of the current node
        std::cout << curr->data << " ";

        // Push the left child to the queue if it exists
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        // Push the right child to the queue if it exists
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    dfsTraversal(root);
    cout << "------------------------"<<endl;
    bfsTraversal(root);
}