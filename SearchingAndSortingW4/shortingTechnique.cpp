// Sorting technique 
#include<iostream>
#include<vector>
using namespace std;

int main(){
//   Q1.Selection Sort
    int arr[5]={5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n-1; i++){
      int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
      }
    // for printing vector
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Q2.Bubble Sort
      int arr1[6]={10,1,7,6,14,9};
      int n1 = sizeof(arr1)/sizeof(arr1[0]);
     for(int round = 1; round < n1; round++){
        int swapCount = 0;
        for(int j =0; j< n1-round; j++) {
         if(arr1[j] > arr1[j+1]){
                swap(arr1[j], arr1[j+1]);
                swapCount++;
            }
         }
        if(swapCount == 0) {
            //sort ho chuka hai, no need to check in further rounds
            break;
        }
    }
    //For prninting vector
    for(int i=0; i<n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Q3.Insertion Sort
      int arr2[6] = {10,1,7,6,14,9};
      int n2 = sizeof(arr2)/sizeof(arr2[0]);
      for(int round = 1; round < n2; round++){
      int val = arr2[round];
      int j = round-1;
      for(; j>=0; j--){
          if(arr2[j] > val){
              arr2[j+1] = arr2[j];
          }
          else {
              break;
          }
        }
      arr2[j+1] = val;
     }
      // For printing vector
      for(int i=0; i<n2; i++) {
         cout << arr2[i] << " ";
     }
       cout << endl;
     return 0;
}