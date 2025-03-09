// Symmetric Tree or Mirror Tree
// https://leetcode.com/problems/symmetric-tree/description/?envType=problem-list-v2&envId=tree&difficulty=EASY
#include<iostream>
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
 bool isMirror(TreeNode* p,TreeNode* q){
    if(!p && !q) return true;
    if(p && q){
        return (p->val == q->val)&& isMirror(p->left,q->right)&&
        isMirror(p->right,q->left);
    }
    return false;
 }
 bool isSymmetric(TreeNode* root){
    return isMirror(root->left,root->right);
 }
 int main(){
TreeNode* root1 = NULL;
 root1 = buildTree();
 cout<<"Tree are symmetric or not : "<<isSymmetric(root1)<<endl;
 return 0;
}