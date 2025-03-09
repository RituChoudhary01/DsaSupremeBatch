// Merge two Binary Max heaps
// https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
#include<iostream>
#include<vector>
using namespace std;
void heapify(vector<int>&v,int i,int n){
    while(true){
        int left = 2*i+1;
        int right = 2*i+2;
        int swapIndex = i;
        if(left<n && v[left]>v[i]){
            swapIndex = left;
        }
        if(right<n && v[right]>v[swapIndex]){
            swapIndex = right;
        }
        if(swapIndex == i) break;
        swap(v[i],v[swapIndex]);
        i = swapIndex;
    }
}
vector<int>mergeHeaps(vector<int>&a,vector<int>&b,int n,int m){
    // merge two heap vectors
    vector<int>c(a.begin(),a.end());
    c.insert(c.end(),b.begin(),b.end());
    // let's heapify vector
    for(int i=(c.size()/2-1);i>=0;--i){
        heapify(c,i,c.size());
    }
    return c;
}
int main(){
    int n,m;
    cout<<"Enter size of first heap: "<<endl;
    cin>>n;
    vector<int>heap1,heap2;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        heap1.push_back(input);
    }
    cout<<"Enter size of first heap: "<<endl;
    cin>>m;
    for(int i=0;i<m;i++){
        int input;
        cin>>input;
        heap2.push_back(input);
    }
    vector<int> ans = mergeHeaps(heap1,heap2,n,m);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}