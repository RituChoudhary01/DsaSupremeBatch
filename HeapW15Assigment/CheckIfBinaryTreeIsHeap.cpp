// Is Binary Tree Heap
// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node* buildTree(){
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;
    if(data == -1) return NULL;
    Node* root = new Node(data);
    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();
    cout<<"Enter data for right part of "<<data<<" node"<<endl;
    root->right = buildTree();
    return root;
}
int nodeCount(struct Node* root){
    if(!root) return 0;
    int l = nodeCount(root->left);
    int r = nodeCount(root->right);
    return 1+l+r;
    }
    bool isCBT(struct Node* root,int i,int &n){
        if(!root) return true;
        if(i>n) return false;
        return isCBT(root->left,2*i,n)&&isCBT(root->right,2*i+1,n);
    }
    bool isMaxOrder(struct Node* root){
        if(!root) return true;
        int l = isMaxOrder(root->left);
        int r = isMaxOrder(root->right);
        int ans = false;
        if(!root->left && !root->right){
            ans = true;
        }
        else if(root->left && !root->right){
            ans = root->data>root->left->data;
        }
        else{
            ans = root->data>root->left->data&&root->data>root->right->data;
        }
        return ans&&l&&r;
    }
    bool isHeap(struct Node* tree){
        int n  = nodeCount(tree);
        int i=1;
        return isCBT(tree,i,n)&&isMaxOrder(tree);
    }
    int main() {
    Node* root = NULL;
    root = buildTree();
    cout<<"Binary tree is Heap: "<<isHeap(root)<<endl;
    }