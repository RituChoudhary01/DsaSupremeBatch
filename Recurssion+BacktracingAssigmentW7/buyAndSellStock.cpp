// Leetcode 121 best time to buy and sell stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include<iostream>
#include<vector>
using namespace std;
void maxProfitFinder(vector<int>&prices,int i,int& minPrice,int& maxProfit){
    // base case
    if(i==prices.size()) return;
    // solution for one case
    if(prices[i]<minPrice)
      minPrice = prices[i];
 int todayProfit = prices[i]-minPrice;
 if(todayProfit>maxProfit)
   maxProfit = todayProfit;
//RE
maxProfitFinder(prices,i+1,minPrice,maxProfit);
}
int maxProfit(vector<int>&prices){
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;
    maxProfitFinder(prices,0,minPrice,maxProfit);
    return maxProfit;
}
int main(){
    int n;
    cin>>n;
    vector<int>prices;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        prices.push_back(input);
    }
    cout<<maxProfit(prices)<<endl;
    return 0;
}

