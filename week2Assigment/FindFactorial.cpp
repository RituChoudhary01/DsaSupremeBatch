// write a function to find the factorial of number

#include<iostream>
using namespace std;int fact(int n){
  int fact = 1;
  for(int i=1;i<=n;i++){
    fact*=i;
  } 
  return fact; 
}
int main(){
   int num;
   cin>>num;
   int ans = fact(num);
   cout<<"Factorial of "<<num<<" is "<<ans<<endl;
    return 0;
}