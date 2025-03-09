// Stone Game III
// https://leetcode.com/problems/stone-game-iii/description/

#include<iostream>
#include<vector>
using namespace std;
int solveRec(vector<int>&v,int i){
    if(i==v.size()) return 0;
    int ans = INT_MIN;
    int total = 0;
    for(int X = 1;X<=3;X++){
        if(i+X-1>=v.size()) break;
        total+=v[i+X-1];
        ans = max(ans,total-solveRec(v,i+X));
    }
    return ans;
}

int solveTD(vector<int>&v,int i,vector<int>&dp){
    if(i==v.size()) return 0;
    if(dp[i]!= -1) return dp[i];
    int ans = INT_MIN;
    int total = 0;
    for(int X = 1;X<=3;X++){
        if(i+X-1>=v.size()) break;
        total+=v[i+X-1];
        ans = max(ans,total-solveRec(v,i+X));
    }
    return dp[i] = ans;
}

int solveBU(vector<int>& v){
    vector<int>dp(v.size()+1,0);
    for(int i=v.size()-1;i>=0;i--){
        int ans = INT_MIN;
        int total = 0;
        for(int X = 1;X<=3;X++){
            if(i+X-1>=v.size()) break;
            total+=v[i+X-1];
            ans = max(ans,total-dp[i+X]);
        }
        dp[i] = ans;
    }
    return dp[0];
}
void stoneGameIII(vector<int>&stoneValue){
    int ans = solveRec(stoneValue,0);
    cout<<"Return will win using Reccursion: ";
    if(ans>0) cout<<"Alice"<<endl;
    if(ans<0) cout<<"Bob"<<endl;
    if(ans==0) cout<<"Tie"<<endl;
    vector<int>dp(stoneValue.size()+1,-1);
   int ans1 =  solveTD(stoneValue,0,dp);
    cout<<"Return will win using Memoization: ";
    if(ans1>0) cout<<"Alice"<<endl;
    if(ans1<0) cout<<"Bob"<<endl;
    if(ans1==0) cout<<"Tie"<<endl;
   int ans2 =  solveBU(stoneValue);
    cout<<"Return will win using Tabulation: ";
    if(ans2>0) cout<<"Alice"<<endl;
    if(ans2<0) cout<<"Bob"<<endl;
    if(ans2==0) cout<<"Tie"<<endl;
}
int main() {
    int n;
    vector<int> stoneValue;
    cout << "Enter size of stoneValue vector: ";
    cin >> n;
    cout << "Enter elements of stoneValue vector: ";
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
       stoneValue.push_back(input);
    }
    stoneGameIII(stoneValue);
    return 0;
}