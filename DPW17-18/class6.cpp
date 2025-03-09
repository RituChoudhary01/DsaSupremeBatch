// Q1.Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/description/

// Q2.Longest Palindromic Subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/description/
// Q3. Edit Distance
// https://leetcode.com/problems/edit-distance/description/

#include<iostream>
#include<vector>
using namespace std;
using namespace std;
/*
//Q1.
int solveUsingRec(string a,string b,int i,int j){
if(i==a.length()) return 0;
if(j==b.length()) return 0;
int ans = 0;
if(a[i]==b[j])
  ans = 1+solveUsingRec(a,b,i+1,j+1);
  else{
    ans = 0+max(solveUsingRec(a,b,i,j+1),solveUsingRec(a,b,i+1,j));
  }
  return ans;
}
int solveUsingMem(string&a, string &b,int i,int j,vector<vector<int> >&dp){
    if(i==a.length()) return 0;
    if(j == b.length()) return 0;
    if(dp[i][j]!= -1) return dp[i][j];
    int ans = 0;
    if(a[i]==b[j])
        ans =  1 + solveUsingMem(a,b, i+1, j+1, dp);
        else {
            ans =  0 + max(solveUsingMem(a,b,i,j+1, dp),solveUsingMem(a,b,i+1,j, dp));
        }
        dp[i][j] =  ans;
        return dp[i][j];
}
int solveUsingTab(string a, string b) {
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));
        for(int i = a.length()-1; i>=0; i--){
        for(int j = b.length()-1; j>=0; j--){
        int ans = 0;
        if(a[i] == b[j])
        ans =  1 + dp[i+1][j+1];
        else{
          ans =  0 + max(dp[i][j+1], dp[i+1][j]);
            }
            dp[i][j] =  ans;
            }
        }
        return dp[0][0];
        }
  int solveUsingTabSO(string a, string b) {
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);
        for(int i = a.length()-1; i>=0; i--) {
        for(int j = b.length()-1; j>=0; j--) {
        int ans = 0;
        if(a[i] == b[j])
        ans =  1 + next[j+1];
        else {
         ans =  0 + max(curr[j+1], next[j]);
          }
         curr[j] =  ans;      
        }
            next = curr;
        }
        return next[0];
       }

    void longestCommonSubsequence(string text1, string text2){
        int i = 0;
        int j = 0 ;
        cout<<"Longest Common Subsequence using Recurssion: "<<solveUsingRec(text1, text2,i,j)<<endl;
        vector<vector<int> > dp(text1.length(), vector<int>(text2.length(), -1));
         cout<<"Longest Common Subsequence using memoization: "<<solveUsingMem(text1, text2, i, j, dp)<<endl;
        cout<<"Longest Common Subsequence using Tabulation: "<<solveUsingTab(text1, text2)<<endl;
        cout<<"Longest Common Subsequence using Space Optimazation: "<<solveUsingTabSO(text1, text2)<<endl;
    }
    int main(){
        string a,b;
        cout<<"Enter First string: "<<endl;
        getline(cin,a);
        cout<<"Enter second string: "<<endl;
        getline(cin,b);
        longestCommonSubsequence(a,b);
        return 0;
    }
    */
    
    /*
    // Q2.
    int solveUsingRec(int i, int j, string &s){
    if (i > j) return 0;
    if (i == j) return 1;
    if (s[i] == s[j]) 
        return 2 + solveUsingRec(i + 1, j - 1, s);
    else
    return max(solveUsingRec(i + 1, j, s), solveUsingRec(i, j - 1, s));
    }

    int solveUsingMemo(int i, int j, string &a, string &b, vector<vector<int> > &dp) {
    if (i >= a.length() || j >= b.length()) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (a[i] == b[j]) 
        return dp[i][j] = 1 + solveUsingMemo(i + 1, j + 1, a, b, dp);
    
    return dp[i][j] = max(solveUsingMemo(i + 1, j, a, b, dp), solveUsingMemo(i, j + 1, a, b, dp));
}

int solveUsingTab(string a, string b) {
    int n = a.length();
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));

     for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
     }
        return dp[0][0];
     }

      int solveUsingTabSO(string a, string b) {
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);
        for(int i = a.length()-1; i>=0; i--) {
            for(int j = b.length()-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j])
                    ans =  1 + next[j+1];
                else {
                    ans =  0 + max(curr[j+1], next[j]);
                }
                curr[j] =  ans;      
            }
            next = curr;
        }
        return next[0];
    }
    void longestPalindromeSubseq(string s){
        string first = s;
        reverse(s.begin(), s.end());
        string second = s;
        cout<<"size of Longest Palindrome Subseq using recurssion: "<<solveUsingRec(0,first.size()-1,first)<<endl;
        vector<vector<int> >dp(first.length(),vector<int>(second.length(),-1));
        cout<<"size of longest Palindrome Subseq using memoization: "<<solveUsingMemo(0,0,first,second,dp)<<endl;
        cout<<"size of Longest Palindrome Subseq using Tabulation: "<<solveUsingTab(first,second)<<endl; 
        cout<<"size of Longest Palindrome Subseq using space Optimazation: "<<solveUsingTabSO(first, second)<<endl;
    }
    int main(){
        string s;
        cout<<"Enter string: "<<endl;
        getline(cin,s);
         longestPalindromeSubseq(s);
         return 0;
    }
    */
   /**/
    // Q3.
    int solveUsingRecursion(string& a, string& b, int i, int j){
        if( i == a.length()) {
            return b.length()-j;
        }
        if(j == b.length()) {
            return a.length()-i;
        }
        int ans = 0;
        if(a[i] == b[j]) {
            ans = solveUsingRecursion(a,b,i+1,j+1);
        }
        else {
            int insert = 1 + solveUsingRecursion(a,b,i,j+1);
            int deleted = 1 + solveUsingRecursion(a,b,i+1,j);
            int replace = 1 + solveUsingRecursion(a,b,i+1, j+1);
            ans = min(insert, min(deleted, replace));
        }
        return ans;
    }
  
    int solveUsingMem(string& a, string& b, int i, int j, vector<vector<int> >& dp){
        if( i == a.length()) {
            return b.length()-j;
        }
        if(j == b.length()) {
            return a.length()-i;
        }
        if(dp[i][j] != -1) 
            return dp[i][j];

        int ans = 0;
        if(a[i] == b[j]) {
            ans = solveUsingMem(a,b,i+1,j+1, dp);
        }
        else {
            int insert = 1 + solveUsingMem(a,b,i,j+1, dp);
            int deleted = 1 + solveUsingMem(a,b,i+1,j, dp);
            int replace = 1 + solveUsingMem(a,b,i+1, j+1, dp);
            ans = min(insert, min(deleted, replace));
        }
        dp[i][j] =  ans;
        return dp[i][j];
    }

    int solveUsingTab(string a, string b) {
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1,0));
        for(int j =0; j<=b.length(); j++) {
            dp[a.length()][j] =  b.length()-j;
        }
        for(int i =0; i<=a.length(); i++) {
            dp[i][b.length()] = a.length() - i;
        }
        for(int i = a.length()-1; i>=0; i--){
            for(int j =b.length()-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]) {
                    ans = dp[i+1][j+1];
                }
                else {
                    int insert = 1 + dp[i][j+1];
                    int deleted = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];
                    ans = min(insert, min(deleted, replace));
                }
                dp[i][j] =  ans;
            }
        }
        return dp[0][0];
    }

int solveUsingSO(string a, string b) {
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);
        for(int j =0; j<=b.length(); j++){
            next[j] =  b.length()-j;
        }
        for(int i = a.length()-1; i>=0; i--){
            curr[b.length()] = a.length()-i;
            for(int j =b.length()-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j]) {
                    ans = next[j+1];
                }
                else {
                    int insert = 1 + curr[j+1];
                    int deleted = 1 + next[j];
                    int replace = 1 + next[j+1];
                    ans = min(insert, min(deleted, replace));
                }
                curr[j] =  ans;
            }
            next = curr;
        }
        return next[0];
    }

    void minDistance(string word1, string word2){
         if(word1.length() == 0){
            cout<<word2.length()<<endl;
            return;
         }
         if(word2.length() == 0){
            cout << word1.length();
            return;
         }
        int i = 0;
        int j = 0;
        cout<<"Minimum Distance using Recurssion: "<<solveUsingRecursion(word1, word2, i, j)<<endl;

        vector<vector<int> > dp(word1.length(), vector<int>(word2.length(), -1));
        cout<<"Minimum Distance using Memoization: "<<solveUsingMem(word1, word2, i, j,dp)<<endl;
         cout<<"Minimum Distance using Tabulation: "<<solveUsingTab(word1, word2)<<endl;
         cout<<"Minimum Distance using space Optimazation: "<<solveUsingSO(word1, word2)<<endl;
    }
    int main(){
        string a,b;
        cout<<"Enter First string: "<<endl;
        getline(cin,a);
         cout<<"Enter second string: "<<endl;
        getline(cin,b);
        minDistance(a,b);
        return 0;
    }
