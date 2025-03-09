//The Painter's Partition Problem-II gfg question
//https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPosibleSolution(int a[],int n,int k,int mid){
    int timeSum = 0;
    int c = 1;
    for(int i=0;i<n;i++){
        if(a[i]>mid){
            return false;
        }
        if(a[i]+timeSum>mid){
            c++;
            timeSum = a[i];
            if(c>k) return false;
        }
        else{
            timeSum+=a[i];
        }
    }
    return true;
}
 int minTime(int arr[],int n,int k){
    int start = 0;
    int end = 0;
    for(int i=0;i<n;i++){
        end+=arr[i];
    }
    int ans = -1;
    while(start <= end){
        int mid = start+(end-start)/2;
        if(isPosibleSolution(arr,n,k,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = minTime(arr,n,k);
    cout<<ans<<endl;
    return 0;
}

