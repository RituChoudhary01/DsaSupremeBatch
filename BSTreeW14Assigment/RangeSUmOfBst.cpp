// Range Sum of BST
// https://leetcode.com/problems/range-sum-of-bst/

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
int rangeSumBst(Node* root,int low,int high){
    if(!root) return 0;
    int ans = 0;
    bool wasInRange = false;
    if(root->data >= low && root->data <= high){
        wasInRange = true;
        ans+=root->data;
    }
    if(wasInRange){
        ans+=rangeSumBst(root->left,low,high)+rangeSumBst(root->right,low,high);
    }
    else if(root->data<low){
        ans+=rangeSumBst(root->right,low,high);
    }
    else if(root->data>high){
        ans+=rangeSumBst(root->left,low,high);
    }
    return ans;
}
int main() {
    cout << "Enter the tree elements (-1 to stop): " << endl;
    Node* root = NULL;
    takeInput(root);
    int low,high;
    cout<<"Enter the low value of range:"<<endl;
    cin>>low;
    cout<<"Enter the high value of range:"<<endl;
    cin>>high;
    cout<<"total sum of all the nodes value lie in range: "<<rangeSumBst(root,low,high)<<endl;
    return 0;
}