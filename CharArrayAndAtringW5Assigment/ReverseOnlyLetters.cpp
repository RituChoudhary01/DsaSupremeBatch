// Reverse Only Letters
// https://leetcode.com/problems/reverse-only-letters/description/

#include<iostream>
using namespace std;
    string reverseOnlyLetters(string s) {
        int l=0,h=s.length()-1;
        while(l<=h){
            if(!isalpha(s[l])) l++;
            else if(!isalpha(s[h])) h--;
            else if(isalpha(s[l]) && isalpha(s[h])){ 
            swap(s[l],s[h]);
            l++,h--;
            }
        }
        return s;
    }
    int main(){
        string s;
        cout<<"Enter the string: ";
        getline(cin,s);
        cout<<reverseOnlyLetters(s);
        return 0;
    }