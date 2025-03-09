// Russian Doll Envelopes
//https://leetcode.com/problems/russian-doll-envelopes/description/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<vector<int> >& env, int prev, int i) {
    if (i == env.size()) return 0;
    
    int include = INT_MIN;
    if (prev == -1 || (env[prev][0] < env[i][0] && env[prev][1] < env[i][1]))
        include = 1 + solve(env, i, i + 1);
        int exclude = solve(env, prev, i + 1);
        return max(include, exclude);
}

int solveTD(vector<vector<int> >& env, int prev, int i, vector<vector<int> >& dp) {
    if (i == env.size()) return 0;
    if (dp[prev + 1][i] != -1) return dp[prev + 1][i];

    int include = INT_MIN;
    if (prev == -1 || (env[prev][0] < env[i][0] && env[prev][1] < env[i][1]))
        include = 1 + solveTD(env, i, i + 1, dp);

    int exclude = solveTD(env, prev, i + 1, dp);

    return dp[prev + 1][i] = max(include, exclude);
}

// Comparator for sorting envelopes
static bool comp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) return a[1] > b[1]; // Sort heights in descending order if widths are equal
    return a[0] < b[0]; // Otherwise, sort by increasing width
}

// Optimized LIS solution using binary search (Patience Sorting)
int solveOptimal(vector<vector<int> >& env) {
    if (env.empty()) return 0;

    // Sort envelopes by width (inc) and height (dec if same width)
    sort(env.begin(), env.end(), comp);

    vector<int> lis;
    
    for (int i = 0; i < env.size(); i++) {
        int h = env[i][1];

        auto it = lower_bound(lis.begin(), lis.end(), h);
        if (it == lis.end()) {
            lis.push_back(h); // Extend LIS
        } else {
            *it = h; // Replace to maintain lowest possible values
        }
    }

    return lis.size();
}

// Driver function
void maxEnvelopes(vector<vector<int> >& envelopes) {
    sort(envelopes.begin(), envelopes.end()); // Sorting for recursive approach

    cout << "Max Envelopes using Recursion: " << solve(envelopes, -1, 0) << endl;
    
    vector<vector<int> > dp(envelopes.size() + 1, vector<int>(envelopes.size() + 1, -1));
    cout << "Max Envelopes using Memoization: " << solveTD(envelopes, -1, 0, dp) << endl;
    
    cout << "Max Envelopes using Optimized LIS: " << solveOptimal(envelopes) << endl;
}

int main() {
    int n;
    cout << "Enter the number of envelopes: ";
    cin >> n;

    vector<vector<int> > envelopes(n, vector<int>(2));

    cout << "Enter the width and height of each envelope:\n";
    for (int i = 0; i < n; i++) {
        cin >> envelopes[i][0] >> envelopes[i][1];
    }

    maxEnvelopes(envelopes);

    return 0;
}
