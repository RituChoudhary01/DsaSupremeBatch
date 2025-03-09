// Maximum Sum of Non-adjacent nodes.
// https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

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
pair<int,int>getMaxSum_helper(Node* root){
    if(!root) return make_pair(0,0);
    auto left = getMaxSum_helper(root->left);
    auto right = getMaxSum_helper(root->right);
    // sum include the node
    int a = root->data+left.second+right.second;
    // sum excluding the node
    int b = max(left.first,left.second)+max(right.first,right.second);
    return make_pair(a,b);
}
int getMaxSum(Node* root){
    auto ans = getMaxSum_helper(root);
    return max(ans.first,ans.second);
}
int main(){
Node* root = NULL;
 root = buildTree();
 cout<<"Maximum sum of Non-adjacent nodes of tree is : "<<getMaxSum(root)<<endl;
return 0;
}
