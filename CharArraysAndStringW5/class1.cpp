/*Q What is the difference of char array and string.
Ans: In c++, both character arrays and string are used to store sequences of characters,but they have some key differences:
1.Syntax:Character arrays are declared using square brackets,while string are declared using double quotes or using the string class.For example  
C++
char arr[] ={'h','e','l','l','o'};
char str[] = "hello";                   
std:string s = "hello";
2.size:The size of a character array must be specified at the time of declaration and cannot be changed later,while the size of a string can be changed dynamically as needed.
3.Null termination:C-style character array need to be null termined which means that a null character (\0) needs to be added at the end of the array to indicate the end of the string.String obects automatically add a null character at the end,so there's no need to do this manually.
4.String manipulation:String have several built-in member functions that can be manipulate them,such as append(),substr(),find()etc.Character arrays do not have these built-in function,so string manipulation must be done manually using function like strcpy(),strcat(),strlen() etc.
5.Compatibility:Character array are compatible with C-style string and can be used with function that take C-style string as arguments,while string can be used with c++ string manipulation functions.

In general string are easier to use and more flexible,while character arrays are faster and more memory-efficient.However,the choice between the two depends on the specific requirements of the program and the preferences of the programmer.
*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    // basic of string and character
   char name[100];
   cout<< "Enter your Name " << endl;
   cin >> name;
   cout << "Aapka naam: " << name << "  hai " << endl;
   char ch[100];
   ch[0] = 'a';
   ch[1] = 'b';
   cin >> ch[2];
   cout << ch[0] << ch[1] << ch[2] << endl;
   char name[100];
   cin >> name;
   for(int i=0; i<7; i++) {
    cout << "index: " << i << " value: " << name[i] << endl;
        }
    int value = (int)name[6];
    cout << "value is : " << value << endl;
    char arr[100];
    //cin >> arr;
    cin.getline(arr, 50);
    cout << arr;
      //string create
    string str;
  //input
   cin >> str;
   getline(cin, str);
   cout << str;
   cout << "length: "<< str.length() << endl;
   cout << "isEmpty: " << str.empty() << endl;
   str.push_back('A');
   cout << str << endl;
   str.pop_back();
   cout << str << endl;
   cout << str.substr(1, 3) << endl;
   cout << str << endl;
   string a = "Love";
   string b = "love";
   if(a.compare(b) == 0) {
          cout << " a and b are exactly same strings" << endl;
  }
  else {
  cout << "a and b are not same" << endl;
}
string x = "bbbb";
string y = "bbbba";
cout << x.compare(y) << endl;
string sentence = "hello Jee kaise ho saare";
string target = "Everyone";
cout << sentence.find(target) << endl;
if(sentence.find(target) == string::npos) {
          cout << "Not Found" << endl;
  }
string str = "This is my First Message";
string word = "Babbar";
str.replace(11, 5 , "Second");
cout << str << endl;
string str = "ABCDEFGHIJKLMNOPQRST";
str.erase(10,10);
cout << str;
}
/*Q1.find the length of given string
int findLen(string str){
    int len = 0;
    for(int i=0;str[i]!='\0';i++){
        len++;
    }
    return len;
}
int main(){
     string str;
     getline(cin,str);
     int length = findLen(str);
     cout<<"Length of string is: "<<length<<endl;
    return 0;
}
*/

/*Q2. Reverse a given string
void reverseStr(string &str){
    int s = 0;
    int e = str.length()-1;
    while(s<=e){
        swap(str[s],str[e]);
        s++;
        e--;
    }
}
int main(){
     string str;
     getline(cin,str);
     reverseStr(str);
     cout<<"Reverse of string is: "<<endl;
     for(int i=0;i<str.length();i++){
        cout<<str[i];
     }
    return 0;
}
*/
/*Q3.Replace all spaces with @
void replaceSpace(string &str){
    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            str[i]='@';
        }
    }
}
int main(){
     string str;
     getline(cin,str);
     replaceSpace(str);
     for(int i=0;i<str.length();i++){
        cout<<str[i];
     }
    return 0;
}
*/
/*Q4.check given string is Palindrome or not;
bool checkPalindrome(string str){
    int start = 0;
    int end = str.length()-1;
    while(start<=end){
        if(str[start]!=str[end]) return false;
        else start++,end--;
    }
    return true;
}
int main(){
     string str;
     getline(cin,str);
     bool isTrue = checkPalindrome(str);
     if(isTrue)
     cout<<"Given string is Palindrome";
     else{
       cout<<"Given string is not Palindrome"; 
     }
    return 0;
}
*/

/*Q5.convert lowercase string to uppercase
void convertIntoUpperCase(string &str){
   for(int i=0;i<str.length();i++){
    str[i] = str[i]-'a'+'A';
   } 
}
int main(){
    string str="hellowji";
    convertIntoUpperCase(str);
 for(int i=0;i<str.length();i++){
        cout<<str[i];
     }
    return 0;
}
*/
/* Q6.Comparing 2 string 
bool compareString(string a, string b) {
if(a.length() != b.length())
return false;
for(int i=0; i<a.length(); i++) {
if(a[i] != b[i]) {
  return false;
}
    }
  return true;
}
int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    bool isEqual = compareString(str1,str2);
    if(isEqual){
        cout<<"Both string are same"<<endl;
    }
    else{
        cout<<"Both string are different."<<endl;
    }
}
*/