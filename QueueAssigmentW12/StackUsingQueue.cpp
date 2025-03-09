//Implament stack using queues
//https://leetcode.com/problems/implement-stack-using-queues/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class MyStack{
    public:
    queue<int>q;
    MyStack(){}

    void push(int x){
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
    int pop(){
        int top = q.front();
        q.pop();
        return top;
    }
    int top(){
        return q.front();
    }
    bool empty(){
        return q.empty();
    }
};
int main(){
    MyStack s;
    s.push(5);
    cout<<s.top()<<endl;;
     s.push(51);
    cout<<s.top()<<endl;;
    s.pop();
    cout<<s.top()<<endl;;
    s.push(25);
    s.push(465);
    cout<<s.top()<<endl;;
    cout<<s.empty()<<endl;
    return 0;
}