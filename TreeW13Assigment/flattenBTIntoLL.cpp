// Flatten Binary tree into Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

#include<iostream>
#include<queue>
using namespace std;
struct TreeNode{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 TreeNode* buildTree(){
	int data; 
	cout << "Enter the data: " << endl;
	cin >> data;
    if(data == -1){
	  return NULL;
	}
	TreeNode* root = new TreeNode(data);
    cout << "Enter data for left part of " << data << " node " << endl;
	root->left = buildTree();
	
	cout << "Enter data for right part of " << data << " node " << endl;
	root-> right = buildTree();
    return root;
}
void levelOrderTraversal(TreeNode* root){
    queue<TreeNode*>q;
    // initially
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->val<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
              q.push(temp->right);  
            }
        }
    }
}
 void flatten(TreeNode* root) {
        
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* pred = curr->left;
                while(pred->right)
                pred = pred->right;
                
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
int main(){
TreeNode* root = NULL;
 root = buildTree();
 levelOrderTraversal(root);
 flatten(root);
 cout<<"flatten into linked list: "<<endl;
 levelOrderTraversal(root);
 return 0;
}