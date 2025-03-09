//Valid Anagram
//https://leetcode.com/problems/valid-anagram/description/
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 using sorting
bool isAnagram1(string s,string t){
    sort(s.begin(),s.end()); 
    sort(t.begin(),t.end());   
    if(s==t) return true;
    else return false;
}
bool isAnagram2(string s,string t){
  vector<int>freq(256,0);
    for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
    for(int i=0;i<t.size();i++){
            freq[t[i]]--;
        }
    for(int i=0;i<256;i++){
            if(freq[i]!=0)
              return false;
        }
        return true;
    }
// Approach 2 using counting
int main(){
 string s,t;
 cout<<"Enter the first string: ";
 getline(cin,s);
  cout<<"Enter the second string: ";
 getline(cin,t);
 cout<<"Both string are anagram: "<<isAnagram1(s,t)<<endl;
 cout<<"Both string are anagram: "<<isAnagram2(s,t)<<endl;
  return 0;
}
