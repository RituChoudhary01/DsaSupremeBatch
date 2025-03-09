// vertical order Traversal
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
TreeNode* buildTree() {
    int data;
    cout << "Enter the data (-1 for NULL): ";
    cin >> data;
    
    if (data == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(data);
    cout << "Enter data for left child of " << data << " (Enter -1 for NULL):" << endl;
    root->left = buildTree();

    cout << "Enter data for right child of " << data << " (Enter -1 for NULL):" << endl;
    root->right = buildTree();

    return root;
}

// Function for vertical order traversal
vector<vector<int> > verticalTraversal(TreeNode* root) {
    vector<vector<int> > ans;
    if (!root) return ans; 

    queue<pair<TreeNode*, pair<int, int> > > q;
    q.push(make_pair(root,make_pair(0, 0)));
    map<int, map<int, multiset<int> > > mp; // Column -> (Row -> Set of Values)

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        TreeNode* node = front.first;
        int row = front.second.first;
        int col = front.second.second;

        mp[col][row].insert(node->val);

        if (node->left) {
            q.push(make_pair(node->left,make_pair(row + 1, col - 1)));
        }
        if (node->right) {
            q.push(make_pair(node->right, make_pair(row + 1, col + 1)));
        }
    }

    // Extracting the ordered values from the map
    for (auto it : mp) {
        vector<int> vLine;
        for (auto colMapIt : it.second) {
            vLine.insert(vLine.end(), colMapIt.second.begin(), colMapIt.second.end());
        }
        ans.push_back(vLine);
    }

    return ans;
}

int main() {
    TreeNode* root = buildTree();

    vector<vector<int> > ans = verticalTraversal(root);

    cout << "\nVertical Traversal of the tree:" << endl;
    for (auto level : ans) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
// 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    return 0;
}
