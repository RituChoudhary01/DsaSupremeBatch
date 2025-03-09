// Fletten BST to Sorted List.
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

// Helper function to flatten BST into sorted linked list
void inOrderFlatten(Node* root, Node*& prev) {
    if (!root) return;

    inOrderFlatten(root->left, prev);

    prev->left = NULL; // Set left pointer to NULL (flattening)
    prev->right = root; // Link previous node to current
    prev = root; // Move previous pointer forward

    inOrderFlatten(root->right, prev);
}

// Function to flatten BST into sorted linked list
Node* flatten(Node* root) {
    if (!root) return NULL;

    Node* dummy = new Node(-1); // Dummy node to start the list
    Node* prev = dummy;

    inOrderFlatten(root, prev);

    prev->left = prev->right = NULL; // Final node should point to NULL
    Node* head = dummy->right; // The real head of the linked list
    delete dummy; // Delete the dummy node to free memory

    return head;
}

// Print the flattened list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->right;
    }
    cout << "NULL" << endl;
}

// Insert into BST
Node* insertIntoBST(Node* root, int data) {
    if (!root) return new Node(data);
    if (data < root->data) root->left = insertIntoBST(root->left, data);
    else root->right = insertIntoBST(root->right, data);
    return root;
}

// Take input to create BST
void takeInput(Node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main() {
    Node* root = NULL;
    cout << "Enter the BST elements (-1 to stop): " << endl;
    takeInput(root);

    cout << "Flattened BST into sorted linked list: " << endl;
    Node* head = flatten(root);
    printList(head);

    return 0;
}
