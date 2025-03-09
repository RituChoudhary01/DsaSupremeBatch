// Ones and Zeroes
// https://leetcode.com/problems/ones-and-zeroes/description/

#include <iostream>
#include <vector>
using namespace std;

// Convert each string to a pair of (zeros, ones)
void convertStrsToNumStrs(vector<string>& strs, vector<pair<int, int> >& numStrs) {
    for (auto& str : strs) {
        int zeros = 0, ones = 0;
        for (auto ch : str) {
            if (ch == '0') zeros++;
            else ones++;
        }
        numStrs.push_back(make_pair(zeros, ones));
    }
}

// Recursion 
int solve(vector<pair<int, int> >& numStrs, int i, int m, int n) {
    if (i == numStrs.size()) return 0;

    int zeros = numStrs[i].first;
    int ones = numStrs[i].second;
    
    int include = 0, exclude = 0;
    
    if (m - zeros >= 0 && n - ones >= 0) {
        include = 1 + solve(numStrs, i + 1, m - zeros, n - ones);
    }
    exclude = solve(numStrs, i + 1, m, n);
    
    return max(include, exclude);
}

// Memoization (Top-Down DP)
int solveTD(vector<pair<int, int> >& numStrs, int i, int m, int n, vector<vector<vector<int> > >& dp) {
    if (i == numStrs.size()) return 0;
    if (dp[i][m][n] != -1) return dp[i][m][n];

    int zeros = numStrs[i].first;
    int ones = numStrs[i].second;

    int include = 0, exclude = 0;
    
    if (m - zeros >= 0 && n - ones >= 0) {
        include = 1 + solveTD(numStrs, i + 1, m - zeros, n - ones, dp);
    }
    exclude = solveTD(numStrs, i + 1, m, n, dp);
    
    return dp[i][m][n] = max(include, exclude);
}

// Bottom-Up DP (Tabulation)
int solveBU(vector<pair<int, int> >& numStrs, int m, int n) {
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    for (auto& numStr : numStrs) {
        int zeros = numStr.first;
        int ones = numStr.second;

        // Traverse in reverse to avoid overwriting previous results
        for (int j = m; j >= zeros; j--) {
            for (int k = n; k >= ones; k--) {
                dp[j][k] = max(dp[j][k], 1 + dp[j - zeros][k - ones]);
            }
        }
    }

    return dp[m][n];
}

// Function to call all three approaches
void findMaxForm(vector<string>& strs, int m, int n) {
    vector<pair<int, int> > numStrs;
    convertStrsToNumStrs(strs, numStrs);

    cout << "Size of the largest subset using Recursion: " << solve(numStrs, 0, m, n) << endl;

    vector<vector<vector<int> > > dp(strs.size(), vector<vector<int> >(m + 1, vector<int>(n + 1, -1)));
    cout << "Size of the largest subset using Memoization: " << solveTD(numStrs, 0, m, n, dp) << endl;

    cout << "Size of the largest subset using Tabulation: " << solveBU(numStrs, m, n) << endl;
}

// Main Function
int main() {
    int size, m, n;
    vector<string> strs;

    cout << "Enter size of vector: ";
    cin >> size;
    cin.ignore(); 

    cout << "Enter the strings: " << endl;
    for (int i = 0; i < size; i++) {
        string str;
        getline(cin, str);
        strs.push_back(str);
    }

    cout << "Enter values of m and n: ";
    cin >> m >> n;

    findMaxForm(strs, m, n);
    return 0;
}
