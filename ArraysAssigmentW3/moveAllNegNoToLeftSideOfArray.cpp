// Move all -ve number to left side of array order of element may or may not be preserved.

#include<iostream>
#include<vector>
using namespace std;
// Detch National flag algorithm or 2 pointer approach
void moveallNeg(int *arr,int n){
    int low = 0;
    int high = n-1;
    while(low<high){
        if(arr[low]<0){
            low++;
        }
        else if(arr[high]>=0){
            high--;
        }
        else{
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
    }
}
int main(){
int arr[]={11,23,-98,3,-21,-43,45};
int n = sizeof(arr)/sizeof(arr[0]);
// Method 1 using  inbuilt sort  method T.C = O(nlogn),S.C. = O(1);
sort(arr,arr+n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
// Method 2 using Dutch national flag algorithm T.C = O(n),S.C = O(1);
moveallNeg(arr,n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
return 0;
}
