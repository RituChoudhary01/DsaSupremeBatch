// insert deletion of singly linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

     ~Node() {
        cout << "Node with value: " << this->data << " deleted" << endl;
        }
};
// Function to print linked list
void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Find the length of linked list
int findLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

// Insert a node at the head of the linked list
void insertAtHead(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);
    // Check for empty linked list
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } 
    else{
        newNode->next = head;
        head = newNode;
    }
}
// Insert a node at the tail of the linked list
void insertAtTail(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    } 
    else {
        tail->next = newNode;
        tail = newNode;
    }
}
// Insert a node at any position in the linked list
void insertAtAnyPosition(Node*& head, Node*& tail, int position, int data) {
    if (head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    if (position == 0) {
        insertAtHead(head, tail, data);
        return;
    }
    int len = findLength(head);
    if (position >= len) {
        insertAtTail(head, tail, data);
        return;
    }
    // Find prev and curr
    int i = 1;
    Node* prev = head;
    while (i < position) {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    Node* newNode = new Node(data);
    newNode->next = curr;
    prev->next = newNode;
}
// delete a node
void deleteNode(Node*& head, Node*& tail, int position){
    if(head == NULL){
        cout<<"Cannot delete,LL is empty";
        return;
    }
    // deleting first node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int len = findLength(head);
    // deleting last node
    if(position == len){
        int i=1;
        Node* prev = head;
        while(i<position-1){
            prev = prev->next;
            i++;
        }
        prev->next = NULL;
        Node* temp  = tail;
        tail = prev;
        delete temp;
        return ;
    }
    // delete middle node
    int i=1;
    Node* prev = head;
    while(i<position-1){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
// lecture 2 question reverse a linked list
Node* reverse(Node*& prev, Node*& curr){
        //base case
        if(curr == NULL){
            return prev;
        }
        //1 case solve then recursion will take care
        Node* forward = curr -> next;
        curr -> next = prev;
        reverse(curr, forward);
}

Node* reverseusingLoop(Node* head ){
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL ) {
                Node* temp = curr ->next;
                curr ->next = prev;
                prev = curr;
                curr = temp;
        }
        return prev;
}
Node* reverseusingRecursion(Node* prev, Node* curr) {
        //base case
        if(curr == NULL) 
        return prev;
        Node* temp = curr ->next;
        curr ->next = prev;
        prev = curr;
        curr = temp;
        //recursion sambhal lega
        return reverseusingRecursion(prev, curr);
}

int main() {
//  Node* first = new Node(12);
//  Node* second = new Node(13);
//  Node* third = new Node(14);
//  Node* fourth = new Node(15);
//  Node* fifth = new Node(16);
//  first->next = second;
//  second->next = third;
//  third->next = fourth;
//  fourth->next = fifth;
//  printLL(first);
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    printLL(head);

    insertAtTail(head, tail, 65);
    insertAtTail(head, tail, 75);
    insertAtTail(head, tail, 85);
    printLL(head);

    insertAtTail(head, tail, 95);
    insertAtAnyPosition(head, tail, 3, 33);
    insertAtAnyPosition(head, tail, 6, 66);
    insertAtAnyPosition(head, tail, 8, 88);
    insertAtAnyPosition(head, tail, 1, 111);
    printLL(head);

    deleteNode(head,tail,5);
    printLL(head);
    deleteNode(head,tail,1);
    printLL(head);
    deleteNode(head,tail,9);
    printLL(head);
     
    Node* prev = NULL;
    Node* curr = head;
    cout << "printing reverse list" << endl;
    // head = reverse(prev, curr);
    // head = reverseusingLoop(prev, curr);
    head = reverseusingRecursion(prev, curr);
    cout << endl;
    printLL(head);
   return 0;
}
 
