// Reverse Vowels of a string.
// https://leetcode.com/problems/reverse-vowels-of-a-string/description/

#include<iostream>
using namespace std;
bool isVowel(char ch){
   if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
     return true;
    else if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
      return true;
    else return false;  
}
string reverseVowels(string &s){
    int l = 0,h=s.size()-1;
    while(l <= h){
         if(isVowel(s[l]) && isVowel(s[h])){
                swap(s[l],s[h]);
                l++,h--;
            }
            else if(!isVowel(s[l])) l++;
            else h--;

        } 
        return s;
}
int main(){
    string s;
    getline(cin,s);
    reverseVowels(s);
    cout<<s<<endl;
    return 0;
}
