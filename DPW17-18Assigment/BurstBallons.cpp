// Brust Balloons
// https://leetcode.com/problems/burst-balloons/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive Approach (Brute Force)
int solveRec(vector<int>& nums, int start, int end) {
    if (start > end) return 0;
    
    int coins = 0;
    for (int i = start; i <= end; i++) {
        int cost = nums[start - 1] * nums[i] * nums[end + 1] 
                   + solveRec(nums, start, i - 1) 
                   + solveRec(nums, i + 1, end);
        coins = max(coins, cost);
    }
    return coins;
}

// Memoization (Top-Down DP)
int solveTD(vector<int>& nums, int start, int end, vector<vector<int> >& dp) {
    if (start > end) return 0;
    if (dp[start][end] != -1) return dp[start][end];

    int coins = 0;
    for (int i = start; i <= end; i++) {
        int cost = nums[start - 1] * nums[i] * nums[end + 1] 
                   + solveTD(nums, start, i - 1, dp) 
                   + solveTD(nums, i + 1, end, dp);
        coins = max(coins, cost);
    }
    return dp[start][end] = coins;
}

// Bottom-Up DP (Tabulation)
int solveBU(vector<int>& nums) {
    int n = nums.size() - 2;  // Excluding artificial boundaries
    vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));

    for (int length = 1; length <= n; length++) {  // Length of subarray
        for (int start = 1; start <= n - length + 1; start++) {
            int end = start + length - 1;
            for (int i = start; i <= end; i++) {
                int coins = nums[start - 1] * nums[i] * nums[end + 1] 
                            + dp[start][i - 1] + dp[i + 1][end];
                dp[start][end] = max(dp[start][end], coins);
            }
        }
    }
    return dp[1][n];
}

// Function to compute maximum coins from bursting balloons
void maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);  // Add boundary balloon at the start
    nums.push_back(1);  // Add boundary balloon at the end
    cout << "Maximum coins using recursion: " << solveRec(nums, 1, nums.size() - 2)<<endl;
    vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), -1));
     cout << "Maximum coins using memoization: " <<solveTD(nums, 1, nums.size() - 2, dp)<<endl;
     cout << "Maximum coins using tabulation: " <<solveBU(nums)<<endl;
}

int main() {
    int n;
    cout << "Enter number of balloons: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter balloon values: ";
    for (int i = 0; i < n; i++) cin >> nums[i];
    maxCoins(nums);
    return 0;
}
