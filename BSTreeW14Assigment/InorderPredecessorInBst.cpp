#include <iostream>
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

// Find a node in BST
Node* findNode(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL; 
}

// Q1: Inorder Predecessor in BST
Node* findPredecessor(Node* root, Node* p) {
    Node* pred = NULL;
    Node* curr = root;
    while (curr) {
        if (curr->data < p->data) {
            pred = curr;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return pred;
}

// Q2: Inorder Successor in BST
Node* findSuccessor(Node* root, Node* x) {
    Node* succ = NULL;
    Node* curr = root;
    while (curr) {
        if (curr->data > x->data) {
            succ = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return succ;
}

int main() {
    cout << "Enter the tree elements (-1 to stop): " << endl;
    Node* root = NULL;
    takeInput(root);

    cout << "Enter the node value to find predecessor and successor: ";
    int target;
    cin >> target;

    Node* targetNode = findNode(root, target);
    if (!targetNode) {
        cout << "Node not found in the BST!" << endl;
        return 0;
    }

    Node* pred = findPredecessor(root, targetNode);
    Node* succ = findSuccessor(root, targetNode);

    cout << "Inorder Predecessor: " << pred->data << endl;
    cout << "Inorder Successor: " << succ->data << endl;
    return 0;
}

