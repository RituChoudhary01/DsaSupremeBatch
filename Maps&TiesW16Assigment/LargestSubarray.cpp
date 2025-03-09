// Q1.Largest Subarray with 0 sum
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

//Q2. Largest Subarray of 0's and 1's
// https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

#include<iostream>
#include<unordered_map>
using namespace std;
// Largest Subarray with 0 sum
int maxSub(int A[],int n){
   unordered_map<int,int>map;
    int csum = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        csum+=A[i];
        if(csum==0){
            ans = max(ans,i+1);
        }
        else if(map.find(csum)==map.end()){
            map[csum]=i;
        }
        else{
            ans = max(ans,i-map[csum]);
        }
    } 
    return ans;
}
// Largest Subarray of 0's and 1's
int maxLen(int A[],int n){
    unordered_map<int,int>map;
    int csum = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        int val = A[i]==0?-1:1;
        csum+=val;
        if(csum==0){
            ans = max(ans,i+1);
        }
        else if(map.find(csum)==map.end()){
            map[csum]=i;
        }
        else{
            ans = max(ans,i-map[csum]);
        }
    }
    return ans;
}
int main(){
    int arr[8]={15,-2,2,-8,1,7,10,23};
   cout<<"Largest Subarray with 0 sum is: "<<maxSub(arr,8)<<endl;
   int a[] = {1,0,1,1,1,0,0};
   int n = sizeof(a)/sizeof(a[0]);
   cout<<"Largest Subarray of 0's and 1's is: "<<maxLen(a,n)<<endl;
   return 0;
}