/*
Q1.Debug the code. Matrix Chain Multiplication.
int MatrixChainOrder(int arr[], int n) {
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        dp[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L;
            for (k = i; k <= j - 1; k++) {
                q = dp[i][k] + dp[k + 1][j]
                    + arr[i - 1] * arr[k] * arr[j];
                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }
 
    return dp[0][n - 1];
}
Ans:-
int MatrixChainOrder(int arr[], int n) {
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        dp[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = dp[i][k] + dp[k + 1][j]
                    + arr[i - 1] * arr[k] * arr[j];
                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }
 
    return dp[1][n - 1];
}
// Q2.Debug the code. Paint Fence.
class Solution {
public:
    int numWays(int n, int k) {
				vector<int> dp(3,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(i==1)
                dp[1]=k;
            else
                dp[i]=(dp[i-2]+dp[i-1])*(k-1);            
        }
        return dp[n-1]*k;
    }
};
Ans:-
class Solution {
public:
    int numWays(int n, int k) {
	vector<int> dp(3,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(i==1)
                dp[1]=k;
            else
                dp[i%3]=(dp[(i-2)%3]+dp[(i-1)%3])*(k-1);            
        }
        return dp[(n-1)%3]*k;
    }
};
Q3.Debug the code. Paint House.
class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) {
            return 0;
        }

        int dp[2][3];
        for (int i= 0; i < 3; i++) {
            dp[0][i] = costs[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 3; j++) {
                dp[i&1][j] = INT_MAX;
                for (int k = 0; k < 3; k++) {
                    if (k != j) {
                        dp[i&1][j] = min(dp[i&1][j], dp[i&1][k] + costs[i][j]);
                    }
                }
            }
        }
        return min(dp[n&1^1][0], min(dp[n&1^1][1], dp[n&1^1][2]) );
    }

};
Ans:-
class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) {
            return 0;
        }

        int dp[2][3];
        for (int i= 0; i < 3; i++) {
            dp[0][i] = costs[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i&1][j] = INT_MAX;
                for (int k = 0; k < 3; k++) {
                    if (k != j) {
                        dp[i&1][j] = min(dp[i&1][j], dp[i&1^1][k] + costs[i][j]);
                    }
                }
            }
        }
        return min(dp[n&1^1][0], min(dp[n&1^1][1], dp[n&1^1][2]) );
    }

};

Q4.1. Debug the code. Ugly Number. 

An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

Given an integer `n`, return `true` if `n` is an ugly number

class Solution {
public:
    bool isUgly(int n) {
        if(n < 1)
            return false;
        int temp = n;
        while(n != 1){
            if(n % 2 == 0)
                n /= 2;
            else if(n % 3 == 0)
                n /= 3;
            else if(n % 5 == 0)
                n /= 5;
            if(temp == n)
                return true; 
            temp = n;
        }
        return false;
    }
};
Ans:-
class Solution {
public:
    bool isUgly(int n) {
        if(n < 1)
            return false;
        int temp = n;
        while(n != 1){
            if(n % 2 == 0)
                n /= 2;
            else if(n % 3 == 0)
                n /= 3;
            else if(n % 5 == 0)
                n /= 5;
            if(temp == n)
                return false;
            temp = n;
        }
        return true;
    }
};
Q5.Debug the code. Edit Distance.
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
    public:
    int editDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
         
        vector<int>prev(m+1, 0), curr(m+1, 0);
         
        for(int j =0; j<=m; j++) {
            prev[j] = j;
        }
         
        for(int i = 1; i <= n; i++) {
            curr[0] = i;
            for(int j = 1; j<= m; j++) {
                if(s[i-1] == t[j-1]) {
                    curr[j] = prev[j];
                }
                else {
                    int mn = min(1 + prev[j], 1 + curr[j-1]);
                    curr[j] = min(mn, 1 + prev[j-1]);                  
                }
            }
        }
         
        return prev[m];
    }
     
};
Ans:-
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
    public:
    int editDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
         
        vector<int>prev(m+1, 0), curr(m+1, 0);
         
        for(int j =0; j<=m; j++) {
            prev[j] = j;
        }
         
        for(int i = 1; i <= n; i++) {
            curr[0] = i;
            for(int j = 1; j<= m; j++) {
                if(s[i-1] == t[j-1]) {
                    curr[j] = prev[j-1];
                }
                else {
                    int mn = min(1 + prev[j], 1 + curr[j-1]);
                    curr[j] = min(mn, 1 + prev[j-1]);                  
                }
            }
            prev = curr;
        }
         
        return prev[m];
    }
     
};
*/ 