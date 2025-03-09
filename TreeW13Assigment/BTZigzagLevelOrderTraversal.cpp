// Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
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
// Function to perform zigzag level order traversal
vector<vector<int> > zigzagLO(TreeNode* root) {
    vector<vector<int> > ans;
    
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);
    // True means Left to Right, False means Right to Left
    bool LtoRdir = true;

    while (!q.empty()) {
        int width = q.size();
        vector<int> oneLevel(width);

        for (int i = 0; i < width; i++) {
            TreeNode* front = q.front();
            q.pop();

            // Correct index calculation
            int index = LtoRdir ? i : (width - i - 1);
            oneLevel[index] = front->val;

            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }

        // Toggle the direction for the next level
        LtoRdir = !LtoRdir;
        ans.push_back(oneLevel);
    }
    return ans;
}

int main() {
    TreeNode* root = buildTree();

    vector<vector<int> > ans = zigzagLO(root);

    cout << "\nZigzag Level Order Traversal of the tree:" << endl;
    for (auto level : ans) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

