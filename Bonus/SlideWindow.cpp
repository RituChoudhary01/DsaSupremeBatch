/*
Sliding Window:- 
the sliding window technique is a common approach used to solve problems that involve finding or analyzing a subset of elements in a larger data structure, such as an array or string.here are the key patterns often used in sliding window problem statements:
1.Fixed size Window
2.Variable size Window
3.Two Pointer Approach
4.Optimised Sliding Windows

Fixed-Size Windows
1 Maintain a window of a fixed size (usually a contiguous subset of elements).
2 Slide the window one element at a time to process the data.
learn.codehelp.in
maunemaucslaboratorylouszuagmall.com
3 Useful for finding the maximum, minimum, or some other calculation wittin a fixed-sized window.

Problem Statements:
1 Given an array of integers and a window size, find the maximum sum of any subarray of the given window size.
2 Given a string, find the length of the longest substring containing only unique characters within a fixed window size.
3 Given an array of temperatures, find the minimum number of days it takes for a contiguous window of size K to have increasing temperatures.
4 Given a binary array (containing only 0s and 1s), find the maximum number of consecutive 1s with at most K 0s allowed in the window.
5 Given a string of characters, find the smallest window length that contains all the characters of a given pattern.

Variable-Size Window
1 Start with a small window and gradually expand or shrink it based on certain conditions.
2 Useful when the size of the window is not fixed are depends on the problem requirements.
3 Often used to find a subarray or substring satisfying specific conditions (e.g., sum, product, or a certain property).

Variable Size Window problem list:
1.Given an array of positive integers and a target sum, find the minimum subarray length whose sum is greater than or equal to the target.
2.Given a string, find the longest substring with at most K distinct characters.
3.Given an array of non-negative integers, find the subarray of length K with the maximum average valve.
4.Given a string, find the length of the longest substring that can be formed by repeating exactly K times.
5. Given an array of integers, find the maximum product of a subarray with size at most K

2-Pointer Approach
• Two Pointers:
1 Use two pointers to define the boundaries of the window.
2 One pointer usually represents the start of the window, and the other represents the end.
3 Move the pointers within the data structure based on certain conditions.
4 Commonly used when the problem requires finding a target sum, a pair of elements, or a subarray with specific characteristics.

Optimised Window:
• Optimized Sliding Window:
1. Apply additional optimization techniques to improve the sliding window solution.
2.Examples include precomputing sums or frequencies, utilizing data structures like heaps or hash maps, or skipping unnecessary calculations.
3.Helps to reduce the time complexity and optimize the overall solution.

Problem Statements:
1.Given a string find the longest substring that contains at most k characters and has at least  K/2 repeating characters.
2.Given an array of integers, find the maximum product of a subarray with size at most K and the minimum product of a subarray with size at most K.
3.Given two strings, find the minimum window in the first string that contains all the characters of the second string, considering multiple possible windows.
4.Given a string, find the longest palindromic substring with at most K deletions allowed.
5.Given an array of integers, find the maximum sum of K non-overlapping subarrays.
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Q1.Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/description/

vector<int>maxSlidingWindow(vector<int>&nums,int k){
    deque<int>dq;
    // we will store indexes in dequeu
     vector<int>ans;
    // process first k size window
    for(int i=0;i<k;i++){
        while(!dq.empty()&&nums[dq.back()]<nums[i])
         dq.pop_back();
        //  insert element
        dq.push_back(i);
    }
    // ans store karlo first window ka
    ans.push_back(nums[dq.front()]);
    // remaining windows
    for(int i=k;i<nums.size();i++){
        if(!dq.empty()&& i-k>=dq.front())
          dq.pop_front();
          while(!dq.empty()&&nums[dq.back()]<nums[i])
           dq.push_back(i);
           ans.push_back(nums[dq.front()]);
    }
    return ans;
}
// Q2.Two sum
// https://leetcode.com/problems/two-sum/description/
static bool cmp(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}
vector<int>twoSum(vector<int>&nums,int target){
    vector<pair<int,int> >data;
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        int val = nums[i];
        int index = i;
        data.push_back({val,index});
    }
    sort(data.begin(),data.end(),cmp);
    int start = 0;
    int end = data.size()-1;
    while(start<end){
        if(data[start].first+data[end].first==target){
            ans.push_back(data[start].second);
            ans.push_back(data[end].second);
            break;
        }
        else if(data[start].first+data[end].first>target) end--;
        else start++;
    }
    return ans;
}
// Minimum size subarray
// https://leetcode.com/problems/minimum-size-subarray-sum/
int minSubArrayLen(int target,vector<int>& nums){
    int i=0;
    int j=0;
    int sum  = 0;
    int len = INT_MAX;
    while(j<nums.size()){
        //include current number 
        sum = sum+nums[j];
        //mere paas ek window ka sum ready h 
        while(sum>=target){
            // minimise->sum me se decrease karo,len bhi update krelna,i/start ko aage badhana padega
            len = min(len,j-i+1);
            sum = sum-nums[i];
            i++;
        }
        j++;
    }
}
// Q4.Minimum window Substring
// https://leetcode.com/problems/minimum-window-substring/
string minWindow(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        int start = 0;
        int ansIndex = -1;
        int ansLen = INT_MAX;
        if(len1 < len2) {
            return "";
        }
        unordered_map<char, int> strMap;
        unordered_map<char, int> patMap;
        //to keep track of all characters of P string
        for(int i=0; i<p.length(); i++) {
            char ch = p[i];
            patMap[ch]++;
        }
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            
            strMap[ch]++;
            //valid character -> jo character tumhare opattern me bhi ho 
            if(strMap[ch] <= patMap[ch] ) {
                count++;
            }
            if(count == len2) {
                //window is ready
                //minimise the window -> freq decrement, ans update , start ko aage badhana h 
                
                while(strMap[s[start]] > patMap[s[start]] ||patMap[s[start]] == 0 ) {
                    
                    if(strMap[s[start]] > patMap[s[start]])
                        strMap[s[start]]--;
                        
                    start++;
                }
                
                //ans update
                int lengthOfWindow = i - start + 1;
                if(lengthOfWindow < ansLen ) {
                    ansLen = lengthOfWindow;
                    ansIndex = start;
                }
            }
        }
        
        if(ansIndex == -1)
            return "";
        else
            return s.substr(ansIndex, ansLen);
    }
