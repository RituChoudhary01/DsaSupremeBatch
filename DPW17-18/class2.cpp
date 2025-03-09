// Q1.Coin Change
// https://leetcode.com/problems/coin-change/description/
// Q2.House Robber 
// https://leetcode.com/problems/house-robber/description/

#include<iostream>
#include<vector>
using namespace std;
// Q1.Coin Change Problem
int solveUsingRecursion(vector<int>&coins,int amount){
    // base case
    if(amount==0)return 0;
    if(amount<0) return INT_MAX;
    int mini = INT_MAX;
    for(int i=0;i<coins.size();i++){
        int ans = solveUsingRecursion(coins,amount-coins[i]);
        if(ans!=INT_MAX){
            mini = min(mini,1+ans);
        }
    }
    return mini;
}
int solveusingMem(vector<int>&coins,int amount,vector<int>&dp){
    // base case
    if(amount == 0) return 0;
    if(amount<0) return INT_MAX;
    if(dp[amount] != -1){
        return dp[amount];
    }
    int mini = INT_MAX;
    for(int i=0;i<coins.size();i++){
       int ans = solveusingMem(coins,amount-coins[i],dp);
       if(ans!=INT_MAX){
        mini = min(mini,1+ans);
       } 
    }
    dp[amount] = mini;
    return dp[amount];
}
int solveTab(vector<int>&coins,int amount){
    vector<int>dp(amount+1,INT_MAX);
    dp[0]=0;
    for(int target = 1;target<= amount;target++){
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(target-coins[i]>=0){
                int ans = dp[target-coins[i]];
                if(ans!=INT_MAX){
                    mini = min(mini,1+ans);
                }
            }
        }
        dp[target] = mini;
    }
    return dp[amount];
}

int main(){
 int n;
 cout<<"Enter the number of coins:";
cin>>n;
vector<int>coins;
for(int i=0;i<n;i++){
    int input;
    cin>>input;
    coins.push_back(input);
}
int amount;
cout<<"Enter the amount: "<<endl;
cin>>amount;
cout<<"minimum coins using recursion:"<<solveUsingRecursion(coins,amount)<<endl;
vector<int>dp(amount+1,-1);
cout<<"minimum coins Rob  using memoization:"<<solveusingMem(coins,amount,dp)<<endl;
cout<<"minimum coins Rob  using Tabulation method:"<<solveTab(coins,amount)<<endl;
return 0;
}

/*
// Q2.House Robber Problem
int houseRobberUsingRec(vector<int>&nums,int n){
    if(n<0) return 0;
    if(n==0) return nums[0];

// include
int include = houseRobberUsingRec(nums,n-2)+nums[n];
int exclude = houseRobberUsingRec(nums,n-1);
return max(include,exclude);
}

int houseRobberUsingMem(vector<int>& nums,int n,vector<int>&dp){
    if(n<0) return 0;
    if(n==0) return nums[0];
    if(dp[n]!= -1) return dp[n];
    int include = houseRobberUsingMem(nums,n-2,dp)+nums[n];
    int exclude = houseRobberUsingMem(nums,n-1,dp);
    dp[n] = max(include,exclude);
    return dp[n];
}

int houseRobberUsingTablution(vector<int>& nums,int n){
    vector<int>dp(n+1,0);
    dp[0] = nums[0];
    for(int i=1;i<=n;i++){
        int temp = 0;
        if(i-2>=0)
           temp = dp[i-2];
        int include = temp+nums[i];
        int exclude = dp[i-1];
        dp[i] = max(include,exclude);   
    }
    return dp[n];
}

int houseRobberSpaceOptimised(vector<int>&nums,int n){
    int prev2 = 0;
    int prev1 = nums[0];
    int curr = 0;
    for(int i=1;i<=n;i++){
        int temp = 0;
        if(i-2>=0)
           temp = prev2;
        int include = temp+nums[i];
        int exclude = prev1; 
        curr = max(include,exclude);
        prev2 = prev1;
        prev1 = curr;  
    }
    return prev1;
}
int main(){
 int n;
 cout<<"Enter the number of houses:";
cin>>n;
vector<int>houses;
for(int i=0;i<n;i++){
    int input;
    cin>>input;
    houses.push_back(input);
}
cout<<"maximum amount Rob  using recursion:"<<houseRobberUsingRec(houses,n-1)<<endl;
vector<int>dp(n+1,-1);
cout<<"maximum amount Rob  using memoization:"<<houseRobberUsingMem(houses,n-1,dp)<<endl;
cout<<"maximum amount Rob  using Tabulation method:"<<houseRobberUsingTablution(houses,n-1)<<endl;
cout<<"maximum amount Rob  using space optimazation:"<<houseRobberSpaceOptimised(houses,n-1)<<endl;
return 0;
}
*/