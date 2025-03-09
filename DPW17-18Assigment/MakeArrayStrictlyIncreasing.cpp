// make Array Strictly increasing.
// https://leetcode.com/problems/make-array-strictly-increasing/description/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define INF  1e9 + 1

// Recursive Solution
int solve(vector<int>& arr1, vector<int>& arr2, int prev, int i) {
    if (i == arr1.size()) return 0;

    int op1 = INF;
    if (prev < arr1[i]) 
        op1 = solve(arr1, arr2, arr1[i], i + 1);

    int op2 = INF;
    auto it = upper_bound(arr2.begin(), arr2.end(), prev);
    if (it != arr2.end()) {
        int index = it - arr2.begin();
        op2 = 1 + solve(arr1, arr2, arr2[index], i + 1);
    }

    return min(op1, op2);
}

// Memoized (Top-Down DP) Solution
int solveTD(vector<int>& arr1, vector<int>& arr2, int prev, int i, map<pair<int, int>, int>& dp) {
    if (i == arr1.size()) return 0;
    if (dp.find(make_pair(prev, i)) != dp.end()) return dp[make_pair(prev, i)];

    int op1 = INF;
    if (prev < arr1[i]) 
        op1 = solveTD(arr1, arr2, arr1[i], i + 1, dp);

    int op2 = INF;
    auto it = upper_bound(arr2.begin(), arr2.end(), prev);
    if (it != arr2.end()) {
        int index = it - arr2.begin();
        op2 = 1 + solveTD(arr1, arr2, arr2[index], i + 1, dp);
    }
    return dp[make_pair(prev, i)] = min(op1, op2);
}

// Function to find the minimum replacements needed
int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    sort(arr2.begin(), arr2.end()); 
    int ans = solve(arr1, arr2, -1, 0);

    map<pair<int, int>, int> dp;
    // int ans = solveTD(arr1, arr2, -1, 0, dp);

    return ans == INF ? -1 : ans;
}

int main() {
    int n, m;
    cout << "Enter size of arr1: ";
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter elements of arr1: ";
    for (int i = 0; i < n; i++) cin >> arr1[i];

    cout << "Enter size of arr2: ";
    cin >> m;
    vector<int> arr2(m);
    cout << "Enter elements of arr2: ";
    for (int i = 0; i < m; i++) cin >> arr2[i];

    int result = makeArrayIncreasing(arr1, arr2);
    cout << "Minimum number of replacements: " << result << endl;

    return 0;
}
