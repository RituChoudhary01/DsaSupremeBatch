// Diameter of tree
// https://leetcode.com/problems/diameter-of-binary-tree/description/

#include<iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 TreeNode* buildTree() {
	int data; 
	cout << "Enter the data: " << endl;
	cin >> data;
    if(data == -1) {
		return NULL;
	}
	TreeNode* root = new TreeNode(data);
    cout << "Enter data for left part of " << data << " node " << endl;
	root->left = buildTree();
	
	cout << "Enter data for right part of " << data << " node " << endl;
	root-> right = buildTree();
    return root;
}
// Method1
int maxDepth(TreeNode* root){
if(root == NULL) return 0;
int leftDepth = maxDepth(root->left);
int rightDepth = maxDepth(root->right);
int ans = max(leftDepth,rightDepth)+1;
return ans;
}
int diameterOfBinartTree(TreeNode* root){
    if(root == NULL) return 0;
    int op1 = diameterOfBinartTree(root->left);
    int op2 = diameterOfBinartTree(root->right);
    int op3 = maxDepth(root->left)+1+maxDepth(root->right);
    int ans = max(op1,max(op2,op3));
    return ans;
}
// Method 2
int D = 0;
int height(TreeNode* root){
    if(!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    // diameter
    int currD = lh+rh;
    D = max(D,currD);
    return max(lh,rh)+1;
}
int diameterofBT(TreeNode* root){
    return maxDepth(root);
    // height(root);
    // return D;
}
int main(){
TreeNode* root = NULL;
 root = buildTree();
 int dia = diameterofBT(root);
 cout<<"Diameter of tree is: "<<dia<<endl;
 return 0;
}

