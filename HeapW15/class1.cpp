/* Heap:-heap flow fllowing property.
 Complete Binary Tree: All levels are completely filled except possibly the last, which is filled from left to right.

 Heap Property: Every parent node follows the max-heap or min-heap condition.

 Max-Heap:- The parent node is always greater than or equal to its children.
The largest element is at the root.

Min-heap:-The parent node is always smaller than or equal to its children.
The smallest element is at the root.
TimeComplixity:-
Insertion in heap = O(logn);
Deletion in heap = O(logn);
get min/max element = O(1);
Heapify = O(logn);
Build Heap (Heap Construction):O(n);
Heap Sort:O(nlogn);
 */
#include<iostream>
using namespace std;
class Heap{
    public:
    int arr[101];
    int size;
    Heap(){
        size = 0;
    }
    void insert(int value){
        size = size+1;
        int index = size;
        arr[index] = value;
        // iss value ko place at correct position
        while(index>1){
            int parentIndex = index/2;
            if(arr[index]>arr[parentIndex]){
                swap(arr[index],arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }
    int Delete(){
        int ans = arr[1];
        // replace root node value with last node data 
        arr[1]=arr[size];
        size--;
        // place root node ka data on its correct position
        int index = 1;
        while(index<size){
            int left = 2*index;
            int right = 2*index+1;
            int largest = index;
            if(left<size && arr[largest]<arr[left]){
                largest = left;
            }
            if(right<size && arr[right]){
                largest = right;
            }
            if(largest == index){
            break;
            }
            else{
                swap(arr[index],arr[largest]);
                index = largest;
            }
        }
        return ans;
    }
};
void heapify(int arr[],int n,int i){
 int index = i;
 int leftIndex = 2*i;
 int rightIndex = 2*i+1;
 int largest = index;
 if(leftIndex <= n && arr[largest]<arr[leftIndex]){
    largest = leftIndex;
 }
 if(rightIndex<=n && arr[largest]<arr[rightIndex]){
    largest = rightIndex;
    }
  if(index!= largest){
    swap(arr[index],arr[largest]);
    index = largest;
    heapify(arr,n,index);
  }  
}
void buildHeap(int arr[],int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[],int n){
    while(n!= 1){
        swap(arr[1],arr[n--]);
        heapify(arr,n,1);
    }
}
int main(){
  Heap h;
  h.arr[0] = -1;
  h.arr[1] = 100;
  h.arr[2] = 50;
  h.arr[3] = 60;
  h.arr[4] = 40;
  h.arr[5] = 45;
  h.size = 5;
  cout << "printing the heap " << endl;
  for(int i=0; i<=h.size; i++) {
          cout << h.arr[i] << " ";
  }
  cout << endl;
  h.insert(110);
  h.insert(11);
  cout << endl << "printing the heap " << endl;
  for(int i=0; i<=h.size; i++) {
          cout << h.arr[i] << " ";
  }
  cout << endl;
  cout<<"delete value is: " <<h.Delete()<<endl;

  int arr[] = {-1,12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
  int n = 11;
  buildHeap(arr, n);

  cout << "printint the heap "<< endl;
  for(int i=0; i<=n; i++) {
          cout << arr[i] << " ";
  }
  cout << endl;
  heapSort(arr, n);

  cout << endl << "printint the heap after heap sort "<< endl;
  for(int i=1; i<=n; i++) {
          cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
