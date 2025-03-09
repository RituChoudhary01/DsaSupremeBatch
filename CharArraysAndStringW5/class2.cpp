#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*Q1.Leetcode 1047 Remove all adjacent Duplicates in string.
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

class Solution {
public:
    string removeDuplicates(string s){
        string ans ="";
        int i = 0;
        while( i < s.length()){
        if(ans.length() > 0  &&  ans[ans.length() - 1] == s[i]) {
            ans.pop_back();
          }
        else {
            ans.push_back(s[i]);
           }
        i++;
        }
        return ans;
    }
};
int main(){
    string str;
    getline(cin,str);
    Solution s;
    string ans = s.removeDuplicates(str);
    cout<<ans;
}
*/

/*Q2.Leetcode Problem 1910 Remove all occurrences of a substring
https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

class Solution{
public:
    string removeOccurrences(string s, string part) {
        int pos = s.find(part);
        while(pos != string::npos){
            s.erase(pos, part.length());
            pos = s.find(part);
        }
        return s;
    }
};
int main(){
    string str,part;
    getline(cin,str);
    getline(cin,part);
    Solution s;
    string ans = s.removeOccurrences(str,part);
    cout<<ans;
}
*/
/*Q3.Leetcode 680 Valid Palindrome II
https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution {
public:
    bool checkPalindrome(string s, int i, int j ) {
        while(i <= j) {
            if(s[i] != s[j] )
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s){
        int i = 0;
        int j = s.length() - 1;

        while(i<=j) {
            if(s[i] != s[j]) {
                //ek baar i ko remove, ek baar j ko remove
                return checkPalindrome(s,i+1, j) || checkPalindrome(s, i, j-1);
            }
            else {
                //s[i] == s[j]
                i++;
                j--;
            }
        }
        return true;
    }
};

int main(){
    string str;
    getline(cin,str);
    Solution s;
    bool isCheck = s.validPalindrome(str);
    if(isCheck) cout<<"True";
    else cout<<"False";
    return 0;
}
*/

/*Q4.Leetcode 539 Minimum Time Difference
https://leetcode.com/problems/minimum-time-difference/description/
*/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints){
        //step1: convert time string into minutes integer value
        vector<int> minutes;
        for(int i=0; i<timePoints.size(); i++) {
            string curr = timePoints[i];

            int hours = stoi( curr.substr(0,2) );
            int min = stoi( curr.substr(3,2) );
            int totalMinutes = hours*60 + min;
            minutes.push_back(totalMinutes);
        }

        //Step2: sort
        sort(minutes.begin(), minutes.end());

        //Step3: difference and calculate min diff
        int mini = INT_MAX;
        int n = minutes.size();

        for(int i=0; i<n-1; i++) {
            int diff = minutes[i+1] - minutes[i];
            mini = min(mini, diff);
        }

        //something missing - THIS IS THE GAME
        int lastDiff1 = (minutes[0] + 1440) - minutes[n-1];
        int lastDiff2 = minutes[n-1] - minutes[0];
        int lastDiff = min(lastDiff1, lastDiff2);
        mini = min(mini, lastDiff);

        return mini;

    }
};
/*Q5. Leetcode 649 Palindromic Substring
https://leetcode.com/problems/palindromic-substrings/description/
*/
class Solution {
public:
    int expandAroundIndex(string s, int left, int right) {
        int count = 0;
        //jab tak match karega, tab tak count increment kardo and i piche and j aaage kardo
        while(left >= 0 && right <s.length() && s[left] == s[right] ) {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int totalCount = 0;
        int n = s.length();

        for(int center=0; center<n; center++) {
            //odd
            int oddKaAns = expandAroundIndex(s, center, center);
            totalCount = totalCount + oddKaAns;
            //even
            int evenKaAns = expandAroundIndex(s,center,center+1);
            totalCount = totalCount + evenKaAns;
        }

        return totalCount;
    }
};