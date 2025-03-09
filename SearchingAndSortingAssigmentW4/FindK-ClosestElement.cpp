// Find K Closest Elements
// https://leetcode.com/problems/find-k-closest-elements/description/

#include<iostream>
#include<vector>
#include<set>
using namespace std;
//method 1
vector<int> twoPtrMethod(vector<int>& nums,int k,int x){
  int l=0,h=nums.size()-1;
  while(h-l>=k){
    if(x-nums[l]>nums[h]-x) l++;
    else h--;
  }
//   vector<int>ans;
//   for(int i=l;i<=h;i++){
//     ans.push_back(nums[i]);
//   }
//   return ans;
return vector<int>(nums.begin()+l,nums.begin()+h+1);
}

// Method 2
int lowerBound(vector<int>& arr, int x){
    int start = 0,end = arr.size()-1;
    int ans = end;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]>=x){
            ans = mid;
            end = mid-1;
        }
        else if(x>arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}    
vector<int>bs_method(vector<int>& arr,int k,int x){
    int h = lowerBound(arr,x);
    int l = h-1;
    while(k--){
        if(l<0)h++;
        else if(h>=arr.size()){
            l--;
        }
        else if(x-arr[l]>arr[h]-x){
            h++;
        }
        else{
            l--;
        }
    }
    return vector<int>(arr.begin()+l+1,arr.begin()+h);
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
    int x;
    cin>>x;
    vector<int>ans = twoPtrMethod(nums,k,x);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}