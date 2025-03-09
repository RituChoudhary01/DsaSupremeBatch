/*
Linear Search time complexity is O(n);
Binary search time complexity is O(log n);
Binary search condition on array is array should be sorted in ascending order or descending order.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(int arr[],int size,int target){
    int start = 0;
    int end = size-1;
    int mid = start+(end-start)/2;
    while(start<=end){
    mid = start+(end-start)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
        end = mid-1;
    }
    else{
        start = mid+1;   
        }
    }
    return -1;
}

int firstOccurence(int *arr2,int size2,int target2){
    int start = 0;
    int end = size2-1;
    int mid = start+(end-start)/2;
    int ans = -1;
    while(start <= end){
        mid = start+(end-start)/2;
        if(arr2[mid] == target2){
            ans = mid;
            end = mid-1;
        }
        else if(arr2[mid]>target2){
            end = mid-1;
        }
        else start = mid+1;
    }
    return ans;
}

int lastOccurence(int *arr2,int size2,int target2){
    int start = 0;
    int end = size2-1;
    int mid = start+(end-start)/2;
    int ans = -1;
    while(start<=end){
        mid = start+(end-start)/2;
        if(arr2[mid]==target2){
            ans = mid;
            start = mid+1;
        }
        else if(arr2[mid]>target2){
            end = mid-1;
        }
        else start = mid+1;
    }
    return ans;
}

int main(){
    // Q1.Binary search
    int arr[]={2,4,6,45,67,81,99};
    int size = 7;
    int target = 81;
    int indexOfTarget = binarySearch(arr,size,target);
    if(indexOfTarget == -1){
        cout<<"target is not found"<<endl;
    }
    else{
        cout<<"target is found at index: "<<indexOfTarget<<endl;  
      }

  //Q2.inbuilt binary search  
  int arr1[] = {1,2,3,4,5,6,7};
  int size1 = 7;

  if(binary_search(arr1,arr1 + size1, 7)) {
    cout << "Found" << endl;
  }
  else {
    cout << "Not found. " << endl;
  }

// Q3. first occurences of element in sorted array
 int arr2[] = {1,2,3,3,3,3,4,5,6,7};
  int size2 = 10;
  int target2 = 3;
  int firstOcc = firstOccurence(arr2,size2,target2);
  if(firstOcc == -1){
    cout<<"target is not present"<<endl;
  }
  else{
    cout<<"First occurence of target is at index: "<<firstOcc<<endl;
  }
// inbuilt lower bound function
 cout << lower_bound(arr2, arr2+size2,4)-arr2<<endl; 
// Q4. last occurences of element in sorted array
int lastOcc = lastOccurence(arr2,size2,target2);
    if(lastOcc == -1){
        cout<<"target is not present"<<endl;
    }
    else{
        cout<<"Last occurence of target is at index: "<<lastOcc<<endl;
    }
//  inbuilt upper bound function
   cout << upper_bound(arr2, arr2+size2,3)-arr2-1 <<endl; 

// Q5.total occurences of element in sorted array
 cout<<"Total occurence of target is:"<<lastOcc-firstOcc+1<<endl;
// Q6.find the missing element in sorted array 
// leetcode problem 268.
// https://leetcode.com/problems/missing-number/description/
    int nums[]={0,2,3,4,1};
      int n  = sizeof(nums)/sizeof(nums[0]);
      int ans = 0;
         for(int i=0;i<n;i++){
           ans = ans^nums[i]^i;
         }
         ans = ans^n;
        cout<<"Missing element from range 0 to n is: "<<ans<<endl;
    return 0;
}
// Q7.Peak element in mountained array Leetcode Question 852
// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
 int peakIndexInMountainArray(vector<int>& arr){
      int start = 1;
      int n = arr.size();
      int end = n-2;
      int mid = start+(end-start)/2;
      while(start<=end){
        mid = start+(end-start)/2;
        if(arr[mid-1]< arr[mid] && arr[mid]>arr[mid+1])
         return mid;
        else if(arr[mid-1]<arr[mid])
        start = mid+1;
        else end = mid-1; 
      } 
      return -1;
    }
 