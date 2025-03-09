// Convert BST into Balance BST
// https://leetcode.com/problems/balance-a-binary-search-tree/description/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Insertion in BST
Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

// Take input to insert nodes into BST
void takeInput(Node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Level Order Traversal
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// Inorder traversal to store values in a vector
void inorder(Node* root, vector<int>& in) {
    if (!root) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// Build a balanced BST from a sorted array
Node* buildTree(vector<int>& in, int s, int e) {
    if (s > e) return NULL;
    
    int mid = s + (e - s) / 2;
    Node* root = new Node(in[mid]);
    
    root->left = buildTree(in, s, mid - 1);
    root->right = buildTree(in, mid + 1, e);
    
    return root;
}

// Convert an unbalanced BST to a balanced BST
Node* balanceBST(Node* root) {
    vector<int> in;
    inorder(root, in);
    return buildTree(in, 0, in.size() - 1);
}

int main() {
    Node* root = NULL;
    cout << "Enter the data for tree (-1 to stop): " << endl;
    takeInput(root);

    cout << "BST tree is :" << endl;
    levelOrderTraversal(root);

    Node* root1 = balanceBST(root);
    cout << "Balanced BST is :" << endl;
    levelOrderTraversal(root1);

    return 0;
}
