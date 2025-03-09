// Find the height Balance Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/description/

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
    // Method 1
    int height(TreeNode* root){
    // base case
    if(!root) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = 1 + max(leftHeight,rightHeight);
    return ans;
}
bool isBalanced(TreeNode* root){
    // Base case
    if(!root) return true;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int diff = abs(leftHeight-rightHeight);
    bool ans1 = (diff <= 1);
    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);
    if(ans1 && leftAns && rightAns) return true;
    else return false;
}

// Method 2
bool isBalance = true;
int height1(TreeNode* root){
if(!root) return 0;
int lh = height1(root->left);
int rh = height1(root->right);
if(isBalance && abs(lh-rh)>1){
    isBalance = false;
}
return max(lh,rh)+1;
}
bool isBalancedTree(TreeNode* root){
    height1(root);
    return isBalance;
}
int main(){
TreeNode* root = NULL;
 root = buildTree();
//  bool isBal = isBalanced (root);
 bool isBal = isBalancedTree(root);
 cout<<"Tree is balance or not : "<<isBal<<endl;
 return 0;
}
