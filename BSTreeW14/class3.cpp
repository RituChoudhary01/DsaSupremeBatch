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
class NodeData {
	public:
	int size;
	int minVal;
	int maxVal;
	bool validBST;

	NodeData() {
		
	}
	NodeData(int size, int max, int min, bool valid) {
		this->size = size;
		minVal = min;
		maxVal = max;
		validBST = valid;
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
// Q1.Convert BST into DLL
void convertIntoSortedDLL(Node* root, Node* &head) {
	//base case
	if(root == NULL ) return;
	//right subtree into LL
	convertIntoSortedDLL(root->right, head);

	//atach root node
	root->right = head;

	if(head != NULL)
		head -> left = root;

	//update head
	head = root;

	//left subtree linked List
	convertIntoSortedDLL(root->left, head);
}
// print DLL
void printLinkedList(Node* head) {
	Node* temp = head;
    cout << endl;
	while(temp != NULL ) {
		cout << temp -> data << " ";
		temp = temp -> right;
	}
	cout << endl;
}
// Q2.
Node* sortedLinkedListIntoBST(Node* &head, int n) {
	//base case
	if(n <= 0 || head == NULL)
		return NULL;

	Node* leftSubtree = sortedLinkedListIntoBST(head, n/2);

	Node* root = head;
	root->left = leftSubtree;

	head = head -> right;
	
	//right part solve karna h 
	root->right = sortedLinkedListIntoBST(head,n-1-n/2);
	return root;
}
// Q3.
NodeData* findLargestBST(Node* root, int &ans) {
	//base case
	if(root == NULL) {
		NodeData* temp  = new NodeData(0, INT_MIN, INT_MAX, true);
		return temp;
	}

	NodeData* leftKaAns = findLargestBST(root->left, ans);
	NodeData* rightKaAns = findLargestBST(root->right,ans);

	//checking starts here
	NodeData* currNodeKaAns = new NodeData();

	currNodeKaAns->size = leftKaAns->size + rightKaAns->size + 1;
	currNodeKaAns->maxVal = max(root->data, rightKaAns->maxVal);
	currNodeKaAns->minVal = min(root->data, leftKaAns->minVal);

	if(leftKaAns->validBST && rightKaAns->validBST && (root->data > leftKaAns->maxVal && root->data < rightKaAns->minVal) ) {
		currNodeKaAns->validBST = true;
	}
	else {
		currNodeKaAns->validBST = false;
	}

	if(currNodeKaAns->validBST) {
		ans = max(ans, currNodeKaAns->size);
	}
	return currNodeKaAns;
}
int main() {
    Node* root = NULL;
    cout<<"Enter the data for Node "<<endl;
    takeInput(root);
    cout<<"Print tree "<<endl;
    levelOrderTraversal(root);
    cout << "printing sorted linked list:" << endl;
	Node* head = NULL;
	convertIntoSortedDLL(root, head);
    printLinkedList(head);

    Node* root1 = NULL;
	root1 =	sortedLinkedListIntoBST(head, 9);
	cout << "Doping level order traversal for root 1" << endl;
	levelOrderTraversal(root1);

    Node* root = new Node(50);
		Node* first = new Node(30);
		Node* second = new Node(60);
		Node* third = new Node(5);
		Node* fourth = new Node(20);
		Node* fifth = new Node(45);
		Node* sixth = new Node(70);
		Node* seventh = new Node(65);
		Node* eight = new Node(80);

		root->left = first;
		root->right = second;
		first->left = third;
		first -> right = fourth;
		second->left = fifth;
		second->right = sixth;
		sixth->left = seventh;
		sixth->right= eight;

      cout << "Printing the tree" << endl;
	  levelOrderTraversal(root);
      
       int ans = 0;
	  findLargestBST(root,ans);
	  cout << "Largest BSK ka Size:  "<< ans << endl;
}