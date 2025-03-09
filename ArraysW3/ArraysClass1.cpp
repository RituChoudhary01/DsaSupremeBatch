/*
Q1.What is Array?
 Collection of Similar element.
 continous memory block
 list of similar items.
 linear data structure
Q2.Why array is needed?
  when you want to work with multiple values of the same data type.
  int arr[10];
  int arr[40000];

 Q3.Creating an arrays:
 //  array declare
 int a[5];
// array  initilize
 int b[] ={1,2,3,5}; 
 int c[5]= {2,2,2,2,2};
 int d[10] = {1,2,3};

 //  error
 int e[4] = {1,2,3,4,89};
 to insert element more then size of array its give error.

// bad practics
int n;
cin>>n;
int arr[n];
// instead of this we use dynamic array


index and Access in Array
0 based indexing
int arr[]={10,20,30,40,50};
int arr[0]=10;
int arr[1]=20;
int arr[2]=30;
int arr[3]=40;
int arr[4]=50;

Q5. Why index are start form 0.
arr[3]=40
value at(arr+3*4);
value at(arr+12)=40;

formula :- base adress+(index*datatype);

Q6.why pass size in function with array?
arr[10]={1,2,3};
we went to print only 3 element.but size of arr is 10.
if we do not print zero then we pass size 3 their is not any formula which calaculate how many element initilize in array.
*/

#include<iostream>
#include<limits.h>
using namespace std;


 void inc(int arr[],int size){
    // arr is adderess of array which is pass by reference.
     arr[0]=arr[0]+10;
 }
 void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
 }

 bool findKey(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key) return true;
    }
    return false;
  }


int main(){
    int arr[]={1,3,5,7,9};
    // printing all values
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
     int arr1[10];
    // taking input on run time
    for(int index=0;index<10;index++){
        cin>>arr1[index];
    }
    // printing arr1
      for(int index=0;index<10;index++){
        cout<<arr1[index]<<" ";
    }
// Q1. take 5 element in i/p and print its doubles
    int arr2[5];
    for(int index=0;index<5;index++){
        cin>>arr2[index];
    }
    // printing arr1
      for(int index=0;index<5;index++){
        cout<<2*arr2[index]<<" ";
    }
 //Q2.initilaze the whole arr by 0;
 int arr3[10]={0};
//Q3. initilize the whole array other then 0 how?
// memset is a function which is used to initilize the whole array by given value.
int arr21[5];
memset(arr21, -1, sizeof(arr21));
printArray(arr21,5);
// it will initilize whole array with garbage value.Then we use fill.
int arr23[5];
memset(arr23, 45, sizeof(arr23)); 
// The arr values will change to some garbage value.
// fill stl is used to specify the number of elements to fill with a spacific value.
int arr22[5];
fill(begin(arr22), end(arr22), 234);
printArray(arr22,5);

//Q4. array is pass by reference in function
int arr4[]={3,5};
int size1 = 2;
printArray(arr4,size1);
inc(arr4,size1);
printArray(arr4,size1);

//Q5. linear  Search
int arr5[5]={1,4,5,67,78};
int size = 5;
cout<<endl<<"Enter the key to find: "<<endl;
int key;
cin>>key;
if(findKey(arr5,size,key)){
cout<<"Found"<<endl;
}
else {
cout<<"Not Found "<<endl;
}

//Q6. cout zero and one in the given array;
int arr6[]={1,0,0,1,0,0,0,1,1,1,1,0,0,0,1,1,1};
 size = 17;
int countZero = 0;
int countOne = 0;
for(int i=0;i<size;i++){
    if(arr6[i]==0){
       countZero++;
    }
    if(arr6[i]==1){
        countOne++;
    }
}
cout<<"number of zeroes: "<<countZero<<endl;
cout<<"number of ones: "<<countOne<<endl;

//Q7. Maximum number in an array;
int arr7[]={2,3,43,45,432,12,-67,-54,3,2345};
size = 10;
int maxi = INT_MIN;
for(int i=0;i<10;i++){
    if(arr7[i]>maxi){
        maxi = arr7[i];
    }
} 
cout<<"maximum number is: "<<maxi <<endl;

// Q8.Extreme Print in Array;
int arr8[]={2,3,45,34,67,-90,54};
size = 7;
int start = 0;
int end = size-1;
while(start<=end){
    cout<<arr8[start];
    start++;
    if(start!=end){
        cout<<arr8[end];
        end--;
    }
}
printArray(arr8,size);
// Q9 Reverse a array;
int arr9[]={10,20,30,40,50,60};
 size = 6;
 start = 0;
 end = size-1;
while(start<end){
    swap(arr9[start],arr9[end]);
    start++;
    end--;
}
printArray(arr9,size);
 return 0;
}