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
    int cost1 = costs[0]+minCostTicketHelper(days,costs,i+1);
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
 int mincostTickets(vector<int>& days, vector<int>& costs) {

     return minCostTicketHelper(days,costs,0);   
     
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
        cout<<mincostTickets(days,costs);
        return 0;
    }