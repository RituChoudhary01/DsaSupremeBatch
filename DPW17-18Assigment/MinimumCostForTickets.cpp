// Minimum cost for tickets
// https://leetcode.com/problems/minimum-cost-for-tickets/description/
#include<iostream>
#include<vector>
using namespace std;
int minCostTicketHelper(vector<int>& days,vector<int>& costs,int i){
    // BC
    if(i>=days.size()) return 0;
    // sol for 1 case
    // 1 day pass taken
    int cost1 = costs[0] + minCostTicketHelper(days,costs,i+1);
    // 7 days pass taken
    int passEndDay = days[i]+7-1;
    int j=i;
    while(j<days.size()&& days[j]<=passEndDay){
        j++;
    }
    int cost7 = costs[1]+minCostTicketHelper(days,costs,j);
    // 30 days pass taken
    passEndDay = days[i]+30-1;
    j=i;
    while(j<days.size()&& days[j]<=passEndDay){
        j++;
    }
    int cost30 = costs[2]+minCostTicketHelper(days,costs,j);
    return min(cost1,min(cost7,cost30));
}

int minCostTicketHelperTD(vector<int>& days,vector<int>& costs,int i,vector<int>&dp){
if(i>=days.size()) return 0;
if(dp[i]!=-1) return dp[i];
 if(i>=days.size()) return 0;
    // sol for 1 case
    // 1 day pass taken
    int cost1 = costs[0] + minCostTicketHelper(days,costs,i+1);
    // 7 days pass taken
    int passEndDay = days[i]+7-1;
    int j=i;
    while(j<days.size()&& days[j]<=passEndDay){
        j++;
    }
    int cost7 = costs[1]+minCostTicketHelper(days,costs,j);
    // 30 days pass taken
    passEndDay = days[i]+30-1;
    j=i;
    while(j<days.size()&& days[j]<=passEndDay){
        j++;
    }
    int cost30 = costs[2]+minCostTicketHelper(days,costs,j);
    dp[i] =  min(cost1,min(cost7,cost30));
    return dp[i];
}
int minCostTicketHelperBU(vector<int>& days,vector<int>& costs,int i,vector<int>&dp){
    // BC
    dp[days.size()]=0;
    for(int i = days.size()-1;i>=0;i--){
    // 1 days pass taken
    int cost1 = costs[0]+dp[i+1];
    // 7 days pass taken
    int passEndDay = days[i]+7-1;
    int j=i;
    while(j<days.size()&& days[j]<=passEndDay){
        j++;
    }
    int cost7 = costs[1]+dp[j];
    // 30 days pass taken
    passEndDay = days[i]+30-1;
    j=i;
    while(j<days.size()&& days[j]<=passEndDay){
        j++;
    }
    int cost30 = costs[2]+dp[j];
    dp[i] =  min(cost1,min(cost7,cost30));
}
return dp[0];
}
 void mincostTickets(vector<int>& days, vector<int>& costs) {

     cout<<"minimum number of costs solve using Reccurision: "<<minCostTicketHelper(days,costs,0)<<endl;
     int n = days.size();   
     vector<int>dp(n+1,-1);
      cout<<"minimum number of costs solve using Memoization: "<<minCostTicketHelperTD(days,costs,0,dp)<<endl;
     vector<int>dp1(n+30,0);
     cout<<"minimum number of costs solve using Tablution: "<<minCostTicketHelperBU(days,costs,0,dp1)<<endl;
     
    }
    int main(){
        int n;
        vector<int>days;
        vector<int>costs;
        cout<<"Enter the size of days vector"<<endl;
        cin>>n;
        cout<<"Enter the value of days vector"<<endl;
        for(int i=0;i<n;i++){
            int input;
            cin>>input;
            days.push_back(input);
        }
        cout<<"Enter the value of costs"<<endl;
        for(int i=0;i<3;i++){
            int input;
            cin>>input;
            costs.push_back(input);
        }
        mincostTickets(days,costs);
        return 0;
    }