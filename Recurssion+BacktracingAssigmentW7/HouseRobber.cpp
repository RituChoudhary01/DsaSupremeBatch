// House Robber
//https://leetcode.com/problems/house-robber/description/
#include<iostream>
#include<vector>
using namespace std;
int robHelper(vector<int>& nums,int i){
    if(i>=nums.size()){
        return 0;
    }
    // 1 case
    int robAmt1 = nums[i]+robHelper(nums,i+2);
    int robAmt2 = 0+robHelper(nums,i+1);
    return max(robAmt1,robAmt2);
}
int rob(vector<int>&nums){
    return robHelper(nums,0);
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
    cout<<"Maximum amount of rob is: "<<rob(nums)<<endl;
    return 0;
}
// This solution give TLE it optimize it using DP.