// Perfect Squares
//https://leetcode.com/problems/perfect-squares/description/
#include<iostream>
#include<vector>
using namespace std;
int numSquareHelper(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    int ans = INT_MAX;
    int i=1;
    int end = sqrt(n);
    while(i<=end){
        int prefectSquare = i*i;
        int numberOfPerfectSquare = 1+numSquareHelper(n-prefectSquare);
        if(numberOfPerfectSquare<ans){
            ans = numberOfPerfectSquare;
        }
        i++;
    }
    return ans;

}

int numSquareHealperTD(int n,vector<int>&dp){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = INT_MAX;
    int i=1;
    int end = sqrt(n);
    while(i<=end){
        int prefectSquare = i*i;
        int numberOfPerfectSquare = 1+numSquareHelper(n-prefectSquare);
        if(numberOfPerfectSquare<ans){
            ans = numberOfPerfectSquare;
        }
        i++;
    }
    dp[n]=ans;
    return dp[n];
}
int numSquareHealperBU(int n,vector<int>&dp){
    dp[0]=1;
    for(int i=1;i<=n;i++){
    int ans = INT_MAX;
    int start=1;
    int end = sqrt(i);
    while(start<=end){
        int prefectSquare = start*start;
        int numberOfPerfectSquare = 1+dp[i-prefectSquare];
        if(numberOfPerfectSquare<ans){
            ans = numberOfPerfectSquare;
        }
        start++;
    }
    dp[i]=ans;
}
 return dp[n];
}
void numSquare(int n){
    cout<<" least number of perfect square numbers using Recurssion:  "<<numSquareHelper(n)-1<<endl;
    vector<int>dp(n+1,0);
    cout<<" least number of perfect square numbers using Memoization: "<<
    numSquareHealperTD(n,dp)-1<<endl;
     vector<int>dp1(n+1,0);
    cout<<" least number of perfect square numbers using Tabulation: "<<
    numSquareHealperBU(n,dp1)-1<<endl;
}
int main(){
    int n;
    cin>>n;
    numSquare(n);
    return 0;
}