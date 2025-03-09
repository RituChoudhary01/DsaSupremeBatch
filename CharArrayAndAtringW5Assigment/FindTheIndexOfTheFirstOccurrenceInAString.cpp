// Find the Index of the First Occurrence in a String
//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include<iostream>
using namespace std;
int strStr(string haystack,string needle){
    int n = haystack.size();
    int m = needle.size();
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<m;j++){
            if(needle[j]!=haystack[i+j]){
                break;
            }
            if(j==m-1){
             return i;
            }
        }
    }
    return -1;
}

int main(){
    string haystack,needle;
    getline(cin,haystack);
    getline(cin,needle);
    cout<<strStr(haystack,needle)<<endl;
    return 0;
}