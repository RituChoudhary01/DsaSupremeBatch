// minimum difference in sums after removal of elements
// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
# define ll long long
long long minimumDiff(vector<int>& nums){
    int n = nums.size()/3;
    vector<ll>prefix(nums.size(),-1);
    vector<ll>suffix(nums.size(),-1);
    ll sum = 0;
    priority_queue<ll>pq;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        pq.push(nums[i]);
        // pop out max elements
        if(pq.size()>n){
            sum-=pq.top();
            pq.pop();
        }
        if(pq.size()==n){
            prefix[i]=sum;
        }
    }
        sum = 0;//max n element sum
        priority_queue<ll,vector<ll>,greater<ll> >pq2;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            pq2.push(nums[i]);
            // pop out min elements
            if(pq2.size()>n){
                sum-=pq2.top();
                pq2.pop();
            }
            if(pq2.size()==n){
                suffix[i]=sum;
            }
        }
        ll ans = LONG_LONG_MAX;
        for(int i = n-1;i<2*n;i++){
            ans = min(ans,prefix[i]-suffix[i+1]);
        }
        return ans;
    }
    int main(){
        int n;
        cout<<"Enter size of vector: "<<endl;
        cin>>n;
        vector<int>nums;
        for(int i=0;i<n;i++){
            int input;
            cin>>input;
           nums.push_back(input);
        }
        cout<<"Minimum Difference in sums: "<<minimumDiff(nums)<<endl;
        return 0;
    }
