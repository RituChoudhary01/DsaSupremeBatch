// Brother From Different Roots
// https://www.geeksforgeeks.org/problems/brothers-from-different-root/1

#include <iostream>
#include<stack>
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
 int countPairs(Node* root1, Node* root2, int x){
 int ans = 0;
 stack<Node*>s1,s2;
 Node* a = root1;
 Node* b = root2;
 while(1){
    while(a){
        // inorder
        s1.push(a);
        a = a->left;
    }
    while(b){
        s2.push(b);
        b = b->right;
    }
    if(s1.empty()||s2.empty()){
        break;
    }
    auto atop = s1.top();
    auto btop = s2.top();
    int sum = atop->data+btop->data;
    if(sum==x){
        ans++;
       s1.pop();
       s2.pop();
       a = atop->right;
       b = btop->left;
    }
    else if(sum<x){
        s1.pop();
        a = atop->right;
      }
    else{
        s2.pop();
        b = btop->left;
    }  
 }
 return ans;
}
int main(){
    cout<<"Enter the data for 1st tree: "<<endl;
    Node* root1 = NULL;
    takeInput(root1);
    cout<<"Enter the data for 2nd tree: "<<endl;
    Node* root2 = NULL;
    takeInput(root2);
    int targetSum;
    cout<<"Enter the target Sum: "<<endl;
    cin>>targetSum;
    cout<<"Total number of pair present:"<<countPairs(root1,root2,targetSum)<<endl;
    return 0;
}