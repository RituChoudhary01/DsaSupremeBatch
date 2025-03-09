#include<iostream>
#include<vector>
using namespace std;
int findSqrt(int n){
    int target = n;
    int s = 0;
    int e = n;
    int mid = s+(e-s)/2;
    int ans = -1;
    while(s <= e){
      mid = s+(e-s)/2;
      if(mid*mid == target){
        return mid;
      }
      else if(mid*mid < target){
        ans = mid;
        s = mid+1;
      }
      else{
        e = mid-1;
      }
      mid = s+(e-s)/2;
    }
    return ans;
}
 
   // Q1.pivot element
    int findPivot(vector<int> arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    while(s < e){
        if(mid+1 < arr.size() && arr[mid] > arr[mid+1])
        return mid;
        if(mid-1 >= 0 && arr[mid-1] > arr[mid])
        return mid-1;

        if(arr[s] >= arr[mid])
        e = mid - 1;
        else
        s = mid ;
        mid = s + (e-s)/2;
    }
      return s; 
    }
    // Q2.search in rotated sorted array

   int binarySearch(vector<int> arr, int target, int start, int end) {
   int mid = start + (end - start ) / 2;
   while(start <= end) {
        int element = arr[mid];
     if(element == target) {//element found, then return index
        return mid;
        }
     if(target < element) {
        //search in left
        end = mid - 1;
        }
        else {
        //search in right
        start = mid + 1;
        }
     mid = start + (end - start ) / 2;
     }
     //element not found
     return -1;
    }

    int searchInRotatedArray(vector<int>& nums, int target){
        int pivotIndex = findPivot(nums);
        if(target >= nums[0] && target <= nums[pivotIndex]){
         
            int ans = binarySearch(nums, target, 0, pivotIndex);
            return ans;
        }
        if(pivotIndex+1 < nums.size() && 
         target >= nums[pivotIndex+1] && target <= nums[nums.size()-1]){
           
            int ans = binarySearch(nums, target, pivotIndex+1, nums.size()-1);
            return ans;
        }
        return -1;
    }

int main(){
    // Q3.Square root using binary search
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    int ans = findSqrt(n);
    cout<<"Ans is "<<ans<<endl;
    // after precision ans
    int precision;
    cout<<"Enter the number of floating digits in precison "<<endl;
    cin>>precision;
    double step = 0.1;
    double finalAns = ans;
    for(int i=0;i<precision;i++){
        for(double j =finalAns;j*j<=n;j+=step){
            finalAns = j;
        }
        step/=10;
    }
    cout<<"Final ans is "<<finalAns <<endl;
    return 0;
}
    /* Q4.Binary search on matrix leetcode 74.
    // https://leetcode.com/problems/search-a-2d-matrix/ 
      bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int start = 0;
        int end = n*m-1;
        int mid = start+(end-start)/2;
        while(start<=end){
          mid = start+(end-start)/2;
          if(matrix[mid/m][mid%m]==target){
            return true;
          }
          else if(matrix[mid/m][mid%m]>target){
            end = mid-1;
          }
          else  start = mid+1;
        }
        return false;
    }
    */

