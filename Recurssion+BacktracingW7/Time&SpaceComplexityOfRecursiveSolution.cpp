/*Time and space Complexity of Recursive Solutions
Solve time complexity of following question using formula method and using recursive tree.

In a recursive solution, function calls are managed using a stack by the operating system.

Q1.Print Array(Linear traversal of an Array.)
void printArray(int a[],int n){
if(n==0) return;
cout<<*a<<" ";
printArray(a+1,n-1);
}
T.C:-O(n) S.C:-O(n);
Q2.Factorial RE
int fact(int n){
if(n==1)
 return 1;
 return n*fact(n-1);
 }
 T.C:-O(n) S.C:-O(n);
 Q3.Binary Search RE
 int BS(int a[],int k,int start,int end){
 if(start>end)
  return -1;
  int mid = start+(end-start)/2;
  if(a[mid]==k)
   return mid;
   else if(k>a[mid]){
   return BS(a,k,mid+1,end);
   }
   else{
   return BS(a,k,start,mid-1);
   }
   }
   T.C:-O(logn) S.C:-O(n);
   Q4.Fibonacci Series RE
   int fib(int n){
   if(n==0 || n==1)
     return n;
     return fib(n-1)+fib(n-2);
     }
     T.C:-O(2^n) S.C:-O(n);

*/ 