// write a function check a given number is prime or not
#include<iostream>
using namespace std;
bool checkPrime(int n){
    if(n<2) return false;
  int i=2;
  for(int i=2;i*i<n;i++){
    if(n%i==0) return false;
  }
  return true;
}

int main(){
  int n;
  cin>>n;
  bool isPrime = checkPrime(n);
  if(isPrime){
    cout<<"Prime"<<endl;
  }
  else{
    cout<<"Not Prime"<<endl;
  }
  return 0;
}