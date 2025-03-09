// Diagonal Traversal of binary tree
//https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

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
// Method1
void diagnalHelper(Node* root,int d,map<int,vector<int> >&mp){
if(!root) return;
mp[d].push_back(root->data);
diagnalHelper(root->left,d+1,mp);
diagnalHelper(root->right,d,mp);
}
vector<int>diagonal(Node* root){
    vector<int>ans;
    if(!root) return ans;
    map<int,vector<int> >mp;
    int d = 0;
    diagnalHelper(root,d,mp);
    for(auto it:mp){
        for(auto j:it.second){
            ans.push_back(j);
        }
    }
    return ans;
}
// Method 2
// vector<int>diagonal(Node* root){
//     vector<int>ans;
//     if(!root) return ans;
//     queue<Node*>q;
//     q.push(root);
//     while(!q.empty()){
//         Node* temp = q.front();
//         q.pop();
//         while(temp){
//             ans.push_back(temp->data);
//             if(temp->left){
//                 q.push(temp->left);
//             }
//             temp = temp->right;
//         }
//     }
//     return ans;
// }
int main(){
Node* root = NULL;
 root = buildTree();
  vector<int>digTrav = diagonal(root);
 cout<<"Diagnoal traversal of tree is : "<<endl;
 for(auto it:digTrav) 
  cout<<it<<" ";
  cout<<endl;
  return 0;
}
