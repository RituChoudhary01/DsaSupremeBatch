// Target Sum
// https://leetcode.com/problems/target-sum/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Recursion 
int solve(vector<int>& nums, int target, int i){
    if (i == nums.size()) return target == 0 ? 1 : 0;
    int plus = solve(nums, target - nums[i], i + 1);
    int minus = solve(nums, target + nums[i], i + 1);
    return plus + minus;
}

// Top-Down DP 
int solveTD(vector<int>& nums, int target, int i, unordered_map<string, int>& dp) {
    if (i == nums.size()) return target == 0 ? 1 : 0;
    string key = to_string(i) + "," + to_string(target);
    if (dp.find(key) != dp.end()) return dp[key];
    int plus = solveTD(nums, target - nums[i], i + 1, dp);
    int minus = solveTD(nums, target + nums[i], i + 1, dp);
    return dp[key] = plus + minus;
}

// Bottom-Up DP 
int solveBU(vector<int>& nums, int target) {
    int totalSum = 0;
    for (int num : nums) totalSum += num;
    if (abs(target) > totalSum) return 0; 
    int n = nums.size();
    vector<vector<int> > dp(n + 1, vector<int>(2 * totalSum + 1, 0));
    dp[n][totalSum] = 1; 
    for (int i = n - 1; i >= 0; i--) {
        for (int sum = -totalSum; sum <= totalSum; sum++) {
            if (dp[i + 1][sum + totalSum] > 0) {
                dp[i][sum + nums[i] + totalSum] += dp[i + 1][sum + totalSum];
                dp[i][sum - nums[i] + totalSum] += dp[i + 1][sum + totalSum];
            }
        }
    }
    return dp[0][target + totalSum];
}

// Function to find ways to reach target sum
void findTargetSumWays(vector<int>& nums, int target) {
    cout << "Total Ways using Recursive Solution: " << solve(nums, target, 0) << endl;

    unordered_map<string, int> dp;
    cout << "Total Ways using Memoization Solution: " << solveTD(nums, target, 0, dp) << endl;

    cout << "Total Ways using Tabulation Solution: " << solveBU(nums, target) << endl;

}

// Driver Code
int main() {
    int n;
    cout<<"Enter size of nums: "<<endl;
    cin>>n;
    vector<int> nums; 
    cout<<"Enter element of nums: "<<endl;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        nums.push_back(input);
    }
    int target;
    cout<<"Enter target"<<endl;
    cin>>target;
    findTargetSumWays(nums, target);
    return 0;
}

