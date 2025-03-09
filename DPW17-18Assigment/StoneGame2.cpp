// Stone Game II
// https://leetcode.com/problems/stone-game-ii/description/

#include <iostream>
#include <vector>
using namespace std;

// Recursion
int solve(vector<int>& piles, int i, int M, bool alice) {
    if (i >= piles.size()) return 0;
    int ans = alice ? INT_MIN : INT_MAX;
    int total = 0;

    for (int X = 1; X <= 2 * M; X++) {
        if (i + X > piles.size()) break;
        total += piles[i + X - 1];
        if (alice) {
            ans = max(ans, total + solve(piles, i + X, max(M, X), !alice));
        } else {
            ans = min(ans, solve(piles, i + X, max(M, X), !alice));
        }
    }
    return ans;
}

// Memoization
int solveTD(vector<int>& piles, int i, int M, bool alice, vector<vector<vector<int> > >& dp) {
    if (i >= piles.size()) return 0;
    if (dp[i][M][alice] != -1) return dp[i][M][alice];

    int ans = alice ? INT_MIN : INT_MAX;
    int total = 0;

    for (int X = 1; X <= 2 * M; X++) {
        if (i + X > piles.size()) break;
        total += piles[i + X - 1];
        if (alice) {
            ans = max(ans, total + solveTD(piles, i + X, max(M, X), !alice, dp));
        } else {
            ans = min(ans, solveTD(piles, i + X, max(M, X), !alice, dp));
        }
    }
    return dp[i][M][alice] = ans;
}

// Tabulation (Bottom-Up)
int solveBU(vector<int>& piles) {
    int n = piles.size();
    vector<vector<vector<int> > > dp(n + 1, vector<vector<int> >(n + 1, vector<int>(2, 0)));

    // Reverse prefix sum to get sum of remaining elements
    vector<int> suffixSum(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + piles[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int M = 1; M <= n; M++) {
            for (int alice = 0; alice <= 1; alice++) {
                int ans = alice ? INT_MIN : INT_MAX;
                int total = 0;

                for (int X = 1; X <= 2 * M; X++) {
                    if (i + X > n) break;
                    total = suffixSum[i] - suffixSum[i + X];  // Sum of X elements from i
                    if (alice) {
                        ans = max(ans, total + dp[i + X][max(M, X)][0]);  // Alice's turn
                    } else {
                        ans = min(ans, dp[i + X][max(M, X)][1]);  // Bob's turn
                    }
                }
                dp[i][M][alice] = ans;
            }
        }
    }
    return dp[0][1][1];  // Alice starts with M = 1
}

// Function to call all methods
void stoneGameII(vector<int>& piles) {
    cout << "Maximum number of stones Alice can get using Recursion: " << solve(piles, 0, 1, true) << endl;

    vector<vector<vector<int> > > dp(piles.size(), vector<vector<int> >(piles.size(), vector<int>(2, -1)));
    cout << "Maximum number of stones Alice can get using Memoization: " << solveTD(piles, 0, 1, true, dp) << endl;

    cout << "Maximum number of stones Alice can get using Tabulation: " << solveBU(piles) << endl;
}

int main() {
    int n;
    vector<int> piles;
    cout << "Enter size of piles vector: ";
    cin >> n;
    cout << "Enter elements of piles vector: ";
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        piles.push_back(input);
    }
    stoneGameII(piles);
    return 0;
}
