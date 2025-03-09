// Find Duplicate Subtree
// https://www.geeksforgeeks.org/problems/burning-tree/1

#include<iostream>
#include<vector>
#include<unordered_map>
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

vector<TreeNode*>ans;
unordered_map<string,int>subtreeMap;

string preOrder(TreeNode* root){
        if(!root) return "N";
        string curr = to_string(root->val);
        string l = preOrder(root->left);
        string r = preOrder(root->right);
        string s = curr+","+l+","+r;
        if(subtreeMap.find(s)!=subtreeMap.end()){
            if(subtreeMap[s]==1)
            ans.push_back(root);
            subtreeMap[s]++;
        }
        else{
            subtreeMap[s]=1;
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       preOrder(root);
       return ans; 
    }

    void printPreOrder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

    int main(){
   TreeNode* root = NULL;
   root = buildTree();
   cout<<"Duplicate Subtree in a tree is : "<<endl;
   vector<TreeNode*> duplicates = findDuplicateSubtrees(root);
    cout << "Duplicate Subtrees (pre-order traversal):" << endl;
    for (TreeNode* subtreeRoot : duplicates) {
        printPreOrder(subtreeRoot);
        cout << endl;
    }
    return 0;
}
