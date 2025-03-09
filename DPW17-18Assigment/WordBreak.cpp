// Word Break
//https://leetcode.com/problems/word-break/description/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to check if a word exists in the dictionary
bool check(unordered_set<string>& wordSet, string& word) {
    return wordSet.find(word) != wordSet.end();
}

// Recursive Approach
bool solve(string &s, unordered_set<string>& wordSet, int start) {
    if (start == s.size()) return true;

    string word = "";
    for (int i = start; i < s.size(); i++) {
        word += s[i]; 
        if (check(wordSet, word) && solve(s, wordSet, i + 1)) {
            return true;
        }
    }
    return false;
}

// Top-Down DP (Memoization)
bool solveTD(string &s, unordered_set<string>& wordSet, int start, vector<int>& dp) {
    if (start == s.size()) return true;
    if (dp[start] != -1) return dp[start];

    string word = "";
    for (int i = start; i < s.size(); i++) {
        word += s[i];
        if (check(wordSet, word) && solveTD(s, wordSet, i + 1, dp)) {
            return dp[start] = true;
        }
    }
    return dp[start] = false;
}

// Bottom-Up DP (Tabulation)
bool solveBU(string &s, unordered_set<string>& wordSet) {
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[n] = true; 

    for (int start = n - 1; start >= 0; start--) {
        string word = "";
        for (int i = start; i < n; i++) {
            word += s[i];
            if (check(wordSet, word) && dp[i + 1]) {
                dp[start] = true;
                break; 
            }
        }
    }
    return dp[0];
}

void wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    cout << "Recursive Solution: " << (solve(s, wordSet, 0) ? "YES" : "NO") << endl;

    vector<int> dp(s.size(), -1);
    cout << "Memoization Solution: " << (solveTD(s, wordSet, 0, dp) ? "YES" : "NO") << endl;

    cout << "Tabulation Solution: " << (solveBU(s, wordSet) ? "YES" : "NO") << endl;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int n;
    cout << "Enter number of words in dictionary: ";
    cin >> n;

    vector<string> wordDict(n);
    cout << "Enter dictionary words: ";
    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }

    wordBreak(s, wordDict);
    return 0;
}
