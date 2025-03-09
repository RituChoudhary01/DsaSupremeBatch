//Minimum Insertion Steps to make a string Palindrome
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int solveUsingTabSo(string a,string b){
    vector<int>curr(b.length()+1,0);
    vector<int>next(b.length()+1,0);
    for(int i = a.length()-1;i>=0;i--){
        for(int j=b.length()-1;j>=0;j--){
            int ans = 0;
            if(a[i]==b[i]) ans=1+next[j+1];
            else{
                ans = 0+max(curr[j+1],next[j]);
            }
            curr[j]=ans;
        }
        // shift
        next = curr;
    }
    return next[0];
}
int longestPalindromeSubseq(string& s){
    string first = s;
    reverse(s.begin(),s.end());
    string second = s;
    return solveUsingTabSo(first,second);
}
int minIntersections(string s){
    int LPS_len = longestPalindromeSubseq(s);
    int insertionsToDo = s.size()-LPS_len;
    return insertionsToDo;
}
int main(){
    string s;
    cout<<"Enter a string: "<<endl;
    cin>>s;
    cout<<minIntersections(s)<<endl;
    return 0;
}