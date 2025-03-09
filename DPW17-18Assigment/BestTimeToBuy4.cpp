// Best time to buy and Sell stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

#include <iostream>
#include <vector>
using namespace std;
int solveRE(vector<int>& prices, int i, int buy, int limit){
    if (i >= prices.size() || limit == 0) return 0;
    int profit = 0;
    if (buy){
        int buyItProfit = -prices[i] + solveRE(prices, i + 1, 0, limit);
        int skipProfit = solveRE(prices, i + 1, 1, limit);
        profit = max(buyItProfit, skipProfit);
    } 
    else {
        int sellItProfit = prices[i] + solveRE(prices, i + 1, 1, limit - 1);
        int skipProfit = solveRE(prices, i + 1, 0, limit);
        profit = max(sellItProfit, skipProfit);
    }
    return profit;
}

int solveTD(vector<int>& prices, int i, int buy, int limit, vector<vector<vector<int> > >& dp){
    if (i >= prices.size() || limit == 0) return 0;
    if (dp[i][buy][limit] != -1)
        return dp[i][buy][limit];
    int profit = 0;
    if (buy){
        int buyItProfit = -prices[i] + solveTD(prices, i + 1, 0, limit, dp);
        int skipProfit = solveTD(prices, i + 1, 1, limit, dp);
        profit = max(buyItProfit, skipProfit);
    } 
    else{
        int sellItProfit = prices[i] + solveTD(prices, i + 1, 1, limit - 1, dp);
        int skipProfit = solveTD(prices, i + 1, 0, limit, dp);
        profit = max(sellItProfit, skipProfit);
    }
    dp[i][buy][limit] = profit;
    return profit;
}

int solveBU(vector<int>& prices,int k){
    int n = prices.size();
    vector<vector<vector<int> > > dp(n + 1, vector<vector<int> >(2, vector<int>(k+1, 0)));  
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy < 2; buy++) {
            for (int limit = 1; limit < 3; limit++) {
                int profit = 0;
                if (buy) {
                    int buyItProfit = -prices[i] + dp[i + 1][0][limit];
                    int skipProfit = dp[i + 1][1][limit];
                    profit = max(buyItProfit, skipProfit);
                } else {
                    int sellItProfit = prices[i] + dp[i + 1][1][limit - 1];
                    int skipProfit = dp[i + 1][0][limit];
                    profit = max(sellItProfit, skipProfit);
                }
                dp[i][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][2];
}

int solveSO(vector<int>& prices, int k) {
    int n = prices.size();
    vector<vector<int> > curr(2, vector<int>(k + 1, 0)), next(2, vector<int>(k + 1, 0)); 
    for (int i = n - 1; i >= 0; i--){
        for (int buy = 0; buy < 2; buy++){  
            for (int limit = 1; limit <= k; limit++){  
                int profit = 0;
                if (buy){
                    int buyItProfit = -prices[i] + next[0][limit];
                    int skipProfit = next[1][limit];
                    profit = max(buyItProfit, skipProfit);
                }
                else{
                    int sellItProfit = prices[i] + next[1][limit - 1];
                    int skipProfit = next[0][limit];
                    profit = max(sellItProfit, skipProfit);
                }
                curr[buy][limit] = profit;
            }
        }
        next = curr;  
    }
    return curr[1][k]; 
}

void maxProfit(vector<int>& prices,int k) {
    cout << "Max profit using recursion: " << solveRE(prices, 0, 1, k) << endl;
    
    vector<vector<vector<int> > > dp(prices.size(), vector<vector<int> >(2, vector<int>(k+1, -1)));
    cout << "Max profit using top-down DP: " << solveTD(prices, 0, 1, k, dp) << endl;
    
    cout << "Max profit using bottom-up DP: " << solveBU(prices,k) << endl;
    
    cout << "Max profit using space optimization: " << solveSO(prices,k) << endl;
}

int main() {
    int n,k;
    cout<<"Enter the value of k: "<<endl;
    cin>>k;
    cout << "Enter the size of Prices array:" << endl;
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the elements of the prices array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    maxProfit(prices,k);
    return 0;
}