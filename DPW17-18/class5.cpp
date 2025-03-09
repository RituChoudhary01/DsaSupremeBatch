// Q1.Guess Number Higher or Lower II
// https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
// Q2.Minium cost tree from leaf values.
// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
// Q1.
int solveUsingRecursion(int start,int end){
    if(start>=end) return 0;
    int ans = INT_MAX;
    for(int i=start;i<=end;i++){
        ans = min(ans,i+max(solveUsingRecursion(start,i-1),solveUsingRecursion(i+1,end)));
    }
    return ans;
}

int solveUsingMem(int start,int end,vector<vector<int> >&dp){
    if(start>=end) return 0;
    if(dp[start][end] != -1){
        return dp[start][end];
    }
    int ans = INT_MAX;
    for(int i=start;i<=end;i++){
        ans = min(ans,i+max(solveUsingMem(start,i-1,dp),solveUsingMem(i+1,end,dp)));
    }
    dp[start][end] = ans;return ans;
}

int solveUsingTab(int n){
    vector<vector<int> >dp(n+2,vector<int>(n+2,0));
    for(int start = n;start>=1;start--){
       for(int end = 1; end<=n; end++) {
        if(start>=end)continue;
        else {
        int ans = INT_MAX;
        for(int i=start; i<=end; i++) {
         ans = min(ans, i + max(dp[start][i-1],dp[i+1][end]));
         }
         dp[start][end] = ans;
        }  
    }
}
return dp[1][n];
}
void getMoneyAmount(int n) {
        cout<<"Solve using Recurssion: "<<solveUsingRecursion(1,n)<<endl;
        vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        cout<<"Solve using Memosation: "<<solveUsingMem(1, n, dp)<<endl;
        cout<<"Solve using tabulation: "<<solveUsingTab(n)<<endl;
     }
    int main(){
        int n;
        cout<<"Enter the value of n: "<<endl;
        cin>>n;
        getMoneyAmount(n);
        return 0;
    }
   */ 
/*
//Q2.
*/
// Recursion
int solveUsingRecursion(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right) {
    if (left == right) return 0;
    int ans = INT_MAX;

    for (int i = left; i < right; i++) {
        ans = min(ans, 
                  maxi[make_pair(left, i)] * maxi[make_pair(i + 1, right)] +
                  solveUsingRecursion(arr, maxi, left, i) + 
                  solveUsingRecursion(arr, maxi, i + 1, right));
    }
    return ans;
}

// Memoization
int solveUsingMem(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right, vector<vector<int> >& dp) {
    if (left == right) return 0;
    if (dp[left][right] != -1) return dp[left][right];
    int ans = INT_MAX;
    for (int i = left; i < right; i++) {
        ans = min(ans, 
                maxi[make_pair(left, i)] * maxi[make_pair(i + 1, right)] +
                solveUsingMem(arr, maxi, left, i, dp) + 
                solveUsingMem(arr, maxi, i + 1, right, dp));
    }
    return dp[left][right] = ans;
}

// Tabulation
int solveUsingTab(vector<int>& arr, map<pair<int, int>, int>& maxi) {
    int n = arr.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));

    for (int left = n - 1; left >= 0; left--) {
        for (int right = left + 1; right < n; right++) {  // Corrected loop range
            int ans = INT_MAX;
            for (int i = left; i < right; i++) {
                ans = min(ans, 
                          maxi[make_pair(left, i)] * maxi[make_pair(i + 1, right)] + 
                          dp[left][i] + dp[i + 1][right]);
            }
            dp[left][right] = ans;
        }
    }

    return dp[0][n - 1];
}
 void mctFromLeafValues(vector<int>& arr){
 map<pair<int, int>, int> maxi; 
  for (int i = 0; i < arr.size(); i++) {
        maxi[make_pair(i, i)] = arr[i]; 

        for (int j = i + 1; j < arr.size(); j++) {
            maxi[make_pair(i, j)] = max(arr[j], maxi[make_pair(i, j - 1)]);
        }
    }
    int n = arr.size();
    cout<<"Solve using Recurssion: "<<solveUsingRecursion(arr, maxi, 0, n-1)<<endl;
    vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
    cout<<"Solve using Memosation: "<<solveUsingMem(arr, maxi, 0, n-1, dp)<<endl;
    cout<<"Solve using Tabulation: "<<solveUsingTab(arr, maxi)<<endl;
}
int main() {
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        arr.push_back(input);
    }
    mctFromLeafValues(arr);
    return 0;
}
