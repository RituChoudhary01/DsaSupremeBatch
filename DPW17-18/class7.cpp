// Q1.Longest Increasing Subsequence
//https://leetcode.com/problems/longest-increasing-subsequence/description/
// Q2.Maximum Height By Stacking Cuboids
//https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

#include<iostream>
#include<vector>
using namespace std;
/*
// Q1.LIS
int solveUsingRecursion(vector<int>& arr, int curr, int prev){
        if(curr >= arr.size()){
            return 0;
        }
        int include = 0;
        if(prev == -1 || arr[curr] > arr[prev])
            include = 1 + solveUsingRecursion(arr, curr+1, curr);
        int exclude = 0 + solveUsingRecursion(arr, curr+1, prev);
        int ans = max(include, exclude);
        return ans;
     }

    int solveUsingMem(vector<int>& arr, int curr, int prev, vector<vector<int> >& dp){
        if(curr >= arr.size()){
            return 0;
        }
        if(dp[curr][prev + 1] != -1)
           return dp[curr][prev+1];
        int include = 0;
        if(prev == -1 || arr[curr] > arr[prev])
            include = 1 + solveUsingMem(arr, curr+1, curr, dp);
        int exclude = 0 + solveUsingMem(arr, curr+1, prev, dp);
        dp[curr][prev + 1] = max(include, exclude);
            return dp[curr][prev + 1];
        }

    int solveUsingTab(vector<int>& arr){
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
         for(int curr = n-1; curr>=0; curr--) {
        for(int prev = curr - 1; prev >= -1; prev--) {
        int include = 0;
        if(prev == -1 || arr[curr] > arr[prev])
        include = 1 + dp[curr+1][curr + 1];
        int exclude = 0 + dp[curr+1][prev + 1];
        dp[curr][prev + 1] = max(include, exclude);   
          }
        }
        return dp[0][0];
    }
    
    int solveUsingSO(vector<int>& arr) {
        int n = arr.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev])
                    include = 1 + nextRow[curr + 1];
                int exclude = 0 + nextRow[prev + 1];
                currRow[prev + 1] = max(include, exclude);   
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int solveOptimal(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;
        vector<int> ans;
        ans.push_back(arr[0]);

        for(int i=1; i<arr.size(); i++) {
            if(arr[i] > ans.back()) {
                ans.push_back(arr[i]);
            }
            else {
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        return ans.size();
    }

    void lengthOfLIS(vector<int>& nums){
        int curr = 0;
        int prev = -1;
        cout<<" Length of longest increasing subsequence using reccursion: "<<solveUsingRecursion(nums, curr, prev )<<endl;
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int>(n+1, -1));
        cout<<" Length of longest increasing subsequence using Memoization: "<<solveUsingMem(nums, curr, prev, dp)<<endl;
         cout<<" Length of longest increasing subsequence using Tabulation: "<<solveUsingTab(nums)<<endl;
         cout<<" Length of longest increasing subsequence using space optimazation 1: "<<solveUsingSO(nums)<<endl;
        cout<<" Length of longest increasing subsequence using space optimazation 2: "<<solveOptimal(nums)<<endl;
        }
        int main(){
            int n;
            cout<<"Enter the size of vector: "<<endl;
            cin>>n;
            vector<int>nums;
            cout<<"Enter the element of vector: "<<endl;
            for(int i=0;i<n;i++){
                int input;
                cin>>input;
                nums.push_back(input);
            }
            lengthOfLIS(nums);
            return 0;
        }
        */
    //Q2.Maximum Height By Stacking Cuboids

    bool check(vector<int>& a, vector<int>& b) {
        return (b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2]);
    }

    int solveRecursive(vector<vector<int> >& arr, int curr, int prev){
        if (curr >= arr.size()) return 0;
        // Include the current cuboid
        int include = 0;
        if (prev == -1 || check(arr[curr], arr[prev])) {
            include = arr[curr][2] + solveRecursive(arr, curr + 1, curr);
        }
        // Exclude the current cuboid
        int exclude = solveRecursive(arr, curr + 1, prev);
        return max(include, exclude);
    }

    int solveMemo(vector<vector<int> >& arr, int curr, int prev, vector<vector<int> >& dp){
        if (curr >= arr.size()) return 0;
        if (dp[curr][prev + 1] != -1) return dp[curr][prev + 1];
        // Include the current cuboid
        int include = 0;
        if (prev == -1 || check(arr[curr], arr[prev])) {
            include = arr[curr][2] + solveMemo(arr, curr + 1, curr, dp);
        }
        // Exclude the current cuboid
        int exclude = solveMemo(arr, curr + 1, prev, dp);
        return dp[curr][prev + 1] = max(include, exclude);
    }
    int solveTabulation(vector<vector<int> >& arr) {
        int n = arr.size();
        vector<int> dp(n, 0);
         for (int i = 0; i < n; i++){
            dp[i] = arr[i][2]; // Base case: max height with only one cuboid
         }

        for (int curr = 1; curr < n; curr++) {
            for (int prev = 0; prev < curr; prev++) {
                if (check(arr[curr], arr[prev])) {
                    dp[curr] = max(dp[curr], arr[curr][2] + dp[prev]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    int solveSpaceOptimized(vector<vector<int> >& arr) {
        int n = arr.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i][2];
        }
        for (int curr = 1; curr < n; curr++) {
            for (int prev = 0; prev < curr; prev++) {
                if (check(arr[curr], arr[prev])) {
                    dp[curr] = max(dp[curr], arr[curr][2] + dp[prev]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }


    void maxHeight(vector<vector<int> >& cuboids) {
        for (auto &a : cuboids) {
            sort(a.begin(), a.end()); 
        }
        sort(cuboids.begin(), cuboids.end());  

        cout<<" Maximum height using reccursion: "<<solveRecursive(cuboids, 0, -1)<<endl;
        int n = cuboids.size();
        vector<vector<int> > dp(n, vector<int>(n + 1, -1));
        cout<<" Maximum height using Memoization: "<<solveMemo(cuboids, 0, -1, dp)<<endl;
        cout<<" Maximum height using  Tabulation : "<<solveTabulation(cuboids)<<endl;
        cout<<" Maximum height using Space Optimized: "<<solveSpaceOptimized(cuboids)<<endl;
    }
    int main(){
        int row,col;
        cout<<"Enter number of row in cuboids: "<<endl;
        cin>>row;
        cout<<"Enter number of column in cuboids: "<<endl;
        cin>>col;
        vector<vector<int> >cuboids;
        cout<<"Enter the element of cuboids: "<<endl;
        for(int i=0;i<row;i++){
            vector<int>temp;
            for(int j=0;j<col;j++){
                int input;
                cin>>input;
                temp.push_back(input);
            }
            cuboids.push_back(temp);
        }
        maxHeight(cuboids);
        return 0;
   }

