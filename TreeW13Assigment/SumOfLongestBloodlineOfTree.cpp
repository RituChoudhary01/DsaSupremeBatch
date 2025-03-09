// Sum of the Longest bloodline of tree
// https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;
struct Node{
      int data;
      Node *left;
      Node *right;
      Node(int x) : data(x), left(NULL), right(NULL) {}
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
pair<int,int>height(Node* root){
    if(!root) return make_pair(0,0);
    auto lh = height(root->left);
    auto rh = height(root->right);
    int sum = root->data;
    if(lh.first == rh.first){
        sum+=lh.second>rh.second?lh.second:rh.second;
    }
    else if(lh.first>rh.first){
        sum+=lh.second;
    }
    else{
        sum+=rh.second;
    }
    return make_pair(max(lh.first,rh.first)+1,sum);
}
int sumofLongRootToLeaf(Node* root){
    auto h = height(root);
    return h.second;
}
int main(){
Node* root = NULL;
 root = buildTree();
 cout<<"Sum of longest bloodline is : "<<sumofLongRootToLeaf(root)<<endl;
 return 0;
}