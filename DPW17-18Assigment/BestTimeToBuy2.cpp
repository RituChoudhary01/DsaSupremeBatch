// Best time to buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
#include<iostream>
#include<vector>
using namespace std;
int solveRec(vector<int>& prices,int i,int buy){
    if(i>=prices.size()) return 0;
    int profit = 0;
    if(buy){
        int buyItProfit = -prices[i]+solveRec(prices,i+1,0);
        int skipProfit = solveRec(prices,i+1,1);
        profit = max(buyItProfit,skipProfit);
    }
    else{
        int sellItProfit = prices[i]+solveRec(prices,i+1,1);
        int skipProfit = solveRec(prices,i+1,0);
        profit = max(sellItProfit,skipProfit);
    }
    return profit;
}

int solveTD(vector<int>& prices,int i,int buy,vector<vector<int> >&dp){
    if(i>=prices.size()) return 0;
    if(dp[i][buy]!= -1)return dp[i][buy];
    int profit = 0;
    if(buy){
        int buyItProfit = -prices[i]+solveTD(prices,i+1,0,dp);
        int skipProfit = solveTD(prices,i+1,1,dp);
        profit = max(buyItProfit,skipProfit);
    }
    else{
        int sellItProfit = prices[i]+solveTD(prices,i+1,1,dp);
        int skipProfit = solveTD(prices,i+1,0,dp);
        profit = max(sellItProfit,skipProfit);
    }
    dp[i][buy] = profit;
    return dp[i][buy];
}

int solveBU(vector<int>& prices,vector<vector<int> >&dp){
    for(int i=prices.size()-1;i>=0;i--){
        for(int buy = 0;buy<2;buy++){
            int profit = 0;
            if(buy){
                int buyItProfit = -prices[i]+dp[i+1][0];
                int skipProfit = dp[i+1][1];
                profit = max(buyItProfit,skipProfit);
            }
            else{
                int sellItProfit = prices[i]+dp[i+1][1];
                int skipProfit = dp[i+1][0];
                profit = max(sellItProfit,skipProfit);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

int solveSO(vector<int>& prices,vector<vector<int> >&dp){
    for(int i=prices.size()-1;i>=0;i--){
        for(int buy = 0;buy<2;buy++){
            int profit = 0;
            if(buy){
                int buyItProfit = -prices[i]+dp[1][0];
                int skipProfit = dp[1][1];
                profit = max(buyItProfit,skipProfit);
            }
            else{
                int sellItProfit = prices[i]+dp[1][1];
                int skipProfit = dp[1][0];
                profit = max(sellItProfit,skipProfit);
            }
            dp[1][buy] = profit;
        }
        dp[1] = dp[0];
    }
    return dp[0][1];
}
void maxProfit(vector<int>& prices){
    cout<<"max profit using Recurssion:"<<solveRec(prices,0
    ,true)<<endl;
    vector<vector<int> >dp(prices.size(),vector<int>(2,-1));
    cout<<"max profit using Memoization:"<< solveTD(prices,0,true,dp)<<endl;
    vector<vector<int> >dp1(prices.size()+1,vector<int>(2,0));
    cout<<"max profit using Tablution:"<<solveBU(prices,dp1)<<endl;
    cout<<"max profit using Space Optimastion :"<<solveSO(prices,dp1)<<endl;
} 
int main(){
int n;
cout<<"Enter the size of stocks array:"<<endl;
cin>>n;
vector<int>prices;
cout<<"Enter the element of stocks "<<endl;
for(int i=0;i<n;i++){
    int input;
    cin>>input;
    prices.push_back(input);
}
maxProfit(prices);
return 0;
}