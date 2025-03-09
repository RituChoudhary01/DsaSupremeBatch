// House Robber III.
// https://leetcode.com/problems/house-robber-iii/

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class TreeNode {
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

TreeNode* buildTree() {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;
    if (data == -1) return NULL;
    TreeNode* root = new TreeNode(data);
    cout << "Enter data for left part of " << data << " node " << endl;
    root->left = buildTree();
    cout << "Enter data for right part of " << data << " node" << endl;
    root->right = buildTree();
    return root;
}

// Recursion Approach
int solve(TreeNode* root) {
    if (!root) return 0;
    
    int robThisHouse = root->val;
    
    if (root->left) {
        robThisHouse += solve(root->left->left) + solve(root->left->right);
    }
    
    if (root->right) {
        robThisHouse += solve(root->right->left) + solve(root->right->right);
    }
    
    int dontRobThisHouse = solve(root->left) + solve(root->right);
    
    return max(robThisHouse, dontRobThisHouse);
}

// Top Down Memoization (DP)
int solveTD(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
    if (!root) return 0;
    
    if (dp.find(root) != dp.end()) return dp[root];

    int robThisHouse = root->val;
    
    if (root->left) {
        robThisHouse += solveTD(root->left->left, dp) + solveTD(root->left->right, dp);
    }
    
    if (root->right) {
        robThisHouse += solveTD(root->right->left, dp) + solveTD(root->right->right, dp);
    }
    
    int dontRobThisHouse = solveTD(root->left, dp) + solveTD(root->right, dp);
    
    dp[root] = max(robThisHouse, dontRobThisHouse);
    return dp[root];
}

int main() {
    TreeNode* root = NULL;
    root = buildTree();

    cout << "Maximum amount of money the thief can rob using Recursion: " << solve(root) << endl;

    unordered_map<TreeNode*, int> dp;
    cout << "Maximum amount of money the thief can rob using Top Down DP: " << solveTD(root, dp) << endl;

    return 0;
}
