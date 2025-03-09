// Interleaving String
// https://leetcode.com/problems/interleaving-string/description/

#include<iostream>
#include<vector>
using namespace std;
// recurssion
bool solve(string &s1,string &s2,string &s3,int i,int j,int k){
    if(i==s1.size()&&j==s2.size()&&k==s3.size()) return true;
    bool flag = false;
    if(i<s1.size()&&s1[i]==s3[k])
      flag = flag || solve(s1,s2,s3,i+1,j,k+1);
    if(j<s2.size()&&s2[j]==s3[k])
     flag = flag||solve(s1,s2,s3,i,j+1,k+1);
    return flag;  
}

bool solveTD(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<vector<int> > >&dp){
    if(i==s1.size()&&j==s2.size()&&k==s3.size()) return true;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    bool flag = false;
    if(i<s1.size()&&s1[i]==s3[k])
      flag = flag || solve(s1,s2,s3,i+1,j,k+1);
    if(j<s2.size()&&s2[j]==s3[k])
    flag = flag||solve(s1,s2,s3,i,j+1,k+1);
    return dp[i][j][k] =  flag;  
}

int solveBU(string &s1,string &s2,string &s3,int i,int j,int k){
vector<vector<vector<int> > >dp(s1.size()+1,vector<vector<int> >(s2.size()+1,vector<int>(s3.size()+1,-1)));
dp[s1.size()][s2.size()][s3.size()] = 1;
for(int i = s1.size();i>=0;i--){
    for(int j=s2.size();j>=0;j--){
        for(int k=s3.size();k>=0;k--){
             if(i==s1.size()&&j==s2.size()&&k==s3.size()) continue;
            bool flag = false;
           if(i<s1.size()&&s1[i]==s3[k])
            flag = flag || solve(s1,s2,s3,i+1,j,k+1);
          if(j<s2.size()&&s2[j]==s3[k])
           flag = flag||solve(s1,s2,s3,i,j+1,k+1);
           dp[i][j][k] =  flag;  
        }
    }
}
return dp[0][0][0];
}

void isInterval(string s1,string s2,string s3){
   cout<<"interleaving of two strings s and t is possible using Recurssion: "<< solve(s1,s2,s3,0,0,0)<<endl;
    vector<vector<vector<int> > >dp(s1.size()+1,vector<vector<int> >(s2.size()+1,vector<int>(s3.size()+1,-1)));
    cout<<"interleaving of two strings s and t is possible using Memoization: "<<solveTD(s1,s2,s3,0,0,0,dp)<<endl;
    cout<<"interleaving of two strings s and t is possible using Tabulation: "<<solveBU(s1,s2,s3,0,0,0)<<endl;
}
int main(){
  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  isInterval(s1,s2,s3);
  return 0;
}