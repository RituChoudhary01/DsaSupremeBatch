// Number of Dice roll with target sum.
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
#include<iostream>
using namespace std;
int numRollsToTarget(int n,int k,int target){
    // BC
    if(target<0) return 0;
    if(n==0 && target == 0) return 1;
    if(n==0 && target!=0) return 0;
    if(n!=0 && target==0) return 0;
    int ans = 0;
    for(int i=1;i<=k;i++){
        ans = ans+numRollsToTarget(n-1,k,target-i);
    }
    return ans;
}
int main(){
   int n,k,target;
   cin>>n>>k>>target;
   cout<<numRollsToTarget(n,k,target);
   return 0;
}