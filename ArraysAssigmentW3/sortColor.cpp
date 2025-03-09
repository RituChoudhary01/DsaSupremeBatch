// Sort color
// leetcode 75.
// https://leetcode.com/problems/sort-colors/description/

#include<iostream>
#include <vector>
using namespace std;

int main(){
   vector<int>nums;
    int size;
    cout<<"Enter the size of array:"<<endl;
    cin>>size;
    cout<<"Enter the element:"<<endl;
    for(int i=0;i<size;i++){
        int element;
        cin>>element;
        nums.push_back(element);
    }
    // // Method 1 using inbuilt sort function
    // sort(nums.begin(),nums.end());
    // for(int i=0;i<size;i++){
    //     cout<<nums[i]<<" ";
    // }
    // // T.C = O(nlogn),S.C = O(1);

    // Method 2 using count 0's,1's ans 2's.
    // int zeroCount = 0;
    // int oneCount = 0;
    // int twoCount = 0;
    // for(int i=0;i<nums.size();i++){
    //     if(nums[i]==0){
    //         zeroCount++;
    //     }
    //     else if(nums[i]==1){
    //         oneCount++;
    //     }
    //     else{
    //         twoCount++;
    //     }
    // }
    // int i=0;
    // while(zeroCount--){
    //     nums[i]=0;
    //     i++;
    // }
    // while(oneCount--){
    //     nums[i]=1;
    //     i++;
    // }
    // while(twoCount--){
    //     nums[i]=2;
    //     i++;
    // }
    // for(int i=0;i<nums.size();i++){
    //      cout<<nums[i]<<" ";
    // }
    // T.C = O(n),S.C =O(1) but not inplace solution.
    // Method 3 using Dutch National Flag Algorithm
    int zero = 0;
    int one = 0;
    int two = nums.size()-1;
    while(one<=two){
        if(nums[one]==0){
            swap(nums[zero],nums[one]);
            zero++;
            one++;
        }
        else if(nums[one]==1){
            one++;
        }
        else{
            swap(nums[one],nums[two]);
            two--;
        }
    }
     for(int i=0;i<nums.size();i++){
         cout<<nums[i]<<" ";
    }
    return 0;
}