// Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/description/
#include<iostream>
#include<vector>
using namespace std;
int solve(string &s,string &t,int i,int j){
    if(j==t.size()) return 1;
    if(i==s.size()) return 0;
    int ans = 0;
    if(s[i]==t[j])
        ans+=solve(s,t,i+1,j+1);
        ans+=solve(s,t,i+1,j);
        return ans;
    }

    int solveTD(string &s,string &t,int i,int j,vector<vector<int> >&dp){
    if(j==t.size()) return 1;
    if(i==s.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = 0;
    if(s[i]==t[j])
        ans+=solveTD(s,t,i+1,j+1,dp);
        ans+=solveTD(s,t,i+1,j,dp);
        return dp[i][j] =  ans;
    }
    int solveBU(string &s,string &t){
        vector<vector<int> >dp (s.size()+1,vector<int>(t.size()+1,0));
        for(int i=0;i<=s.size();i++){
            dp[i][t.size()]=1;
        }
        for(int i = s.size()-1;i>=0;i--){
            for(int j = t.size()-1;j>=0;j--){
                 dp[i][j] = dp[i + 1][j]; // Skip `s[i]`
                if (s[i] == t[j]) 
                dp[i][j] += dp[i + 1][j + 1]; 
            }
        }
        return dp[0][0];
    }

void numDistance(string &s,string &t){
    cout<<"number of distinct subsequences of s which equals t using reccursion: "<<solve(s,t,0,0)<<endl;
    vector<vector<int> >dp(s.size()+1,vector<int>(t.size()+1,-1));
    cout<<"number of distinct subsequences of s which equals t using Memoization: "<<solveTD(s,t,0,0,dp)<<endl;
    cout<<"number of distinct subsequences of s which equals t using Tabulation: "<<solveBU(s,t)<<endl;
}
int main(){
    string s = "rabbbit";
    string t = "rabbit";
    numDistance(s,t);
    return 0;

}