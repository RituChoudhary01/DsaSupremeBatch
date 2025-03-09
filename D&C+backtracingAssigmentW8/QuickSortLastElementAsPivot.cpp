// quick sort 
// 
#include<iostream>
using namespace std;
void quickSort(int arr[],int start,int end){
    if(start>=end) return;
    int pivot = end;
    int i = start-1;
    int j = start;
    while(j<pivot){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i],arr[pivot]);
    quickSort(arr,start,i-1);
    quickSort(arr,i+1,end);
}
int main() {
  int arr[] = {8,1,3,4,20,50,50,50,50,50,5,1,1,1,1,2,2,2,50,30};
  int n = 20;

  int s = 0;
  int e = n-1;
  quickSort(arr, s, e);

  for(int i=0; i<n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
