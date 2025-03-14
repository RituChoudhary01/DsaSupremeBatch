#include<iostream>
#include<vector>
using namespace std;
/*
// Q1.Search in  nearly sorted array
int binarySearch(vector<int> arr, int target){
  int s = 0;
  int e = arr.size() - 1;
  int mid = s+(e-s)/2;
  while(s <= e){
    if(arr[mid] == target)
      return mid;
    if(mid-1 >= s && arr[mid-1] == target) 
      return mid-1;
    if(mid + 1 <= e && arr[mid+1] == target)
      return mid+1;
    if(target > arr[mid]) {
      //right search
        s = mid + 2;
      }
      else {
        //left search
        e = mid - 2;
      }
      mid = s + (e-s)/2;
  }
  return -1;
}
 int main() {
  vector<int> arr{10,3,40,20,50,80,70};
  int target = 70;
  int ans = binarySearch(arr, target);
  cout << "index of "<< target << " is " << ans << endl;
  return 0;
}
*/

/*
// Q2.Divide a number leetcode problem 29
// https://leetcode.com/problems/divide-two-integers/description/
  int solve(int dividend, int divisor){
  int s = 0;
  int e = abs(dividend);
  int ans = 0;
  int mid = s + (e-s)/2;
  while(s <= e){;
    //perfect solution
    if(abs(mid*divisor) == abs(dividend)){
      ans = mid;
      break;
    }
    //not perfect sol
    if(abs(mid*divisor) > abs(dividend)) {
      //left
      e = mid - 1;
    } 
    else {
      //ans store
      ans = mid;
      //right search
      s = mid + 1;
    }
    mid = s + (e-s)/2;
  }
  if((divisor<0 && dividend<0) || (divisor>0 && dividend>0))
    return ans;
  else {
    return -ans;
  }
}
 int main() {
  int dividend = -21;
  int divisor = -7;
  int ans = solve(dividend, divisor);
  cout << "Ans is-> " << ans << endl;
  return 0;
}
*/
/*
// Q3.odd occuring number
 int solve(vector<int> arr){
  int s = 0;
  int e = arr.size()-1;
  int mid = s + (e-s)/2;
  while(s <= e){
    if(s == e){
      //single element
      return s;
    }
    //2 cases -> mid - even or mid - odd
    if(mid%2 == 0){
      if(arr[mid] == arr[mid + 1] ) {
        s = mid + 2;
      }
      else{
        e = mid;
      }
    }
    else {
        if(arr[mid] == arr[mid-1]){
          s = mid + 1;
        }
        else {
          e = mid - 1;
        }
    }
    mid = s + (e-s)/2;
  }
  return -1;
}

 int main() {
  vector<int> arr{1,1,2,2,1};
  int ans = solve(arr);
  cout << "index is " << ans << endl;
  cout << "value is " << arr[ans] << endl;
  return 0;
}
*/
