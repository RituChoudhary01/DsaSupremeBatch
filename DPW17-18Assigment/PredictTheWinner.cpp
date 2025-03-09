//Predict the winner
//https://leetcode.com/problems/predict-the-winner/description/ 

#include<iostream>
#include<vector>
using namespace std;

int solve (vector<int>&nums,int start,int end){
    if(start == end) return nums[start];
    int diffByStart  = nums[start]-solve(nums,start+1,end);
    int diffByEnd = nums[end]-solve(nums,start,end-1);
    return max(diffByStart,diffByEnd);
}

int solveTD(vector<int>&nums,int start,int end,vector<vector<int> >&dp){
    if(start == end) return nums[start];
    if(dp[start][end]!= -1) return dp[start][end];
    int diffByStart  = nums[start]-solveTD(nums,start+1,end,dp);
    int diffByEnd = nums[end]-solveTD(nums,start,end-1,dp);
    dp[start][end] =  max(diffByStart,diffByEnd);
    return  dp[start][end];
}
int solveBU(vector<int>& nums,vector<vector<int> >&dp){
    for(int i=0;i<nums.size();i++) dp[i][i]=nums[i];
    int i = nums.size();
    for(int start = nums.size()-1;start>=0;start--){
        for(int end = i;end<nums.size();end++){
            int diffByStart = nums[start]-dp[start+1][end];
            int diffByEnd = nums[end]-dp[start][end-1];
            dp[start][end]=max(diffByStart,diffByEnd);
        }
        i--;
    }
    return dp[0][nums.size()-1];
}

void PredictTheWinner(vector<int>& nums){
    int ans = solve(nums,0,nums.size()-1)>=0;
    cout<<"Player 1 win using recurrion: "<<ans<<endl;
    vector<vector<int> >dp(nums.size(),vector<int>(nums.size(),-1));
    ans =  solveTD(nums,0,nums.size()-1,dp)>=0;
    cout<<"Player 1 win using top down: "<<ans<<endl;
    vector<vector<int> >dp1(nums.size(),vector<int>(nums.size()+1,-1));
    ans =  solveBU(nums,dp1)>=0;
    cout<<"Player 1 win using Bottom up: "<<ans<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        nums.push_back(input);
    }
    PredictTheWinner(nums);
    return 0;
}