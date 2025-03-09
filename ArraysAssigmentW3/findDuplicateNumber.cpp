// Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/description/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //  // Method 1. Using inbuilt sort method T.C:O(nlogn),S.C: O(1);
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1]) return nums[i];
        // }
        // Method 2. Negative marking index method T.C:O(N),S.C:O(1);
        // int ans = -1;
        // for(int i=0;i<nums.size();i++){
        //     int index = abs(nums[i]);
        //     // already visited
        //     if(nums[index]<0){
        //         ans = index;
        //         break;
        //     }
        // // visited mark
        // nums[index]*=-1;
        // }
        
        // return ans;

        // Method 3:Positioning method
        while(nums[0]!= nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }   
};
int main(){
    vector<int>nums;
    int n;
    cout<<"Enter the size of vector:"<<endl;
    cin>>n;
    cout<<"Enter the element of vector which lies between 1 to n: "<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    Solution s;
    cout<<s.findDuplicate(nums);
    return 0;
}