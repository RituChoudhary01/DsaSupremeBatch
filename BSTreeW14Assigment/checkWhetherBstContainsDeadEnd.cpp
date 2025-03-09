// Check Whether BST Contains Dead End.
// https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1 

#include <iostream>
#include<stack>
#include<unordered_map>
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
void fun(Node* root,unordered_map<int,bool>&visited,bool &ans){
    if(!root) return;
    visited[root->data]=1;
    if(root->left==0&&root->right==0){
        int xPov = root->data+1;
        int xNeg = root->data -1 ==0?root->data:root->data-1;
        if(visited.find(xPov)!=visited.end()&&visited.find(xNeg)!=visited.end()){
            ans = true;
            return;
        } 
    }
        fun(root->left,visited,ans);
        fun(root->right,visited,ans);
    }

bool isDeadEnd(Node* root){
    bool ans = false;
    unordered_map<int,bool>visited;
    fun(root,visited,ans);
    return ans;
}
int main() {
    cout << "Enter the tree elements (-1 to stop): " << endl;
    Node* root = NULL;
    takeInput(root);
    cout<<"tree has a dead end: "<<isDeadEnd(root)<<endl;
    return 0;
}