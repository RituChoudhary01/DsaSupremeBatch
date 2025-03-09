// minimum ASCII Delete for two Strings
//https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
#include <iostream>
#include <vector>
using namespace std;

// Recursion
int solve(string &s1, string &s2, int i, int j) {
    if (i == s1.size()) {
        int cost = 0;
        for (int x = j; x < s2.size(); x++) cost += s2[x];
        return cost;
    }
    if (j == s2.size()) {
        int cost = 0;
        for (int x = i; x < s1.size(); x++) cost += s1[x];
        return cost;
    }

    if (s1[i] == s2[j]) return solve(s1, s2, i + 1, j + 1);

    int cost1 = s1[i] + solve(s1, s2, i + 1, j);
    int cost2 = s2[j] + solve(s1, s2, i, j + 1);

    return min(cost1, cost2);
}

// Memoization
int solveTD(string &s1, string &s2, int i, int j, vector<vector<int> > &dp){
    if (i == s1.size()) {
        int cost = 0;
        for (int x = j; x < s2.size(); x++) cost += s2[x];
        return cost;
    }
    if (j == s2.size()) {
        int cost = 0;
        for (int x = i; x < s1.size(); x++) cost += s1[x];
        return cost;
    }

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j]) return dp[i][j] = solveTD(s1, s2, i + 1, j + 1, dp);

    int cost1 = s1[i] + solveTD(s1, s2, i + 1, j, dp);
    int cost2 = s2[j] + solveTD(s1, s2, i, j + 1, dp);

    return dp[i][j] = min(cost1, cost2);
}

// Tabulation (Bottom-Up)
int solveBU(string &s1, string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    // Fill last row (remaining ASCII sum of s2)
    for (int j = n - 1; j >= 0; j--) dp[m][j] = dp[m][j + 1] + s2[j];

    // Fill last column (remaining ASCII sum of s1)
    for (int i = m - 1; i >= 0; i--) dp[i][n] = dp[i + 1][n] + s1[i];

    // Fill DP table
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i + 1][j + 1];
            else
                dp[i][j] = min(s1[i] + dp[i + 1][j], s2[j] + dp[i][j + 1]);
        }
    }
    return dp[0][0];
}

// Function to call all methods
void minimumDeleteSum(string s1, string s2) {
    cout << "Lowest ASCII sum of deleted characters using Recursion: " << solve(s1, s2, 0, 0) << endl;

    vector<vector<int> > dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    cout << "Lowest ASCII sum of deleted characters using Memoization: " << solveTD(s1, s2, 0, 0, dp) << endl;

    cout << "Lowest ASCII sum of deleted characters using Tabulation: " << solveBU(s1, s2) << endl;
}

int main() {
    string s1, s2;
    cout << "Enter the value of first string: ";
    cin >> s1;
    cout << "Enter the value of second string: ";
    cin >> s2;
    minimumDeleteSum(s1, s2);
    return 0;
}
