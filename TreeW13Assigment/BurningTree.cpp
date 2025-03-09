// Burning Tree
// https://www.geeksforgeeks.org/problems/burning-tree/1

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(){
	int data; 
	cout << "Enter the data: " << endl;
	cin >> data;
    if(data == -1){
	  return NULL;
	}
	Node* root = new Node(data);
    cout << "Enter data for left part of " << data << " node " << endl;
	root->left = buildTree();
	
	cout << "Enter data for right part of " << data << " node " << endl;
	root-> right = buildTree();
    return root;
}

// Function to create parent mapping and find the target node.
Node* makeNodeToParentMappingAndFindTargetNode(Node* root, unordered_map<Node*, Node*>& parentMap, int target) {
    queue<Node*> q;
    Node* targetNode = nullptr;
    q.push(root);
    parentMap[root] = nullptr;
    while (!q.empty()) {
        Node* front = q.front();
        q.pop();
        if (front->data == target) {
            targetNode = front;
        }
        if (front->left) {
            q.push(front->left);
            parentMap[front->left] = front;
        }
        if (front->right) {
            q.push(front->right);
            parentMap[front->right] = front;
        }
    }
    return targetNode;
}

// Function to simulate burning the tree and calculate the time taken.
int burnTheTree(Node* targetNode, unordered_map<Node*, Node*>& parentMap) {
    unordered_map<Node*, bool> isBurnt;
    queue<Node*> q;
    int time = 0;
    q.push(targetNode);
    isBurnt[targetNode] = true;
    while (!q.empty()) {
        int size = q.size();
        bool isFireSpreaded = false;
        for (int i = 0; i < size; i++) {
            Node* front = q.front();
            q.pop();
            if (front->left && !isBurnt[front->left]) {
                q.push(front->left);
                isBurnt[front->left] = true;
                isFireSpreaded = true;
            }
            if (front->right && !isBurnt[front->right]) {
                q.push(front->right);
                isBurnt[front->right] = true;
                isFireSpreaded = true;
            }
            if (parentMap[front] && !isBurnt[parentMap[front]]) {
                q.push(parentMap[front]);
                isBurnt[parentMap[front]] = true;
                isFireSpreaded = true;
            }
        }
        if (isFireSpreaded) {
            time++;
        }
    }
    return time;
}

int minTime(Node* root, int target) {
    unordered_map<Node*, Node*> parentMap;
    Node* targetNode = makeNodeToParentMappingAndFindTargetNode(root, parentMap, target);
    if (targetNode == nullptr) {
        cout << "Target node not found in the tree." << endl;
        return -1;
    }
    return burnTheTree(targetNode, parentMap);
}

int main() {
    cout << "Build the tree:" << endl;
    Node* root = buildTree();
    int target;
    cout << "Enter the target node value: ";
    cin >> target;
    int result = minTime(root, target);
    if (result != -1) {
        cout << "Minimum time to burn the tree starting from node " << target << " is: " << result << " seconds." << endl;
    }
    return 0;
}
