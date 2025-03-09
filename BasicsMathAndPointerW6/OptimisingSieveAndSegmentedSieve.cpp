/* 
int,double,char arrays maximum size in function is 10^6.
bool array maximum size in function is 10^7.
if we declare global array of int,char,double  maximum size of array is 10^7.
if we declare global array of bool type  maximum size of array is 10^8.
*/
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

// Sieve of Eratosthenes
    vector<bool>Sieve(int n){
    // create a sieve array of N size telling is prime
    vector<bool>sieve(n+1,true);
    sieve[0]=sieve[1]=false;
    for(int i=2;i<=n;i++){
        if(sieve[i]==true){
            int j = i*2;
            while(j<=n){
                sieve[j]=false;
                j+=i;
            }
        }
    }
    return sieve;
}

// optimising Sieve of Eratosthenes.
 
//   1.First optimasied in inner loop we start inner loop from i*i.
//   2.Second optimasied in outer loop we start outer loop from 2 to i*i<=n;

vector<bool>OptmizeSieve(int n){
    // create a sieve array of N size telling is prime
    vector<bool>sieve(n+1,true);
    sieve[0]=sieve[1]=false;
    for(int i=2;i*i<=n;i++){
        if(sieve[i]==true){
            int j = i*i;
            while(j<=n){
                sieve[j]=false;
                j+=i;
            }
        }
    }
    return sieve;
}
// Segmented Sieve.
// 1.Generate all primes responsible to mark seg. sieve. using root(R).
    vector<bool>segSieve1(int L,int R){
    vector<bool>sieve = Sieve(sqrt(R));
    vector<int>basePrimes;
    for(int i=0;i<sieve.size();i++){
        if(sieve[i]){
            basePrimes.push_back(i);
        }
    }
    vector<bool>segSieve(R-L+1,true);
    if(L==1||L==0){
        segSieve[L]=false;
    }
       for(int k = 0;k<basePrimes.size();k++) {
        int prime = basePrimes[k];
        int first_mul = (L/prime)*prime;
        if(first_mul<L){
            first_mul+=prime;
        }
        int j= max(first_mul,prime*prime);
        while(j<=R){
            segSieve[j-L]=false;
            j+=prime;
        }
    }
    return segSieve;
}
/*
int main(){
    int n;
    cin>>n;
    vector<bool>ans =Sieve(n);
    for(int i=0;i<=n;i++){
        if(ans[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    vector<bool>ansOptmize =OptmizeSieve(n);
    for(int i=0;i<=n;i++){
        if(ansOptmize[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    // //print prime number from 1 to 25.
    vector<bool>sieve = Sieve(25);
    for(int i=0;i<=25;i++){
        if(sieve[i])
        cout<<i<<" ";
    }
    cout<<endl;
    //    
    int L = 200;
    int R = 400;
    vector<bool>ss = segSieve1(L,R);
    for(int i=0;i<ss.size();i++){
        if(ss[i]){
            cout<<i+L<<" ";
        }
    }
    return 0;
}
*/
// H.W. Product of Primes  gfg question
// https://www.geeksforgeeks.org/problems/product-of-primes5328/1

class Solution {
public:
    const int MOD = 1000000007;
    
    vector<bool> Sieve(int n) {
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }
        return sieve;
    }
    
    vector<bool> segSieve1(long long L, long long R) {
        long long lim = sqrt(R);
        vector<bool> sieve = Sieve(lim);
        vector<long long> basePrimes;
        
        for (long long i = 2; i <= lim; i++) {
            if (sieve[i]) {
                basePrimes.push_back(i);
            }
        }
        
        vector<bool> segSieve(R - L + 1, true);
        if (L == 1) {
            segSieve[0] = false;
        }
        
        for (long long prime : basePrimes) {
            long long first_mul = max(prime * prime, (L + prime - 1) / prime * prime);
            for (long long j = first_mul; j <= R; j += prime) {
                segSieve[j - L] = false;
            }
        }
        
        return segSieve;
    }
    
    long long primeProduct(long long L, long long R) {
        long long ans = 1;
        vector<bool> prime = segSieve1(L, R);
        
        for (long long i = 0; i < prime.size(); i++) {
            if (prime[i]) {
                ans = (ans * (L + i)) % MOD;
            }
        }
        return ans;
    }
};
int main(){
    long long L,R;
    cin>>L>>R;
    Solution s;
    long long ans = s.primeProduct(L,R);
    cout<<ans<<endl;
    return 0;
}
