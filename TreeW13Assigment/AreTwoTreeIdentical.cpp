// Same tree
// https://leetcode.com/problems/same-tree/description/
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
 bool isSameTree(TreeNode* p,TreeNode* q){
    if(!p && !q) return true;
    if(p&&q){
        return (p->val==q->val)&&
               isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
    return false;
 }
 int main(){
TreeNode* root1 = NULL;
 root1 = buildTree();
 TreeNode* root2 = NULL;
 root2 = buildTree();
 cout<<"Both tree are identical or not : "<<isSameTree(root1,root2)<<endl;
 return 0;
}