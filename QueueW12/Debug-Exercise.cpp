#include<iostream>
#include<queue>
#include<stack>
using namespace std;
/*
// Q1.Debug the code. Queue using two stacks.

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
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int t= s2.top();
        // here use s2.pop()in sol.
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    int peek() {
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int t= s2.top();
				s2.pop();//(not use this line in sol.)
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    bool empty() {
        return s1.empty();
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

// Ans:-
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
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int val= s2.top();
        s2.pop();
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return val;
    }
    
    int peek() {
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int t= s2.top();
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    bool empty() {
        return s1.empty();
    }
};
*/

/*
// Q2.Debug the code. Return index of first non-repeating character.
int firstUniqChar(string s) {
        vector<int> c(26,0);
        queue<char> q;
       
        for(auto i:s){
            c[i]++;
            q.push(i);
        }
        
        int idx=0;
      
        while(q.empty()){
            auto elem = q.front();
            q.pop();
            
            if(c[elem] != 1){
               idx++;
            }
        }
        return idx;
    }
    //Ans:-
    int firstUniqChar(string s){
        vector<int> c(26,0);
        queue<char> q;
       
        for(auto i:s){
            c[i-'a']++;
            q.push(i);
        }
        int idx=0;
        while(!q.empty()){
            auto elem=q.front();
            q.pop();
            
            if(c[elem-'a']==1){
               return idx;
            }else{
                idx++;
            }
        }
        return -1;
    }
    Q3.Debug the code. Idea is to use stack involved in recursion to reverse the queue.

    void reverseQueue(queue<int> &q) {
    q.pop();
    reverseQueue(q);
    q.push(q.front());
}
Ans:-
void reverseQueue(queue<int> &q) {
    if(q.empty()){
        return;
    }
    int x = q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
    
}

Q4.Debug the code. Implement Queue using Linked List.

template<typename T>
class Queue {
    int capacity;
    int size;
    Node<T>* head;
    Node<T>* tail;
    public :
    Queue() {
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    void enqueue(T data) {
        Node<T>* temp = new Node<T>(data);
        if(isEmpty()){
            head = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        if(size==0){
            return true;
        }
        return false;
    }
    
    T dequeue() {
        T data = head->data;
        head = head->next;
        return data;
    }
    
    T front()  {
        return head->data;
    }
};

Ans:-
template<typename T>
class Queue {
    int capacity;
    int size;
    Node<T>* head;
    Node<T>* tail;
    public :
    Queue() {
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    void enqueue(T data) {
        Node<T>* temp = new Node<T>(data);
        if(isEmpty()){
            head = temp;
            tail = head;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        if(size==0){
            return true;
        }
        return false;
    }
    
    T dequeue() {
        if(isEmpty()){
            return 0;
        }
        T data = head->data;
        head = head->next;
        size--;
        return data;
    }
    
    T front()  {
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
};

// Q5.Debug the code. Stack using two queues.

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()){
            q1.pop();
            q2.push(q1.front());
        }

        q1.push(x);

        while(!q2.empty()){
            q2.pop();
            q1.push(q2.front());
        }

    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
Ans:-
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()){
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
        }

        q1.push(x);

        while(!q2.empty()){
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
        }

    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
*/
