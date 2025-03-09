#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
// Insertion in BST
Node* insertIntoBST(Node* root,int data){
    if(root == NULL){
        // this is first node we have to create
        root = new Node(data);
        return root;
    }
    if(root->data>data){
     root->left = insertIntoBST(root->left,data);
    }
    else{
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}
// take input to insert node into BST
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}
void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			cout << temp->data << " ";
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
	}
}

// Q1.to check given tree is valid BST
// https://leetcode.com/problems/validate-binary-search-tree/description/
bool isValidBST_helper(Node* root, long long int lb, long long int ub) {
    //base case
    if(root == NULL)
        return true;
    
    if(root->data > lb && root->data < ub) {
        bool leftAns = isValidBST_helper(root->left, lb, root->data);
        bool rightAns = isValidBST_helper(root->right, root->data, ub);
        return leftAns && rightAns;
    }
    else {
        return false;
    }

}
    bool isValidBST(Node* root) {
        long long int lowerBound = -4294967296;//(INT_MIN-1)
        long long int upperBound = 4294967296;//INT_MAX+2
        bool ans  = isValidBST_helper(root, lowerBound, upperBound );
        return ans;
    }

    //Q2.Lowest common Ancestor in bst
    // https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(root==NULL) return NULL;
        if(p->data<root->data && q->data<root->data)
        return lowestCommonAncestor(root->left,p,q);
        if(p->data>root->data && q->data>root->data)
        return lowestCommonAncestor(root->right,p,q);
        return root;
    } 

    // Q3.Kth smallest Node
    // https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
    int kthSmallest(Node* root, int k) {
        // base case
        if(!root) return -1;
        int leftAns = kthSmallest(root->left,k);
        if(leftAns!= -1) return leftAns;
        k--;
        if(k==0) return root->data;
        int rightAns = kthSmallest(root->right,k);
        return rightAns;
    }

    // Q4.Convert Inorder into BST
    // 
    Node* bstUsingInorder(int inorder[],int s,int e){
        if(s>e) return NULL;
        int mid = (s+e)/2;
        int element = inorder[mid];
        Node* root = new Node(element);
        root->left = bstUsingInorder(inorder,s,mid-1);
        root->right = bstUsingInorder(inorder,mid+1,e);
        return root;
    }

    // Q5.Sum of two Node of BST is equal to target
    // https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
    void storeInorder(Node* root, vector<int> &inorder) {
        if(root == NULL) return;
        storeInorder(root->left, inorder);
        inorder.push_back(root->data);
        storeInorder(root->right, inorder);
    }
     bool findTarget(Node* root, int k) {
     vector<int> inorder;
     storeInorder(root, inorder);
      int s = 0;
      int e = inorder.size() - 1;
      while(s < e) {
        int sum = inorder[s] + inorder[e];
         if(sum == k )return true;
         if(sum > k)e--;
            else s++;
        }
     return false;
     }

int main(){
int inorder[10] = {1,2,3,4,5,6,7,8,9,10};
Node* root = bstUsingInorder(inorder,0,9);
cout<<"Print BST: "<<endl;
levelOrderTraversal(root);
return 0;
}
