// Merge Two BST's 
// https://www.geeksforgeeks.org/problems/merge-two-bst-s/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <iostream>
#include<vector>
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
vector<int>merge(Node* root1,Node* root2){
    vector<int>ans;
    stack<Node*>sa,sb;
    Node* a = root1,*b = root2;
    while(a||b||!sa.empty()||!sb.empty()){
        while(a){
            sa.push(a);
            a = a->left;
        }
        while(b){
            sb.push(b);
            b = b->left;
        }
        if(sb.empty()||(!sa.empty() && sa.top()->data<=sb.top()->data)){
            auto atop = sa.top();
            ans.push_back(atop->data);
            sa.pop();
            a = atop->right;
        }
        else{
            auto btop = sb.top();
            sb.pop();
            ans.push_back(btop->data);
            b = btop->right;
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
    vector<int>ans = merge(root1,root2);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}