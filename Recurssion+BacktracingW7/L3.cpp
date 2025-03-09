#include<iostream>
#include<vector>
using namespace std;
/*
// Q1. Check array is shorted or not
bool checkSorted(vector<int> &arr, int& n, int i) {
  //base case
  if(i >= n-1) {
    return true;
  }
  //1 case solve krna h
  if(arr[i+1] <= arr[i])
    return false;
 //baaki recursion sambhal lega
  bool ans = checkSorted(arr, n, i+1);
  return ans;
}
 int main() {
 int n;
 cout<<"Enter the size of vector: ";
 cin>>n;
 vector<int>v;
  cout<<"Enter the element od vector: "<<endl;
  for(int i=0;i<n;i++){
    int input;
    cin>>input;
    v.push_back(input);
  }
  int i = 0;
  bool isSorted = checkSorted(v, n, i);

  if(isSorted) {
    cout << "Array is sorted" << endl;
  }
  else {
    cout << "Array is not sorted" << endl;
  }
 return 0;
}
*/

/*
// Q2.Binary Search using Recursion
int binarySearch(vector<int>& arr, int& s, int& e, int& key){
 //base case
 if(s>e) 
 return -1;
 int mid = (s+e)/2;
 // 1 case solve krdo
 if(arr[mid] == key)
    return mid;
 //baaki recursion sambhal lega
  if(arr[mid] < key){
    s = mid+1;
    int ans =  binarySearch(arr,s,e, key );
    return ans;
  }
  else {  
    e= mid-1;
    int ans = binarySearch(arr,s,e, key);
    return ans;
  }

}

 int main(){
 int n;
 cout<<"Enter the size of vector: ";
 cin>>n;
 vector<int>v;
 cout<<"Enter the element of vector: "<<endl;
 for(int i=0;i<n;i++){
    int input;
    cin>>input;
    v.push_back(input);
  }
  int target;
  cout<<"Enter the value of target: ";
  cin>>target;
  int s = 0;
  int e = n-1;
  int ans = binarySearch(v, s, e, target );
  cout << "Answer is: " << ans << endl;
  return 0;
}
*/

//Q3.print all the subSequence of a given sequence.
void printSubsequences(string str, int n, string output, int i, vector<string>& v){
  //base case
  if(i >= n){
    v.push_back(output);
    return;
  }
  //include
  printSubsequences(str,n, output + str[i], i+1,v);
  //exclude
  printSubsequences(str,n, output, i+1,v);
}
 int main() {
  string str = "abcd";
  string output = "";
  vector<string> v;
  int i = 0;
  int n = str.length();
  printSubsequences(str,n, output, i, v);
  cout << "Printing all subsequences: " << endl;
  for(auto val: v) {
    cout << val << " " ; 
  }
  cout << endl << "Size of vector is: " << v.size() << endl;
  return 0;
}