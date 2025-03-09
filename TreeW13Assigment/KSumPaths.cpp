// Path Sum III
//https://leetcode.com/problems/path-sum-iii/description/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to build the tree from user input
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
int ans = 0;
void pathFromOneRoot(TreeNode* root, int sum){
    if(!root) return;
    if(sum == root->val){
        ans++;
    }
    pathFromOneRoot(root->left,sum-root->val);
    pathFromOneRoot(root->right,sum-root->val);
}
int pathSum(TreeNode* root,int targetSum){
    if(root){
        pathFromOneRoot(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
    }
    return ans;
}
int main(){
TreeNode* root = NULL;
 root = buildTree();
 int targetSum;
 cout<<"Enter the target sum: "<<endl;
 cin>>targetSum;
 cout<<"The paths that sum is equal to target sum is : "<<pathSum(root,targetSum)<<endl;
 return 0;
}