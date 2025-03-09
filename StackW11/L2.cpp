/* //Q1.Insert at bottom
#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &s, int target){
    // base case
    if(s.empty()){
        s.push(target);
        return ;
    }
    int topElement = s.top();
    s.pop();
    insertAtBottom(s,target);
    s.push(topElement);
}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    if(s.empty()){
        cout<<"Stack is empty,canot insert at bottom"<<endl;
        return 0;
    }
    int target = s.top();
    s.pop();
    insertAtBottom(s,target);
    cout<<"Printing"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}*/

/*
//Q2.Reverse a stack
#include <iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &s, int target) {
        //base case
        if(s.empty()) {
            s.push(target);
            return;
        }

        int topElement = s.top();
        s.pop();
        //rec cal
        insertAtBottom(s, target);
        //BT
        s.push(topElement);
    }

void reverseStack(stack<int> &s) {
        //base case 
        if(s.empty()){
          return;
        }

        int target = s.top();
        s.pop();
        //reverse stack
        reverseStack(s);
        //insert at bottom target ko
        insertAtBottom(s, target);
}

int main() {
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  reverseStack(s);
  cout << "Printing" << endl;
  while(!s.empty()) {
          cout << s.top() << " ";
          s.pop();
  }
  cout << endl;
  return 0;
}
*/

/*
// Q3.Valid Parentheses
//https://leetcode.com/problems/valid-parentheses/description/
#include<iostream>
#include<stack>
using namespace std;
bool isValid(string s){
    stack<char>st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
    if(ch=='('||ch=='{'||ch=='['){
        st.push(ch);
    }
    else{
        if(!st.empty()){
            char topCh = st.top();
            if(ch == ')' && topCh == '(')
            st.pop();
            else if(ch == '}' && topCh == '{')
            st.pop();
            else if(ch == ']' && topCh == '[')
            st.pop();
            else return false;
        }
        else return false;
    }
}
    if(st.empty()) return true;
   return false;
}
int main(){
    string str;
    cout<<"Enter a valid Parentheses string "<<endl;
    getline(cin,str);
    bool ans = isValid(str);
    if(ans)
    cout<<"Is valid Parentheses string"<<endl;
    else{
        cout<<"Is not valid Parentheses string"<<endl;
    }
    return 0;
}
*/

/*
//Q4. Sort a stack
#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int>& s,int target){
    // bc
    if(s.empty()){
        s.push(target);
        return;
    }
    if(s.top()>= target){
        s.push(target);
        return;
    }
    int topElement = s.top();
    s.pop();
    insertSorted(s,target);
   s.push(topElement);
}

void sortStack(stack<int>& s){
    if(s.empty()){
        return;
    }
    int topElement = s.top();
    s.pop();

    sortStack(s);
    insertSorted(s,topElement);
}
int main() {
  stack<int> s;
  s.push(7);
  s.push(11);
  s.push(3);
  s.push(5);
  s.push(9);

  sortStack(s);

  cout << "Printing" << endl;
  while(!s.empty()) {
          cout << s.top() << " ";
          s.pop();
  }
  cout << endl;
  return 0;
}
*/

//HW: Expression contains redundant bracket or not
#include<iostream>
#include<stack>
using namespace std;
bool checkRedundancy(string s){
   stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                char top = st.top();
                st.pop();
                bool flag = true;
                while(!st.empty() && top !='('){
                    if(top=='+'||top=='-'||top=='*'||top=='/')
                     flag = false;
                     top = st.top();
                     st.pop();
                }
                if(flag) return true;
            }
            else st.push(s[i]);
        }
        return false;
    }

 int main(){
    string exp;
    cout<<"Enter the expression: "<<endl;
    getline(cin,exp);
    bool ans = checkRedundancy(exp);
    if(ans){
     cout<<"redundant bracket is present."<<endl;
    }
    else{
    cout<<"redundant bracket is not present."<<endl;
    }
    return 0; 
 }   

