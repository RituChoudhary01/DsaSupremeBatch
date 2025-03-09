#include <iostream>
using namespace std;
/*
// Q1.Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/description/
int climbStairs(int n) {
	//base case - stopping condition
	if(n==0 || n==1)
	  return 1;
        int ans = climbStairs(n-1) + climbStairs(n-2);
	return ans;
}

int main() {
        int n;
	cout << "Enter the value of n" << endl;
	cin >> n;
        int ans = climbStairs(n);
	cout << "Answer is : " << ans << endl;
    return 0;
}
*/

/*
// Q2.Print array using recursion
// Approach 1
void print(int arr[], int n, int i) {
        //base case
        if( i >= n) {
        return;
        }
        //1 case solve krdia
        cout << arr[i] << " ";
        //baaki recursion sambhal lega
        print(arr, n, i+1);

}
// Approach 2
void print1(int arr[], int n) {
        //base case
        if( n==0) {
                return;
        }
        //1 case solve krdia
        cout << arr[0] << " ";
        //baaki recursion sambhal lega
        print1(arr+1, n-1);
}
int main() {
  int arr[5] = {10,20,30,40,50};
  int n = 5;
  int i = 0;
  print(arr, n,i);
  cout<<endl;
  print1(arr,n);
  return 0;
}
// Do not use i++ because it first passes the value of i and then increments it. In a recursive solution, first pass the value of i, then increment it separately. Otherwise, in every recursive call, the value of i will remain the same, causing infinite recursion and resulting in a segmentation fault.
// Do not use in this manner print(arr, n, i++);
*/
/*
// Q3. find max and min element in array using recursion
// for maximum element
void findMax(int arr[], int n, int i, int& maxi) {
  //base case
  if(i >= n) {
    return;
    }
     //1 case solve krna h 
    //current element ko check karo for max element
    if(arr[i] > maxi) {
        maxi = arr[i];
    }
    //baaki recursion sambhal lega
    findMax(arr, n, i+1, maxi);
    }
   //for minimum element 
    void findMin(int arr[], int n, int i, int& mini ){
    //base case
    if( i >= n) {
     return;
    }
    //1 case solve kr diya
    mini = min(mini, arr[i]);
    //baaki recursion sambhal lega
    findMin(arr, n, i+1, mini);
}
int main() {
int arr[] = {10,30,21,44,32,6,19,66};
int n = 8;
int maxi = INT_MIN;
int mini = INT_MAX;
int i = 0;
findMax(arr, n, i, maxi);
findMin(arr, n, i, mini);
cout << "maximum number is: "<< maxi << endl;
cout << "minimum number is: "<< mini << endl;
return 0;
}
*/

// Q4.Linear seach in string using recursion
void checkKey(string& str,int& i, int n, char key) {
//base case
if(i >= n){
//key not found
i=-1;
return;
}
//1 case solve krdo
if(str[i] == key) {
 return;
}
i= i+1;
//baaki recursion sambhal lega
checkKey(str, i, n, key);
}

int main() {
string str = "HelloDost";
int n = str.length();
char key = 'l';
int i = 0;
checkKey(str,i, n, key);
cout << "first index where key is found: "<<i << endl;
cout << endl;
return 0;
}

/*
// Q5.Print digits of number
void printDigits(int n){
//base case
if(n == 0)
return ;
//baaaki recursion sambhal lega
printDigits( n / 10);
//1 case  solve kardo
int digit = n % 10;
cout << digit << " ";
}
int main() {
int n = 64786;
cout << n << endl;
if(n == 0)
cout << 0 << endl;
printDigits(n);
return 0;
}
*/