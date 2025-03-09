// K-diff pairs in an array
// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

#include<iostream>
#include<vector>
#include<set>
using namespace std;
int findPairs(vector<int>& nums,int k){
  sort(nums.begin(),nums.end());
  set<pair<int,int> >ans;
  int i=0,j=1;
  while(j<nums.size()){
    int diff = nums[j]-nums[i];
    if(diff == k){
        ans.insert(make_pair(nums[i],nums[j]));
        i++,j++;
    }
    else if(diff > k) i++;
    else j++;
    if(i==j) j++;
  }
  return ans.size();
}

// Method 2
int BS(vector<int>& nums,int start,int x){
    int end = nums.size()-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(nums[mid]==x)
           return mid;
         else if(x>nums[mid])
            return mid+1;
         else end = mid-1;     
    }
    return -1;
}
int findPairs1(vector<int>& nums,int k){
   sort(nums.begin(),nums.end());
   set<pair<int,int> >ans;
   for(int i=0;i<nums.size();i++){
    if(BS(nums,i+1,nums[i]+k)!= -1){
        ans.insert(make_pair(nums[i],nums[i]+k));
    }
   }
   return ans.size();
}
int main(){
    int size;
    cout<<"Enter the size of array:"<<endl;
    cin>>size;
    vector<int>nums;
    for(int i=0;i<size;i++){
        int input;
        cin>>input;
        nums.push_back(input);
    }
    int k;
    cout<<"Enter the value of k:"<<endl;
    cin>>k;
    int count = findPairs(nums,k);
    cout<<"K-diff pairs in an array:  "<<count<<endl;
}
