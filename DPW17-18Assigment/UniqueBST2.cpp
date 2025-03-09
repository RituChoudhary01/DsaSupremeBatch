// Unique Binary Search Trees II 
// https://leetcode.com/problems/unique-binary-search-trees-ii/description/


// TreeNode* buildTree(){
// 	int data; 
// 	cout << "Enter the data: " << endl;
// 	cin >> data;
//     if(data == -1){
// 		return NULL;
// 	}
// 	TreeNode* root = new TreeNode(data);
//     cout << "Enter data for left part of " << data << " node " << endl;
// 	root->left = buildTree();
	
// 	cout << "Enter data for right part of " << data << " node " << endl;
// 	root-> right = buildTree();
//     return root;
// }
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class TreeNode{
	public:
	int val;	
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

vector<TreeNode*> allPossibleBSTs(int start, int end) {
    // Base Case
    if (start > end) return {nullptr};  // Important: Return a vector with nullptr for empty subtrees.
    if (start == end) return {new TreeNode(start)};

    vector<TreeNode*> ans;
    for (int i = start; i <= end; i++) {
        vector<TreeNode*> left = allPossibleBSTs(start, i - 1);
        vector<TreeNode*> right = allPossibleBSTs(i + 1, end);

        for (TreeNode* l : left) {
            for (TreeNode* r : right) {
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
    }
    return ans;
}

map<pair<int, int>, vector<TreeNode*>> dp;
vector<TreeNode*> allPossibleBSTsTD(int start, int end) {
    // Base case
    if (start > end) return {nullptr}; 
    if (start == end) return {new TreeNode(start)};

    // Memoization check
    if (dp.find({start, end}) != dp.end()) return dp[{start, end}];

    vector<TreeNode*> ans;
    for (int i = start; i <= end; i++) {
        vector<TreeNode*> left = allPossibleBSTsTD(start, i - 1);
        vector<TreeNode*> right = allPossibleBSTsTD(i + 1, end);

        for (TreeNode* l : left) {
            for (TreeNode* r : right) {
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
    }
    return dp[{start, end}] = ans;
}
vector<TreeNode*>generateTrees(int n){
    if(n==0)return {};
    return allPossibleBSTs(1, n);
}