/*Stack flow LIFO order LAST IN FIRST OUT
Basic operation of stack
declaration of stack
stack<datatype>nameofstack
stack<int>st;
push element in stack
st.push(5);
st.push(7);
pop element from stack
st.pop();
to acces top element from stack
st.top();
to check stack is empty or not
st.empty();
to check size of stack or number of element present of stack
st.size();

STL of stack
#include <iostream>
#include<stack>
using namespace std;

int main() {
        //creation
        stack<int> st;

        //insertion
        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);

        //remove
        st.pop();

        //check element on top
        cout << "Element on top is: " << st.top() << endl; 

        //size
        cout << "size of stack is: " << st.size() << endl;

        if(st.empty()) 
                cout << "stack is empty" << endl;
        else
                cout << "stack is not empty" << endl; 
        return 0;               

}
*/
/*
Q1. Implamentation of stack

#include<iostream>
using namespace std;
class Stack{
    private:
    int *arr;
    int top;
    int size;
    public:
    Stack(int size){
    arr = new int[size];
    this->size = size;
    top = -1;
    }
    // functions
    void push(int data){
        if(size-top>1){
            top++;
            arr[top] = data;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(top == -1){
            cout<<"Stack underflow, cant dalete element"<<endl;
        }
        else{
            top--;
        }
    }
    int getTop(){
        if(top ==  -1){
            cout<<"There is not element in stack"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }
    // return number of valid elements present in stack
    int getSize(){
        return top+1;
    }
    bool isEmpty(){
        if(top==-1) return true;
        else return false;
    }
};
int main(){
    // creation 
    Stack s(5);
    // insertion 
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // s.push(60);
//  while(!s.isEmpty()) {
//    cout << s.getTop() << " ";
//    s.pop();
//   }
//   cout << endl;
    cout << "Size of stack " << s.getSize() << endl;
    s.pop();
    return 0;
}
*/
/*
Q2.Reverse a string
#include <iostream>
#include<stack>
using namespace std;

int main() {
  string str = "Reverse";

  stack<char> s;
  for(int i=0; i<str.length(); i++) {
    s.push(str[i]);
  }
while(!s.empty()) {
     cout << s.top();
    s.pop();
  }
  cout << endl;
 return 0;
}
*/

/*
Q3. Implement 2 stack using 1 array
#include<iostream>
using namespace std;
class Stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;
    Stack(int size){
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }
    // functions
    void push1(int data){
      if(top2-top1 == 1){
        cout<<"Overflow in stack 1"<<endl;
      }
      else{
        top1++;
        arr[top1] = data;
      }
    }
    void pop1(){
      if(top1==-1){
        cout<<"Underflow in stack 1"<<endl;
      }
      else{
        arr[top1]=0;
        top1--;
      }
    }
    void push2(int data){
    if(top2 - top1 == 1){
        cout<<"Overflow in stack 2"<<endl;
    }
    else{
        top2--;
        arr[top2]= data;
    }
    }
    void pop2(){
    if(top2 == size){
        cout<<"Underflow in stack 2"<<endl;
    }
    else{
        arr[top2]=0;
        top2++;
    }
    }
    void print(){
        cout<<"top1: "<<top1<<endl;
        cout<<"top2: "<<top2<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Stack s(10);
        s.push1(10);
        s.print();
        s.push1(20);
        s.print(); 
        s.push1(30);
        s.print();
        s.push1(40);
        s.print();
        s.push1(50);
        s.print();

        s.push2(100);
        s.print();
        s.push2(110);
        s.print();
        s.push2(120);
        s.print();
         s.push2(130);
        s.print();
        s.push2(140);
        s.print();
        
        s.pop1();
        s.print();
        s.pop1();
        s.print();

        s.pop1();
        s.print();

        s.pop1();
        s.print();

        s.pop1();
        s.print();

        s.push2(1000);
        s.print();

        s.pop1();
        s.print();
  return 0;
} 
*/
/*
Q4.print middle element of stack*/
#include <iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int> &s, int &totalSize) {
        if(s.size() == 0){
                cout << "There is no element in stack" << endl;
                return ;
        }
        //base case
        if(s.size() == totalSize/2 + 1){
                cout << "Middle element is: " << s.top() << endl;
                return;
        }
        int temp = s.top();
        s.pop();

        //recursive call
        printMiddle(s, totalSize);
        //backtrack;
        s.push(temp);

}

int main() {
        stack<int> s;

        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        s.push(60);
        s.push(70);

        int totalSize = s.size();
        printMiddle(s,totalSize);
        return 0;
}