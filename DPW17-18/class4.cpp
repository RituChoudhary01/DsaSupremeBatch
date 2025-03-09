// Q1.Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/description/
// Q2. Number of Dice Rolls With Target Sum
//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#include<iostream>
#include<vector>
using namespace std;
 long long int MOD = 1000000007;
/*
// Q1.
 bool solveUsingRecursion(int index, vector<int>& nums, int target) {
        //base case
        int n = nums.size();
        if(index >= n)
            return 0;

        if(target < 0)
            return 0;

        if(target == 0) 
            return 1;

        bool include = solveUsingRecursion(index+1, nums, target-nums[index]);
        bool exclude = solveUsingRecursion(index+1, nums, target);

        return (include || exclude);
    }

    bool solveUsingMem(int index, vector<int>& nums, int target, vector<vector<int> >& dp) {
        //base case
        int n = nums.size();
        if(index >= n)
            return 0;

        if(target < 0)
            return 0;

        if(target == 0) 
            return 1;

        if(dp[index][target] != -1)
            return dp[index][target];

        bool include = solveUsingMem(index+1, nums, target-nums[index], dp);
        bool exclude = solveUsingMem(index+1, nums, target, dp);

        dp[index][target] = (include || exclude);
        return dp[index][target];
    }

    bool solveUsingTabulation(vector<int>& nums, int target,  vector<vector<int> >& dp) {
        int n = nums.size();
        
        for(int i=0; i<nums.size(); i++) {
            dp[i][0] = 1;
        }

        for(int index = n-1; index>=0; index--) {
            for(int t = 1; t<=target; t++) {
                bool include = 0;
                if(t-nums[index] >=0)
                    include = dp[index+1][t-nums[index]];

                bool exclude = dp[index+1][t];

                dp[index][t] = (include || exclude);
            }
        }

        return dp[0][target];
    }


    bool solveUsingTabulationSO(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);

        curr[0] = 1;
        next[0] = 1;

        for(int index = n-1; index>=0; index--) {
            for(int t = 1; t<=target; t++) {
                bool include = 0;
                if(t-nums[index] >=0)
                    include = next[t-nums[index]];

                bool exclude = next[t];

                curr[t] = (include || exclude);
            }
            next = curr;
        }

        return next[target];
    }
    void canPartition(vector<int>& nums){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum & 1){
        cout<<false<<endl;
        return;
        }
        int target = sum/2;
        int index = 0;
        cout<<"using recurssion:"<<
        solveUsingRecursion(index, nums, target)<<endl;
        vector<vector<int> > dp(nums.size(), vector<int>(target+1, -1));
        cout<<"using Top down Approach: "<<solveUsingMem(index, nums, target, dp)<<endl;
        int n = nums.size();

        vector<vector<int> > dp1(n + 1, vector<int>(target+1, 0));   
        cout<<"using bottom up approach: "<< solveUsingTabulation(nums,target, dp1)<<endl;
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
        canPartition(nums);
        return 0;
    }
    */
// Q2.
int solveUsingRecursion(int n, int k , int target){
        //base case
        if(n < 0)
            return 0;
        if(n == 0 && target == 0)
            return 1;
        if(n == 0 && target != 0) 
            return 0;
        if(n != 0 && target == 0)
            return 0;

        int ans = 0;
        for(int i=1; i<=k; i++){
            ans += solveUsingRecursion(n-1, k , target-i);
        }
        return ans;
    }

    long long int solveUsingMem(  int n,  int k ,   int target,  vector<vector< long long int> >& dp) {
        //base case
        if(n < 0)
            return 0;
        if(n == 0 && target == 0)
            return 1;
        if(n == 0 && target != 0) 
            return 0;
        if(n !=0 && target == 0)
            return 0;
        
        if(dp[n][target] != -1)
            return dp[n][target];

        long long int ans = 0;
        for(int i=1; i<=k; i++){
            long long int recAns = 0;
            if(target - i >= 0)
                recAns = solveUsingMem(n-1, k , target-i, dp);
            ans = (ans % MOD + recAns % MOD) % MOD;
        }
        dp[n][target] =  ans;
        return dp[n][target];
    }

    int solveUsingTabulation(int n, int k, int target) {
        vector<vector< long long int> > dp(n+1, vector< long long int>(target+1, 0));
        dp[0][0] = 1;

        for(int index = 1; index <=n; index++) {
            for(int t=1; t<=target; t++) {
                long long int ans = 0;
                for(int i=1; i<=k; i++) {
                    long long int recAns = 0;
                    if(t - i >= 0 )
                        recAns = dp[index-1][t-i];
                    ans = (ans % MOD + recAns % MOD) % MOD;
                }
                dp[index][t] =  ans;
            }
        }

    return dp[n][target];

    }

    int solveUsingSO(int n, int k, int target) {

        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        prev[0] = 1;

        for(int index = 1; index <=n; index++) {
            for(int t=1; t<=target; t++) {

                long long int ans = 0;
                for(int i=1; i<=k; i++) {
                    long long int recAns = 0;
                    if(t - i >= 0 )
                        recAns = prev[t-i];
                    ans = (ans % MOD + recAns % MOD) % MOD;
                }
                curr[t] =  ans;
            }
            prev = curr;
        }
        return prev[target];
}
void numRollsToTarget(int n, int k, int target) {
        cout<<"solve using recurrision: "<<solveUsingRecursion(n,k,target)<<endl;
        vector<vector< long long int> > dp(n+1, vector< long long int>(target+1, -1));
        cout<<"solve using memoization: "<<solveUsingMem(n,k,target, dp)<<endl;
        cout<<"solve using tabulation: "<< solveUsingTabulation(n, k, target)<<endl;
        cout<<"solve using space optizamation: "<< solveUsingSO(n, k, target)<<endl;
    }
   int main(){
   int n,k,target;
   cin>>n>>k>>target;
   numRollsToTarget(n,k,target);
   return 0;
}

