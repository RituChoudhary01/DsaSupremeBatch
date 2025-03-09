// Print all subarrays using RE
#include<iostream>
using namespace std;
void printSubarray_util(int nums[],int n,int start,int end){
    if(end==n) return;
    // 1 case
    for(int i=start;i<=end;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    // RE
    printSubarray_util(nums,n,start,end+1);
}
void printSubarray(int nums[],int n){
    for(int start = 0;start<n;start++){
        int end = start;
        printSubarray_util(nums,n,start,end);
    }
}
int main(){
    int nums[]={1,2,3,4,5};
    int n = sizeof(nums)/sizeof(nums[0]);
    printSubarray(nums,n);
    return 0;
}