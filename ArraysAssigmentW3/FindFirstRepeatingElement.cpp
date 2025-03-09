// First Repeating Element GFG
// https://www.geeksforgeeks.org/problems/first-repeating-element4018/1

#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
int firstReapting(int arr[],int n){
    // Method 1 using brust force aproach using two loops
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(arr[i]==arr[j]){
    //             return i;
    //         }
    //     }
    // }
    //     return -1;
// method 2 using hashing
unordered_map<int,int>mp;
 for(int i=0;i<n;i++){
    mp[arr[i]]++;
 }
 for(int i=0;i<n;i++){
    if(mp[arr[i]]>1){
     return i+1;
    }
 }
 return -1;
}
};

int main(){
    int arr[]={1,5,3,4,3,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution s;
    cout<<s.firstReapting(arr,n);
}
