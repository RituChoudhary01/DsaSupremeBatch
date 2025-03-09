/*
Q1. Debug the code Clime Stairs
int climbStairs(int n) {
        int a = 1;
        int b = 1;

        for(int i = 2 ; i <= n ; i++){
            b = a;
            a = a + b ;
        }
        return a;
    }
   Ans:-
   int climbStairs(int n) {
    int a = 1;
    int b = 1;

    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        b = a;
        a = temp;
    }
    return a;
}

// Q2.Debug the code. Jump Game II.
class Solution {
public:
    int jump(vector<int>& nums) {

      for(int i = 1; i < nums.size(); i++) {
        nums[i] = nums[i] + i;
      }

      int curr = 0;
      int jumps = 0;

      while(curr <= nums.size() - 1) {
        jumps++;
        curr = nums[curr];
      }

      return jumps;
    }
};
Ans:-
int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0; // If there is only one element, no jumps needed

    int jumps = 0, farthest = 0, currentEnd = 0;

    for (int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + nums[i]); // Find the farthest index we can reach

        if (i == currentEnd) { // We reached the end of the current jump
            jumps++;
            currentEnd = farthest;

            if (currentEnd >= n - 1) break; // If we can reach the last index, break early
        }
    }

    return jumps;
}

// Q3.Debug the code. Longest Increasing Sequence.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(dp[i] > dp[j])
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        return dp[n-1];
    }
};
Ans:-
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);  // Each element starts with LIS length of 1
        int answer = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {  // Compare values in nums, not dp
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            answer = max(answer, dp[i]);  // Track the maximum LIS found
        }

        return answer;
    }
};

// Q4.Debug the code. Min Cost Path.
int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j]) + grid[i][j];
            }
        }
        return dp[m][n];
    }
    Ans:-
    int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the first cell
    dp[0][0] = grid[0][0];

    // Fill the first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill the first column
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill the remaining cells
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[m - 1][n - 1];  
    }

//Q5.Debug the code. Maximum Area of Square with 1. 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int maxi=0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i][j] == '1'){
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return maxi;
    }
};
Ans:-
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0; // Edge case: empty matrix
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxi = 0;

        // Fill DP table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // First row or first column, only 1s can form squares of size 1
                    } else {
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return maxi * maxi; // Return area of the maximal square
    }
};

*/