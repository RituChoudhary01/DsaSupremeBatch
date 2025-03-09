/*
Tree:- Tree is non linear data structure.
root:-the root is the topmost node of the tree.The root node has no parent, and every tree has exactly one root node.
node:- A node is a fundamental component of data structures like trees and linked lists.Each node contains data and may link to other nodes, establishing relationships within the structure.
parent:- In a tree, a parent node is a node that has a branch to another node, which is called a child node. The parent node is the predecessor of the child node
child:-  a node that is directly below another node, called its parent.
ancestor:- The ancestors of a node include that node, the parent of that node, the grandparent of that node, and so on up to the root.
descendant:-n a tree, a descendant of a node is any node that lies in its subtree. In simple terms, a node’s descendants include its children, grandchildren, great-grandchildren, and so on. 
sibling:- siblings are nodes that share the same parent
leaf:-A leaf node is a node in a tree that has no children.

*/ 
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
// level order traversal
void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
              q.push(temp->right);  
            }
        }
    }
}
// inorder traversal
void inorderTraversal(Node* root){
	//base case
	if(root == NULL){
		return ;
	}
    //LNR
	inorderTraversal(root->left);
	cout << root -> data << " ";
	inorderTraversal(root->right);
}
// preorder traversal
void preorderTraversal(Node* root) {
	//base case
	if(root == NULL) {
		return ;
	}
    //NLR
	cout << root -> data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

// postorder traversal
void postorderTraversal(Node* root) {
	if(root == NULL)
		return;

	//LRN
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root -> data << " ";
}

// to find height of tree
int height(Node* root) {
	if(root == NULL) return 0;
    int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	int ans = max(leftHeight, rightHeight) + 1;
	return ans;
}
int main() {
	Node* root = NULL;
    root = buildTree();
	levelOrderTraversal(root);
    // inorderTraversal(root);
	cout << "height: "<< height(root) << endl;
    return 0;
}

// Q function to find diameter of tree
int maxDepth(Node* root) {
        if(root == NULL) 
		return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int ans = max(leftHeight, rightHeight) + 1;
        return ans;
    }
    int diameterOfBinaryTree(Node* root) {
        if(root == NULL) 
        return 0;

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxDepth(root->left) + 1 + maxDepth(root->right);
        int ans = max(op1, max(op2, op3));
        return ans ;
    }
