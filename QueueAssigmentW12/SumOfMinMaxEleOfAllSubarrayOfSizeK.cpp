// Sum of min and max element of all subarray of size K
#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int sumOfMinMaxofAllWindowOfsizeK(vector<int>nums,int k){
    deque<int>dq,dq2;
    int ans = 0;
    // first window of k size
    for(int i=0;i<k;i++){
        // chote element remove krdo
        while(!dq.empty()&&nums[i]>=nums[dq.back()]){
            dq.pop_back();
        }
        // bade element remove krdo
        while(!dq2.empty()&&nums[i]<=nums[dq2.back()]){
            dq2.pop_back();
        }
        // inserting index so that we can checkout of window element
        dq.push_back(i);
        dq2.push_back(i);
    }
    ans+=nums[dq.front()]+nums[dq2.front()];
    // remaining window ko process
    for(int i=k;i<nums.size();i++){
        // out of window element ko remove krdia.
        if(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }
        if(!dq2.empty() && i-dq2.front()>=k){
            dq2.pop_front();
        }
        // ab ferse current element k liye chotte element ko remove krna h.
        while(!dq.empty() && nums[i]>=nums[dq.back()]){
            dq.pop_back();
        }
        while(!dq2.empty() && nums[i]<=nums[dq2.back()]){
            dq2.pop_back();
        }
        // inserting index so that we can checkout of window element
        dq.push_back(i);
        dq2.push_back(i);
        // current window ka answer store krna h
        ans+=nums[dq.front()]+nums[dq2.front()];
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the size of vector: "<<endl;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        nums.push_back(input);
    }
    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;
    cout<<sumOfMinMaxofAllWindowOfsizeK(nums,k)<<endl;
    return 0;
}