/*
Q1.Debug the code. Next Greater to the Right.
void nextGreaterElementRight(vector<int> input, int n){
		vector<int> right(n,-1);
		stack<int> s;
		for(int i=0; i<n; i++){
		    if(s.empty()){
				s.push(i);
			}
			while(!s.empty() && input[s.top()] < input[i]){
				right[s.top()] = input[i];
				s.pop();
			}
		}
}
Ans:-
void nextGreaterElementRight(vector<int> input, int n){
  vector<int> right(n,-1);
  stack<int> s;
  for(int i=0; i<n; i++){
	if(s.empty()){
		s.push(i);
		continue;
	}
	while(!s.empty() && input[s.top()] < input[i]){
	right[s.top()] = input[i];
	 s.pop();
	}
	s.push(i);
   }
}

Q2. Debug the code. Next Greater to the Left.
void nextGreaterElementLeft(vector<int> input, int n){
		vector<int> left(n,-1);
		stack<int> s;
		for(int i=0; i<n; i++){
				while(!s.empty() && input[s.top()] <= input[i]){
						s.pop();
				}
				left[i] = s.top();
				s.push(i);
		}
}
Ans:-
void nextGreaterElementLeft(vector<int> input, int n) {
    vector<int> left(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && input[s.top()] <= input[i]) {
            s.pop();
        }
        if (!s.empty()) {
            left[i] = s.top();
        }
        s.push(i);
    }

Q3.Debug the code. Reverse a given input stack using one empty extra stack.
void reverseStack(stack<int> &input, stack<int> &extra) {
    int x = input.top();
    input.pop();
    reverseStack(input, extra);
    for(int i=0; input.empty(); i++){
        extra.push(input.top());
        input.pop();
    }
    input.push(x);
    for(int i=0; extra.empty(); i++){
        input.push(extra.top());
        extra.pop();
    }
}
Ans:-
void reverseStack(stack<int> &input, stack<int> &extra) {
	if(input.empty()){
        return;
    }
    int x = input.top();
    input.pop();
    reverseStack(input,extra);
    for(int i=0; input.empty()==false; i++){
        extra.push(input.top());
        input.pop();
    }
    input.push(x);
    for(int i=0; extra.empty()==false; i++){
        input.push(extra.top());
        extra.pop();
    }
    return;
}

Q4.Debug the code. Implement Stack using Linked List.
template <typename T>
class Stack {
    Node<T> *head;
    int size;

    public :    
    Stack() {
        head = NULL;
        size = 0;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    void push(T element) {
        Node<T>* temp = new Node<T>(element);
        temp->next = head;
        head = temp;
        size++;
        return;
    }
    
    T pop() {
        T data = head->data;
        head = head->next;
        size--;
        return data;   
    }
    
    T top() {
        return head->data;
    }    
};
Ans:-
template <typename T>
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack
    
    public :
    
    Stack() {
        head = NULL;
        size = 0;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    void push(T element) {
        Node<T>* temp = new Node<T>(element);
        temp->next = head;
        head = temp;
        size++;
        return;
    }
    
    T pop() {
        if(size==0){
            return 0;
        }
        T data = head->data;
        head = head->next;
        size--;
        return data;
        
    }
    
    T top() {
        // Return 0 if stack is empty. Don't display any other message
        if(size==0){
            return 0;
        }
        return head->data;
    }
    
  
    
};

Q5.Debug the code.
void deleteMiddle(stack<int>& s, int k) {
    stack<int> aux;
    int count = 0;

    while (!s.empty()) {
        int num = s.top();
        s.pop();
        aux.push(num);
        count++;
        if (count == k) {
            s.pop();
        }
    }

    while (!aux.empty()) {
        int num = aux.top();
        aux.pop();
        s.push(num);
    }
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    // delete middle element
    int k = (s.size() + 1) / 2;
    deleteMiddle(s, k);

    // print remaining elements
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
Ans:-
void deleteMiddle(stack<int>& s, int k) {
    stack<int> aux;
    int count = 0;

    while (!s.empty()) {
        int num = s.top();
        s.pop();
        aux.push(num);
        count++;
        if (count == k) {
            s.pop();
            break;
        }
    }

    while (!aux.empty()) {
        int num = aux.top();
        aux.pop();
        s.push(num);
    }
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    // delete middle element
    int k = (s.size() + 1) / 2;
    deleteMiddle(s, k);

    // print remaining elements
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
*/