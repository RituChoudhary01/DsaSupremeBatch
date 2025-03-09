/*
Dynamic Programming 
DP:-it is an optimization technique used to solve complex problems by breaking them down into smaller overlapping subproblems and storing the results to avoid redundant computations.
Types of Solutions in Dynamic Programming :-
1.Top-Down (Recursion+Memoisation) solution
2.Bottom-Up(tabulation method)solution
3.Space Optimization.
 When to apply dp?
  1.Overlapping Subproblems:-A problem has overlapping subproblems if it can be broken down into smaller subproblems, and these subproblems are reused multiple times.
  2️.Optimal Substructure:-A problem has optimal substructure if its solution can be constructed from the solutions of its subproblems.
*/ 
// Q. Fibbonaci No.
// https://leetcode.com/problems/fibonacci-number/description/
#include<iostream>
#include<vector>
using namespace std;
// solution 1. Reccuesive solution
int recSolve(int n) {
     //base case
    if(n == 1 || n == 0) {
    return n;
    }
    int ans = recSolve(n-1) + recSolve(n-2);
    return ans;
}
 //solution 2. Recursion + Memoisation or top-down approach
    int topDownSolve(int n, vector<int>& dp) {
        //base case
        if(n == 1 || n == 0) {
            return n;
        }
        //step3: check if ans allready exist.
        if(dp[n] != -1) {
            return dp[n];
        }
        //step2: replace ans with dp[n]
        dp[n] = topDownSolve(n-1,dp) + topDownSolve(n-2, dp);
        return dp[n];
    }
// solutin 3. tabulation method or Bottom Up approach
   int bottomUpSolve(int n) {
       //step1: create a dp array
       vector<int> dp(n+1, -1);

       //step2:base case
       dp[0] = 0;
       if(n == 0) 
       return dp[0];
       dp[1] = 1;

       //step3: topDown approach me n kaise travel krra h 
       for(int i = 2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
       }
     return dp[n];
    }
// Solution 4. space Optimization
   int spaceOptSOlve(int n) {
      //base case
       int prev2 = 0;
       int prev1 = 1;
       if(n==0)
        return prev2;
       if(n == 1)
        return prev1;
       int curr;
       //topDown approach me n kaise travel krra h 
       for(int i = 2; i<=n; i++) {
            curr = prev1 + prev2;
            //shifting
            prev2 = prev1;
            prev1 = curr;
       }
        return curr;
        }

    int main(){
        int n;
        cout<<"Enter the number :"<<endl;
        cin>>n;
        cout<<"using recurssion fibbonaci "<<n<<"th number is: "<<recSolve(n)<<endl;
        //step1: create dp array
        vector<int> dp(n+1, -1);
        cout<<"using top down approach fibbonaci "<<n<<"th number is: "<<topDownSolve(n, dp)<<endl;

        cout<<"using bottom approach fibbonaci "<<n<<"th number is: "<<bottomUpSolve(n)<<endl;

         cout<<"using space optimization fibbonaci "<<n<<"th number is: "<<spaceOptSOlve(n)<<endl; 
         return 0;
    }
