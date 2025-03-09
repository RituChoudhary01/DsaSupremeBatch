// Find Median Of BST
// https://www.geeksforgeeks.org/problems/median-of-bst/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <iostream>
#include<stack>
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

// Insertion in BST
Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

// Take input to insert nodes into BST
void takeInput(Node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}
int findNodeCount(Node* root){
    int count = 0;
    Node* curr = root;
    while(curr){
        if(!curr->left){ count++;
        curr = curr->right;
        }
        else{
            Node* pred = curr->left;
            while(pred->right!=curr && pred->right){
                pred = pred->right;
            }
            if(!pred->right){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                count++;
                curr = curr->right;
            }
        }
    }
   return count;
}
float FindActualMedian(Node* root,int n){
int i=0;
int odd1 = (n+1)/2,odd1Val = -1;
int even = n/2,evenVal = -1;
int even2 = n/2+1,even2Val = -1;
Node* curr = root;
while(curr){
    if(!curr->left){
        i++;
        if(i==odd1) odd1Val = curr->data;
        if(i==even) evenVal = curr->data;
        if(i==even2) even2Val = curr->data;
        curr = curr->right;
    }
    else{
        Node* pred = curr->left;
        while(pred->right != curr && pred->right){
            pred = pred->right;
        }
        if(!pred->right){
            pred->right = curr;
            curr = curr->left;
        }
        else{
            pred->right = NULL;
            i++;
        if(i==odd1) odd1Val = curr->data;
        if(i==even) evenVal = curr->data;
        if(i==even2) even2Val = curr->data;
        curr = curr->right;
        }
    }
}
    float median = 0;
    if((n&1)==0){
        median = (evenVal+even2Val)/2.0;
    }
    else{
        median = odd1Val;
    }
return median;
}
float findMedian(struct Node *root){
    int n = findNodeCount(root);
    return FindActualMedian(root,n);
}
int main() {
    cout << "Enter the tree elements (-1 to stop): " << endl;
    Node* root = NULL;
    takeInput(root);
    cout<<"Median of tree is: "<<findMedian(root)<<endl;
    return 0;
}

