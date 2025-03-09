#include <iostream>
#include <queue>
using namespace std;
/*
// STL of  priorityqueue
int main() {
  //max-heap
  priority_queue<int> pq;
  pq.push(3);
  pq.push(6);
  pq.push(9);
  pq.push(4);
  pq.push(8);

  cout << "top element: " << pq.top() << endl;
  pq.pop();
  cout << "top element: " << pq.top() << endl;
  pq.pop();
  cout << "top element: " << pq.top() << endl;
  pq.pop();
  cout << "top element: " << pq.top() << endl;
  pq.pop();
  cout << "top element: " << pq.top() << endl;
  pq.pop();
  cout << "Size: " << pq.size() << endl;
  if(pq.empty()) {
          cout << "Max heap is empty" << endl;
  }
  else {
          cout << "Max heap is not empty" << endl;
  }

    //  Min-heap
        priority_queue<int,vector<int>, greater<int> > pq;
        pq.push(3);
        pq.push(6);
        pq.push(9);
        pq.push(4);
        pq.push(8);

        cout << "top element: " << pq.top() << endl;
        pq.pop();
        cout << "Size: " << pq.size() << endl;
        cout << "top element: " << pq.top() << endl;
        pq.pop();
        cout << "top element: " << pq.top() << endl;
        pq.pop();
        cout << "top element: " << pq.top() << endl;
        pq.pop();
        cout << "top element: " << pq.top() << endl;
        pq.pop();

          if(pq.empty()) {
          cout << "Min heap is empty" << endl;
     }
      else {
          cout << "Min heap is not empty" << endl;
    }
     return 0;
}*/
/*
// to find kth greatest element in heap
int getKthGreatestElement(int arr[],int n,int k){
    // create min heap
    priority_queue<int,vector<int>,greater<int> >pq;
    // insert inital k elements of array
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    // for remaining elements,push only if they are greater than top
    for(int i=k;i<n;i++){
        int element = arr[i];
        if(element>pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}
// to find kth smallest element in heap
int getKthSmallestElement(int arr[],int n,int k){
    // create max heap
    priority_queue<int>pq;
    // insert inital k elements of array
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    // for remaining elements,push only if they are less than top
    for(int i=k;i<n;i++){
        int element = arr[i];
        if(element < pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}
int main() {
        int arr[] = {10,5,20,4,15};
        int n = 5;
        int k = 5;
        cout << k<<"th smallest element in heap is: " << getKthSmallestElement(arr,n,k)<< endl;
       cout << k<<"th Greatest element in heap is: " <<    getKthGreatestElement(arr, n, k )<< endl;
        return 0;
}
*/
// Q. IS Complate Binary Tree is Heap.

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to check if the binary tree is a Complete Binary Tree (CBT)
bool isComplete(Node* root) {
    if (!root) return true;

    queue<Node*> q;
    q.push(root);
    bool end = false; // Flag to indicate when we encounter a non-full node

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left) {
            if (end) return false; // If we have seen a non-full node before, return false
            q.push(temp->left);
        } else {
            end = true; // No left child means all further nodes should not have children
        }

        if (temp->right) {
            if (end) return false; // If we have seen a non-full node before, return false
            q.push(temp->right);
        } else {
            end = true;
        }
    }
    return true;
}

// Function to check if the binary tree follows the Max Heap property
bool isHeapProperty(Node* root) {
    if (!root) return true;

    if (root->left && root->data < root->left->data) return false;
    if (root->right && root->data < root->right->data) return false;

    return isHeapProperty(root->left) && isHeapProperty(root->right);
}

// Function to check if the given binary tree is a heap
bool isHeap(Node* root) {
    return isComplete(root) && isHeapProperty(root);
}

// Function to take level-wise input for a binary tree (not a BST)
Node* takeInput() {
    cout << "Enter root node value: ";
    int data;
    cin >> data;
    if (data == -1) return NULL;

    Node* root = new Node(data);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left child of " << temp->data << " (-1 for NULL): ";
        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << " (-1 for NULL): ";
        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}

int main() {
    Node* root = takeInput();
    cout << "Is the given binary tree a Heap? " << (isHeap(root) ? "Yes" : "No") << endl;
    return 0;
}
