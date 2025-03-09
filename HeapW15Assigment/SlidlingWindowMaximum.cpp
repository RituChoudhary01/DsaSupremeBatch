// Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/description/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>maxSlidingWindow(vector<int>& nums,int k){
    priority_queue<pair<int,int> >pq;
    vector<int>ans;
    // consider first window
    for(int i=0;i<k;i++){
        pq.push(make_pair(nums[i],i));
    }
    // store max of first window
    ans.push_back(pq.top().first);
    // consider rest of the windows
    for(int i=k;i<nums.size();i++){
        pq.push(make_pair(nums[i],i));
        // remove if max are from prev window
        while(pq.top().second<=i-k){
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}
int main(){
    int size;
    vector<int>nums;
    cout<<"Enter size of nums: "<<endl;
    cin>>size;
    cout<<"Enter element in nums: "<<endl;
    for(int i=0;i<size;i++){
        int input;
        cin>>input;
        nums.push_back(input);
    }
    int k;
    cout<<"Enter value of K: "<<endl;
    cin>>k;
    vector<int>ans = maxSlidingWindow(nums,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}