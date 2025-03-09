#include <iostream>
#include<vector>
using namespace std;

class Node{
	public:
	int data;	
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

Node* buildTree() {
	int data; 
	cout << "Enter the data: " << endl;
	cin >> data;
    if(data == -1) {
		return NULL;
	}
	Node* root = new Node(data);
    cout << "Enter data for left part of " << data << " node " << endl;
	root->left = buildTree();
	
	cout << "Enter data for right part of " << data << " node " << endl;
	root-> right = buildTree();
    return root;
}
//Q1. check for balanced tree
// https://leetcode.com/problems/balanced-binary-tree/description/
 int height(Node* root) {
        //base case
        if(root == NULL)
            return 0;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int ans = 1 + max(leftHeight, rightHeight);
        return ans;
    }
    bool isBalanced(Node* root){
        //Base case
        if(root == NULL)
            return true;
        // for 1 case
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);
        bool ans1 = (diff <= 1);
        //Recursion
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);
        if(ans1 && leftAns && rightAns)
            return true;
        else
            return false;
    }

    // Q2.lowest common Ancestor
    // https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
   Node* lowestCommonAncestor(Node* root,Node* p, Node* q){
        //base case
        if(root == NULL)
            return NULL;

        //check for p and q;
        if(root->data == p->data)
            return p;
        if(root->data == q->data)
            return q;
        
         Node* leftAns = lowestCommonAncestor(root->left,p,q);
         Node* rightAns = lowestCommonAncestor(root->right,p,q);

        if(leftAns == NULL && rightAns == NULL)
            return NULL;
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
        else{
            return root;
        }
    }
    // Q3.path sum II
    // https://leetcode.com/problems/path-sum-ii/
     void solve(Node* root, int targetSum , int &currSum, vector<int> &path, vector<vector<int> > &ans){
        //base case
        if(root == NULL) {
            return;
        }
        //Leaf Node
        if(root->left == NULL && root->right == NULL) {
            //include curr node
            path.push_back(root->data);
            currSum += root->data;
            //check for target sum
            if(currSum == targetSum) {
                ans.push_back(path);
            }
            //exclude 
            path.pop_back();
            currSum -= root->data;
            return;
        }
        //include curr node
        path.push_back(root->data);
        currSum += root->data;
        solve(root->left, targetSum, currSum, path, ans);
        solve(root->right, targetSum, currSum, path, ans);
        //backltrack
        path.pop_back();
        currSum -= root->data;
        }
        vector<vector<int> > pathSum(Node* root, int targetSum){
        vector<vector<int> > ans;
        int sum = 0;
        vector<int> temp;
        solve(root, targetSum, sum, temp, ans);
        return ans;
    }

    // Q4.Kth Ancestor of a node
    bool kthAncestor(Node* root, int &k , int p) {
	//base case
	if(root == NULL)
		return false;
    if(root->data == p) {
		return true;
	}
    bool leftAns = kthAncestor(root->left, k , p);
	bool rightAns = kthAncestor(root->right, k , p);
	if(leftAns || rightAns)
		k--;
	if(k == 0) {
		cout << "Answer: " << root->data << endl;
		k = -1;
	}
	return leftAns || rightAns;
	}
    int main() {
 	Node* root = NULL;
	root = buildTree();
    // cout<<isBalanced(root)<<endl;

    // int p,q;
    // cin>>p>>q;
    // lowestCommonAncestor(root,p,q);

    // int targetSum;
    // cout<<"Enter targetSum: "<<endl;
    // cin>>targetSum;
    // vector<vector<int> >ans =  pathSum(root,targetSum);
    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[0].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // int k =1;
	// int p = 4;
	// bool found = kthAncestor(root, k, p);
    return 0;
}