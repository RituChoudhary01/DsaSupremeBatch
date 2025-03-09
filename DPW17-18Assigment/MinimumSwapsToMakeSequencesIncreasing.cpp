// Minimum Swaps to make sequences increasing. 
// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive Solution
int solve(vector<int>& nums1, vector<int>& nums2, int i, int prev1, int prev2) {
    if (i == nums1.size()) return 0;
    int swap = INT_MAX, noSwap = INT_MAX;
    // Swap condition
    if (prev1 < nums2[i] && prev2 < nums1[i]) {
        swap = 1 + solve(nums1, nums2, i + 1, nums2[i], nums1[i]);
    }
    // No swap condition
    if (prev1 < nums1[i] && prev2 < nums2[i]) {
        noSwap = solve(nums1, nums2, i + 1, nums1[i], nums2[i]);
    }
    return min(swap, noSwap);
}

// Memoization (Top-Down DP)
int solveTD(vector<int>& nums1, vector<int>& nums2, int i, int swapped, vector<vector<int> >& dp) {
    if (i == nums1.size()) return 0;
    if (dp[i][swapped] != -1) return dp[i][swapped];

    int prev1 = (swapped) ? nums2[i - 1] : nums1[i - 1];
    int prev2 = (swapped) ? nums1[i - 1] : nums2[i - 1];

    int swap = INT_MAX, noSwap = INT_MAX;

    // Swap condition
    if (prev1 < nums2[i] && prev2 < nums1[i]) {
        swap = 1 + solveTD(nums1, nums2, i + 1, 1, dp);
    }
    // No swap condition
    if (prev1 < nums1[i] && prev2 < nums2[i]) {
        noSwap = solveTD(nums1, nums2, i + 1, 0, dp);
    }
    return dp[i][swapped] = min(swap, noSwap);
}

// Bottom-Up DP (Tabulation)
int solveBU(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<vector<int> > dp(n + 1, vector<int>(2, INT_MAX));
    
    dp[0][0] = 0; // No swap at first index
    dp[0][1] = 1; // Swap at first index

    for (int i = 1; i < n; i++) {
        if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) {
            dp[i][0] = dp[i - 1][0]; // No swap at i
            dp[i][1] = dp[i - 1][1] + 1; // Swap at i
        }
        if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1); // Swap at i
            dp[i][0] = min(dp[i][0], dp[i - 1][1]); // No swap at i
        }
    }

    return min(dp[n - 1][0], dp[n - 1][1]);
}
// Function to call all three approaches
void minSwapSequences(vector<int>& nums1, vector<int>& nums2) {
    cout << "Minimum swaps using Recursion: " << solve(nums1, nums2, 1, nums1[0], nums2[0]) << endl;
    vector<vector<int> > dp(nums1.size(), vector<int>(2, -1));
    cout << "Minimum swaps using Memoization: " << solveTD(nums1, nums2, 1, 0, dp) << endl;
    cout << "Minimum swaps using Tabulation: " << solveBU(nums1, nums2) << endl;
}

// Main Function
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums1(n), nums2(n);
    cout << "Enter elements of first sequence: ";
    for (int i = 0; i < n; i++) cin >> nums1[i];

    cout << "Enter elements of second sequence: ";
    for (int i = 0; i < n; i++) cin >> nums2[i];

    minSwapSequences(nums1, nums2);
    return 0;
}
