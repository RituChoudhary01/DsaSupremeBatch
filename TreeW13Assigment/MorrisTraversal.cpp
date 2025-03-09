// Morris Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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
vector<int>inorderTraversal(TreeNode* root){
    vector<int>ans;
    TreeNode* curr = root;
    while(curr){
        // left node is null,then visit it and go right
        if(curr->left==nullptr){
            ans.push_back(curr->val);
            curr = curr->right;
        }
        // left node is not NULL
        else{
            // find inorder predecessor
            TreeNode* pred = curr->left;
            while(pred->right!=curr && pred->right){
                pred = pred->right;
            }
            // if predecessor node is NULL,then go to left after estasblishing link from predecessor to current
            if(pred->right==nullptr){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                // left is already visited,go right after visiting curr node
                pred->right = nullptr;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
        return ans;
    }
int main(){
TreeNode* root = NULL;
 root = buildTree();
 vector<int> morrTrav = inorderTraversal(root);
 cout<<"Morris traversal of tree is: "<<endl;
 for(auto it:morrTrav)
 cout<<it<<" ";
 cout<<endl;
 return 0;
}
