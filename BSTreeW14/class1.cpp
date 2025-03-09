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
// level order of BST
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
// preOrder traversal of BST
void preOrderTraversal(Node* root) {
	//NLR
	if(root == NULL)return;
    cout << root->data << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}
// inorder traversal
void inOrderTraversal(Node* root) {
	//LNR
	if(root == NULL)return;
    inOrderTraversal(root->left);
	cout << root->data << " ";
	inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
	//LRN
	if(root == NULL)return;
    postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << " ";
}
// search a node in BST all node have unide value
Node* findNodeInBST(Node* root,int target){
    // base case
    if(root==NULL) return NULL;
    if(root->data==target) return root;
    if(target>root->data){
      return findNodeInBST(root->right,target);  
    }
    else{
        return findNodeInBST(root->left,target);
    }
}
// find minimum value of BST
int minVal(Node* root){
    Node* temp = root;
    if(temp == NULL) return -1;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}
// find maximum value of BST
int maxVal(Node* root){
    Node* temp = root;
    if(temp == NULL){
        return -1;
    }
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp->data;
}
// delete a node in BST vvvImp.
Node* deleteNodeInBST(Node* root,int target){
    // base case
    if(root==NULL) return NULL;
    if(root->data == target){
        // 4 cases
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        else if(root->left==NULL && root->right==NULL){
            Node* child = root->right;
            return child;
        }
        else if(root->left != NULL && root->right == NULL){
            Node* child = root->left;
            return child;
        }
        else{
            // both child
            // find inorder predecessor in left subtree
            int inorderPre = maxVal(root->left);
            // replace rot->data value with inorder predecessor
            root->data = inorderPre;
            //delete inorder predecessor from left subtree
			root->left = deleteNodeInBST(root->left,inorderPre);
			return root;
        }
    }
    else if(target>root->data){
        root->right = deleteNodeInBST(root->right,target);
    }
    else if(target<root->data){
        root->left = deleteNodeInBST(root->left,target);
    }
    return root;
}

int main(){
Node* root = NULL;
cout<<"Enter the data for Node "<<endl;
takeInput(root);
cout<<"Print tree "<<endl;
levelOrderTraversal(root);
//cout << "Printing Inorder: " << endl;
//inOrderTraversal(root);
// cout << endl;
// cout << "Printing Preorder: " << endl;
// preOrderTraversal(root);
//  cout << endl;
//cout << "Printing Postorder: " << endl;
// postOrderTraversal(root);
// bool ans  = findNodeInBST(root,155);
// cout << "present or not : " << ans << endl;
// cout << endl <<" Minimum value: " << minVal(root) << endl;
// cout << endl << "Maximum value: " << maxVal(root) << endl;
root = deleteNodeInBST(root, 100);
levelOrderTraversal(root);
return 0;
}