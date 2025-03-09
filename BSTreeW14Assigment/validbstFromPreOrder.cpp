// valid BST from PreOrder 
// https://www.interviewbit.com/problems/valid-bst-from-preorder/

#include<iostream>
#include<vector>
using namespace std;
void build(int &i,int min,int max,vector<int>&A){
    if(i>=A.size()) return;
    if(A[i]>min&&A[i]<max){
        int rootData = A[i++];
        build(i,min,rootData,A);
        build(i,rootData,max,A);
    }
}
bool solve(vector<int>&A){
    int min = INT_MIN;
    int max = INT_MAX;
    int i=0;
    build(i,min,max,A);
    return i==A.size();
}
int main(){
 vector<int>pre;
    int n;
    cout<<"Enter size of vector:"<<endl;
    cin>>n;
    cout<<"Enter element:"<<endl;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        pre.push_back(input);
    }
    cout<<"Give preOrder traversal of BST is Valid: "<<solve(pre)<<endl;
    return 0;
}

