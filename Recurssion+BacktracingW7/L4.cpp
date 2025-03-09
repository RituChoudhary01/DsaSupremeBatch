#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
/*
// Q1.coin-change problem.
int solve(int arr[],int n, int target) {
  //base case
  if(target == 0) {
    return 0;
  }
  if(target < 0) {
    return INT_MAX;
  }
  //let's solve 1 case
  int mini = INT_MAX;
  for(int i=0; i<n; i++) {
    int ans = solve(arr,n, target - arr[i]);
    if(ans != INT_MAX)
    mini = min(mini, ans + 1);
  }
  return mini;
}
int main() {
int arr[]={1,2};
int n = sizeof(arr)/sizeof(arr[0]);
int target = 5; 
int ans = solve(arr,n,target);
  cout << "Answer is: " << ans << endl;
  return 0;
}
*/
/*
// Q2.Cut a rod into segment

int solve(int n, int x, int y, int z ) {
  //base case
if(n == 0) {
    return 0;
  }
if(n < 0) {
    return INT_MIN;
  }
int ans1 = solve(n-x, x,y,z) + 1;
int ans2 = solve(n-y, x,y,z) + 1;
int ans3 = solve(n-z, x,y,z) + 1;

int ans = max(ans1, max(ans2, ans3));
return ans;
}

int main() {
  int n = 7;
  int x = 5;
  int y = 2;
  int z = 2;
//solve function -> returns maximum number of segments
int ans = solve(n,x,y,z);
//ans -> valid && invalid
if(ans < 0 )
ans = 0; 
cout << "Answer is: " << ans << endl;
return 0;
}
*/
//maximum sum of non adjacent element
void solve(int arr[],int n,int i, int sum, int &maxi) {
  //base case
  if(i >= n) {
    //maxi update;
    maxi = max(sum, maxi);
    return;
  }
  //include
  solve(arr,n,i+2,sum+arr[i] ,maxi );
  //exclude
  solve(arr,n, i+1, sum, maxi);
}
 int main() {
 int arr[]={1, 2, 3, 1, 3, 5, 8, 1, 9};
 int n = sizeof(arr)/sizeof(arr[0]);
  int sum = 0;
  int maxi = INT_MIN;
  int i = 0;
  solve(arr,n,i, sum, maxi);
  cout << maxi << endl;
  return 0;
}