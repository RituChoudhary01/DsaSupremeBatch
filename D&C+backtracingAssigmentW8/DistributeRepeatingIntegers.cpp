//Distribute Repeating Integers
// https://leetcode.com/problems/distribute-repeating-integers/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool canDistributeHelper(vector<int>& counts,vector<int>& quantity,int ithCustomer){
// BC
if(ithCustomer == quantity.size()) return true;

for(int i=0;i<counts.size();i++){
    if(counts[i]>= quantity[ithCustomer]){
        counts[i]-=quantity[ithCustomer];
        if(canDistributeHelper(counts,quantity,ithCustomer+1));
        return true;
    }
    counts[i]+=quantity[ithCustomer];
}
return false;
}
bool canDistribute(vector<int>& nums,vector<int>& quantity){
unordered_map<int,int>countMap;
for(auto num:nums)
 countMap[num]++;
 vector<int>counts;
 for(auto it:countMap)
   counts.push_back(it.second);
   sort(quantity.rbegin(),quantity.rend());
   return canDistributeHelper(counts,quantity,0);
}
int main(){
  int n1,n2;
  vector<int>nums,quantity;
  cout<<"Enter size of nums vector"<<endl;
  cin>>n1;
  cout<<"Enter element of nums vector"<<endl;
  for(int i=0;i<n1;i++){
    int input;
    cin>>input;
    nums.push_back(input);
  }
  cout<<"Enter size of quantity vector"<<endl;
  cin>>n2;
  cout<<"Enter element of quantity "<<endl;
  for(int i=0;i<n2;i++){
    int input;
    cin>>input;
    quantity.push_back(input);
  }
  cout<<canDistribute(nums,quantity);
  return 0;
}
