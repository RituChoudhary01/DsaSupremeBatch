// Transform to sum tree
// https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1

#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;
struct Node{
      int data;
      Node *left;
      Node *right;
      Node(int x) : data(x), left(NULL), right(NULL) {}
 };

    Node* buildTree(){
	int data; 
	cout << "Enter the data: " << endl;
	cin >> data;
    if(data == -1){
	  return NULL;
	}
	Node* root = new Node(data);
    cout << "Enter data for left part of " << data << " node " << endl;
	root->left = buildTree();
	
	cout << "Enter data for right part of " << data << " node " << endl;
	root-> right = buildTree();
    return root;
}
void levelOrderTraversal(Node* root){
    queue<Node*>q;
    // initially
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

int sum(Node* root){
    if(!root) return 0;
    if(!root->left && !root->right){
        int temp = root->data;
        root->data = 0;
        return temp;
    }
    int lsum = sum(root->left);
    int rsum = sum(root->right);
    int temp = root->data;
    root->data = lsum+rsum;
    return root->data+temp;
}
void toSumTree(Node* node){
    sum(node);
}
int main(){
Node* root = NULL;
root = buildTree();
levelOrderTraversal(root);
toSumTree(root);
cout<<endl;
levelOrderTraversal(root);
return 0;
}
