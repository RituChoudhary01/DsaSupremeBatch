// Permutations II
//https://leetcode.com/problems/permutations-ii/description/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
void permuteUniqueHelper(vector<int>& nums,vector<vector<int> >&ans,int start){
    // BC
    if(start == nums.size()){
        ans.push_back(nums);
        return;
    }
    unordered_map<int,bool>visited;
   for(int i=start;i<nums.size();i++){
    if(visited.find(nums[i])!= visited.end()) continue;
    visited[nums[i]]=true;
    swap(nums[i],nums[start]);
    permuteUniqueHelper(nums,ans,start+1);
    swap(nums[i],nums[start]);
   }
}
vector<vector<int> > permuteUnique(vector<int>& nums){
   vector<vector<int> >ans;
   permuteUniqueHelper(nums,ans,0);
   return ans;    
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
    vector<vector<int> >ans = permuteUnique(nums);
    for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[0].size();j++){
    cout<<ans[i][j]<<" ";
}
cout<<endl;
}
cout<<endl;
return 0;
}
