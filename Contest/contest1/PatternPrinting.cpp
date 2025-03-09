/*
Q1.pattern printing
class Solution {
  public:
    vector<char> printPattern(int N) {
        // code here
        vector<char>ans;
        for(int i=0;i<N;i++){
            for(int j=0;j<=i;j++){
               ans.push_back('*');
            }
            ans.push_back(' ');
        }
        return ans;
    }
};
Q2.Beautiful Arrays
// User function Template for C++

class Solution {
  public:
    int beautifulArray(vector<int>& a, int x, int k) {
        int n = a.size();
        sort(a.begin(), a.end());

        vector<int> gap;
        for (int i = 1; i < n; i++) {
            int tmp = a[i] - a[i - 1];
            if (tmp > k) {
                gap.push_back(tmp);
            }
        }
        sort(gap.begin(), gap.end());
        int cnt = 0;
        for (int i = 0; i < gap.size(); i++) {
            int val = gap[i];
            int diff = val / k;
            if (val % k == 0) {
                diff--;
            }
            int mini = min(x, diff);
            x -= mini;
            val -= mini * k;
            if (val <= k) {
                cnt++;
            }
            if (x <= 0) {
                break;
            }
        }
        int ans = gap.size() - cnt + 1;
        return ans;
    }    
};
Q3.Strange Matrix
class Solution{   
private:
    // do not edit this function
    // use it to get the value of A[i][j]
    int get(int i,int j){
        return a.get(i,j);
    }
public:
    int solve(int R,int C){
        //code here
           int maxOnesRow = 0;
        int maxOnes = 0;
        int j = C - 1;  // Start from the last column

        for (int i = 0; i < R; i++) {
            while (j >= 0 && get(i, j) == 1) { // Move left for more 1s
                j--;
                maxOnes = C - (j + 1);
                maxOnesRow = i;
            }
        }
        return maxOnesRow;
    }
};
// Q4.Stable Array
class Solution{
  public:
  int stableArray(vector<int>& a){
      //Code Here
      int n = a.size();
        map<int,int> mp;
        vector<int> v;
    	for(auto&x:a){
    		mp[x]++;
    	}
    	for(auto i :mp){
    		v.push_back(i.second);
    	}
    	sort(v.begin(),v.end());
    	int ans=INT_MAX;
    	for(int i: v){
    		int temp = lower_bound(v.begin(),v.end(),i)-v.begin();
    		int flag = v.size()-temp;
    		ans = min(ans,n-flag*i);
    	}
    	return ans;
  }
};
// Q5.Awesome Pairs
class Solution {
  public:
    long long pairs(int N, int arr[]) {
        long long int c[31] = {0}, ans = 0;
        for (int i = 0; i < N; i++){
            if(arr[i]==0) continue;
            int j = 0;
            while (arr[i]/(1<<j) != 0) j++;
            c[j-1]++;
        }
        for (int i = 0; i < 31; i++) 
            ans += (c[i] * (c[i] - 1)) / 2;
        return ans;
    }
};

*/