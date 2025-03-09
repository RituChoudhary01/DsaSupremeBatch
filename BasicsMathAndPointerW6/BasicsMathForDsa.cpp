/*
Basic Math for DSA
Q1.Prime Number
    1.Naive Approach.
    2.Sqrt Approach.
    3.Sieve of Eratosthenes
      use to count or print all prime number from 1 to given number N.
       1. Make a array of size n and make all the number from 0 to n-1 is true.
       2.0 and 1 are not prime mark make it false.
       3.Start from 2 till end,mark all the no. come in the table of 2 as non-prime or false.
       4.repeat step 3  till (N-1) only for prime number.
       5.Rest element marked as prime (true) will be count.
       T.C:O(nloglogn),S.C:O(n).
    4.Segmented Sieve.

Q2.Euclid's algorithm to find GCD
  1.gcd(a,b) = gcd(a-b,b) or gcd(a%b,b);  
      gcd(a,b) = gcd(a-b,b) if a>b
               = gcd(b-a,a) if a<b apply this till one of  them parameter become 0.

  2.lcm(a,b)*gcd(a,b) = a*b; 

Q3.Fast Exponention method
  1.Normal solution to find a^b of time complaxity: O(b);
  2.Better Solution a^b of time complixity:O(logb);

Q4.Modulo Arithmetic
 1.(a%n) are lies between 0 to n-1;
 2.Generally to avoid overflow while storing integer we do modulo with a large number.
  1.(a+b)%M = a%M + b%M;
  2.a%M - b%M = (a-b)%M;
  3.((a%M)%M)%M = a%M;
  4.a%M * b%M = (a*b)%M;

  Advanced topic
  1.Pigeon Hole.
  2.Catalan number.
  3.Inclusion - Exclusion Principle.
  4.Chinese Reminder Theorem.
  5.Lucas's Theorem.
  6.Format's Theorem.
  7.Probability Concept.
*/
#include<iostream>
#include<vector>
using namespace std;
//Naive Approach
bool isPrimeNative(int n){
    if(n == 0 || n == 1) return false;
    for(int i=2;i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int countPrimeNative(int n){
    int c = 0;
    for(int i=0;i<n;i++){
        if(isPrimeNative(i)){
            c++;
        }
    }
    return c;
}
// sqrt Approach
bool isPrimeSqrt(int n){
    if(n == 0 || n == 1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int countPrimeSqrt(int n){
    int c = 0;
    for(int i=0;i<n;i++){
        if(isPrimeSqrt(i)){
            c++;
        }
    }
    return c;
}
// Sieve of Eratosthenes
 // leetcode problem 204
    // https://leetcode.com/problems/count-primes/description/
int countPrime(int n){
    if(n==0) return 0;
    vector<bool>prime(n,true);
    prime[0] = prime[1] = false;
    int ans = 0;
    for(int i = 2;i<n;i++){
        if(prime[i]){
            ans++;
            int j = 2*i;
            while(j<n){
                prime[j]=false;
                j+=i;
            }
        }
    }
    return ans;
}
// gcd using Euclid's algorithm.
// gfg problem
// https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1
int gcd(int a,int b){
    if(a==0) return b;
    if(b==0) return a;
    while(a>0 && b>0){
        if(a>b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a==0?b:a;
}
// slow exponentions;
int slowExponentiation(int a,int b){
    int ans = 1;
    for(int i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}
// fast exponentions;
int fastExponentiation(int a,int b){
    int ans = 1;
    while(b>0){
        if(b&1){
            ans = ans*a;
        }
        a = a*a;
        b>>=1;
    }
    return ans;
}
// Modular Exponentiation for large number
// https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1

long long int powMod(long long int x,long long int n,long long int M){
    long long int ans = 1;
    while(n>0){
        if(n&1) ans = (ans*x)%M;
        x = (x*x)%M;
        n = n>>1;
    }
    return ans%M;
}
int main(){
   cout<<"Enter the number: "<<endl;
   int num;
   cin>>num;
   int resultNative = countPrimeNative(num);
   cout<<"Total prime number from 1 to "<<num<<" is: "<<resultNative<<endl;
   int resultSqrt = countPrimeSqrt(num);
   cout<<"Total prime number from 1 to "<<num<<" is: "<<resultSqrt<<endl;
   int result = countPrime(num);
   cout<<"Total prime number from 1 to "<<num<<" is: "<<result<<endl;
   int a,b;
   cout<<"Enter the two number to find gcd: "<<endl;
   cin>>a>>b;
   int gcdab = gcd(a,b);
   cout<<"gcd of "<<a<<" and "<<b<<" is: "<<gcdab<<endl;
   int num1,num2;
   cout<<"Enter the number a and b to find the pow(a,b):"<<endl;
   cin>>num1>>num2;
   int slowResult = slowExponentiation(num1,num2);
   cout<<slowResult<<endl;
   int fastResult = fastExponentiation(num1,num2);
   cout<<fastResult<<endl;
}