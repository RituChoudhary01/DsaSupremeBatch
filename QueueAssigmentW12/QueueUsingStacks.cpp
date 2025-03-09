// Implament of queue using stacks
// https://leetcode.com/problems/implement-queue-using-stacks/description/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int pop = -1;
        if(!s2.empty()){
            pop = s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            pop = s2.top();
        }
        s2.pop();
        return pop;
    }

    
    int peek() {
        int front = -1;
        if(!s2.empty()){
            front = s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            front = s2.top();
        }
        return front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
int main(){
    MyQueue q;
    q.push(34);
    q.push(12);
    cout<<q.peek()<<endl;
    q.pop();
     cout<<q.peek()<<endl;
    q.push(3);
    q.push(341);
    q.pop();
    cout<<q.peek()<<endl;
    cout<<q.empty()<<endl;
}