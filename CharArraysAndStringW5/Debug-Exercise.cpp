#include<iostream>
#include<string>
#include<vector>
using namespace std;
/* Q1.Debug the code
void reverseWords(string s)
{
    vector<string> tmp;
    string str = "";
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            tmp.push_back(str);
            str = "";
        }
        else
            str += s[i];
    }
    tmp.push_back(str);
 return str;
}


Ans:-
void reverseWords(string s)
{
    vector<string> tmp;
    string str = "";
    for (int i = 0; i < s.length(); i++) { // Strings doesn't have null characters as terminator by default
        if (s[i] == ' ') {
            tmp.push_back(str);
            str = "";
        }
        else
            str += s[i];
    }
    tmp.push_back(str);
    // No return statement as function is void
}


Q2.Debug the code. This code tries to find first maximum occurring character.
 char maxOccurring(char* str){
    int count[256] = {0};
    int max = INT_MAX;
    char answer;
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i]]++;
        if (max <= count[str[i]]) {
            max = count[str[i]];
            answer= str[i];
        }
    }
    return answer;
}

int main(){
    char str[] = "sample string";
    cout << maxOccurring(str);
}
Ans:-
#include <bits/stdc++.h>
using namespace std;
 
char maxOccurring(char* str)
{
    int count[256] = {0};
    int max = 0; // Should be initialized with 0 or INT_MIN
    char answer;
 
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i]]++;
        if (max < count[str[i]]) { // we need to find first element which has maximum occurence so '<'
            max = count[str[i]];
            answer = str[i];
        }
    }
    return answer;
}

int main()
{
    char str[] = "sample string";
    cout << maxOccurring(str);
}

Q3.Debug the code. It tries to remove duplicates from the given string.

#include <bits/stdc++.h>
using namespace std;

char *removeDuplicate(char str[], int n) {
  // str is character array and n is the lenght of the character array
	int index = 0;
	for (int i=0; i<n; i++) {
		int j;
		for (j=0; j<i; j++)
			if (str[i] == str[j])
				str[index++] = str[i];
		}
		
	return str;
}
Ans:-
#include <bits/stdc++.h>
using namespace std;

char *removeDuplicate(char str[], int n) {
  // str is character array and n is the lenght of the character array
	int index = 0;
	for (int i=0; i<n; i++) {
		int j;
		for (j=0; j<i; j++)
			if (str[i] == str[j])
				break;
                if(i == j) str[index++] = str[j];
	}

		
	return str;
}

Q4.Debug the code. It tries to check if given string a Palindrome or not.
string isPalindrome(string S)
{
		int N = S.length();
    for (int i = 0; i < (N/2)-1; i++) {
		    if (S[i] != S[N-i]) {
            return "No";
        }
    }
    return "Yes";
}
Ans:-
string isPalindrome(string S)
{
    int N = S.length();
    for (int i = 0; i < (N/2); i++) {  // Fix
	    if (S[i] != S[N-i-1]) { // Fix
            	return "No";
        }
    }
    return "Yes";
}

Q5.Debug the code.
#include <iostream>  
using namespace std;  
int main() {  
    char char_array[] = {'L','A','K','S','H','A','Y'};  
    int array_size = sizeof(char_array);  
    string j = "";  
    int i;  
    for(i = 0; i < array_size; i++) {    
        j = j + char_array[i];  
    }  
    cout << j <<endl;  
}

Ans:-#include <iostream>  
using namespace std;  
int main() {  
    char char_array[] = {'L','A','K','S','H','A','Y'};  
    int array_size = sizeof(char_array) /  sizeof(char);  
    string j = "";  
    int i;  
    for(i = 0; i < array_size; i++) {    
        j = j + char_array[i];  
    }  
    cout << j <<endl;  
}  

Q6.Debug the code. This code attempt to reverse all words occur in a sentence. All words are space separated.
void reverseString(char input[],int n,int start){
    for(int i=start,j=n-1+start;i<j;i++,j--){
        int temp = input[i];
        input[j] = input[i];
        input[i] = temp;
    }
}

void reverseEachWord(char input[]) {
    int start=0,count=1,i=0;
    while(input[i]!=0){
        i++;
        count++;
        if((input[i]==' ')){
            reverseString(input,count-1,start);
            start = i+1;
            count = 0;
        }
    }
}
Ans:-
void reverseString(char input[],int n,int start){
    for(int i=start,j=n-1+start;i<j;i++,j--){
	// Fixed swap
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
}

void reverseEachWord(char input[]) {
    int start=0,count=1,i=0;
    while(input[i]!=0){
        i++;
        count++;
        if((input[i]==' ' || input[i]=='\0')){ // Fix: Need to check if terminating or not
            reverseString(input,count-1,start);
            start = i+1;
            count = 0;
        }
        
    }
}
*/ 