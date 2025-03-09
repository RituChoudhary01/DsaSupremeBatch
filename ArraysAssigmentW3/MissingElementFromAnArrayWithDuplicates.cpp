// Missing Element from an Array with Duplicates
#include<iostream>
using namespace std;

void findMissing(int *arr,int n){
    // visited method
    // for(int i=0;i<n;i++){
    //     int index = abs(arr[i]);
    //     if(arr[index-1]>0){
    //         arr[index-1]*=(-1);
    //     }
    // }
    // // for(int i=0;i<n;i++){
    // //     cout<<arr[i]<<"  ";
    // // }
    // // all positive index are missing
    // for(int i=0;i<n;i++){
    //     if(arr[i]>0){
    //         cout<<i+1<<" ";
    //     }
    // } 


// Method 2 sorting ans swapping
int i=0;
while(i<n){
 int index = arr[i]-1;
 if(arr[i]!= arr[index]){
    swap(arr[i],arr[index]);
 }
 else{
    i++;
 }
}
for(int i=0;i<n;i++){
    if(arr[i]!=i+1)
    cout<<i+1<<" ";
}
cout<<endl;
}

int main(){
    int n;
    int arr[]={1,3,5,3,4};
    n = sizeof(arr)/sizeof(arr[0]);
    findMissing(arr,n);
    return 0;
}