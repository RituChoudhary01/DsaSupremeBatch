// Replace elements with least greater element to its right.
// https://www.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <iostream>
#include<vector>
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
Node* insert(Node* root,int val,int &succ){
    if(!root) return new Node(val);
    if(val>=root->data){
        root->right = insert(root->right,val,succ);
    }
    else{
        succ = root->data;
        root->left = insert(root->left,val,succ);
    }
    return root;
}
vector<int>findLeastGreater(vector<int>& arr,int n){
    vector<int>ans(arr.size(),-1);
    Node* root = 0;
    for(int i=arr.size()-1;i>=0;i--){
        int succ = -1;
        root = insert(root,arr[i],succ);
        ans[i]=succ;
    }
        return ans;
    }
int main(){
    vector<int>arr;
    int n;
    cout<<"Enter size of vector:"<<endl;
    cin>>n;
    cout<<"Enter element:"<<endl;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        arr.push_back(input);
    }
    vector<int>ans = findLeastGreater(arr,n);
    cout<<"least next greater element "<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}