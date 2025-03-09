// Reducing Dishes
// https://leetcode.com/problems/reducing-dishes/

#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& sat,int i,int time){
    if(i==sat.size()) return 0;
    int includeLikeTimeCoeff = time*sat[i]+solve(sat,i+1,time+1);
    int excludeLikeTimeCoeff = solve(sat,i+1,time);
    return max(includeLikeTimeCoeff,excludeLikeTimeCoeff);
}

int solveTD(vector<int>& sat,int i,int time,vector<vector<int> >&dp){
    if(i==sat.size()) return 0;
    if(dp[i][time]!= -1) return dp[i][time];
    int includeLikeTimeCoeff = time*sat[i]+solveTD(sat,i+1,time+1,dp);
    int excludeLikeTimeCoeff = solveTD(sat,i+1,time,dp);
    return dp[i][time] = max(includeLikeTimeCoeff,excludeLikeTimeCoeff);
}

int solveBU(vector<int>& sat){
    vector<vector<int> >dp(sat.size()+1,vector<int>(sat.size()+2,0));
    for(int i=sat.size()-1;i>=0;i--){
        for(int j=sat.size();j>=1;j--){
            int includeLikeTimeCoeff = j*sat[i]+dp[i+1][j+1];
            int excludeLikeTimeCoeff = dp[i+1][j];
            dp[i][j]=max(includeLikeTimeCoeff,excludeLikeTimeCoeff);
        }
    }
    return dp[0][1];
}
void maxSatisfaction(vector<int>& satisfaction){
    sort(satisfaction.begin(),satisfaction.end());
    cout<<"maximum sum of like-time coefficient using Recurssion: "<<solve(satisfaction,0,1)<<endl;
    vector<vector<int> >dp(satisfaction.size(),vector<int>(satisfaction.size()+2,-1));
    cout<<"maximum sum of like-time coefficient using TopDown: "<<solveTD(satisfaction,0,1,dp)<<endl;
    cout<<"maximum sum of like-time coefficient using BottomUp: "<<solveBU(satisfaction)<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int>satisfaction;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        satisfaction.push_back(input);
    }
    maxSatisfaction(satisfaction);
    return 0;
}