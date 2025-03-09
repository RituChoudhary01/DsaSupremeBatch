// Built BST using Preorder Traversal
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

#include<iostream>
#include<vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
  TreeNode* build(int &i,int min,int max,vector<int>& preorder){
    if(i>=preorder.size()){
    return nullptr;
    }
    TreeNode* root = nullptr;
    if(preorder[i]>min && preorder[i]<max){
        root = new TreeNode(preorder[i++]);
        root->left = build(i,min,root->val,preorder);
        root->right = build(i,root->val,max,preorder);
    }
    return root;
  }
  TreeNode* bstFromPreorder(vector<int>& preorder){
        int min = INT_MIN;
        int max = INT_MAX;
        int i=0;
        return build(i,min,max,preorder);
    }
int main(){
vector<int> preorder;
int n;
cout<<"Enter the size of preorder traversal:"<<endl;
cin>>n;
cout<<"Enter element of preorder vector: "<<endl;
for(int i=0;i<n;i++){
int input;
cin>>input;
preorder.push_back(input);
}
TreeNode* root = bstFromPreorder(preorder);
cout<<"root is: "<<root->val<<endl;
return 0;
}