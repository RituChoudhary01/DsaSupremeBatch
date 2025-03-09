//insertion and deletion in doubly linked list.
#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node* prev;
  Node(){
    this->data = 0;
    this->prev = NULL;
    this->next = NULL;
  }
  Node(int data){
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }
  ~Node(){
    cout<<"Node with value: "<<this->data<<" deleted"<<endl;
  }
};
// print doubly linked list
void print(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
}

// length of doubly linked list
int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
// insert at head of doubly linked list
void insertAtHead(Node*& head,Node*& tail,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
    head = newNode;
    tail = newNode;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertAtTail(Node*& head,Node*& tail,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
     head = newNode;
     tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void insertAtPosition(Node*& head,Node*& tail,int data,int position){
    Node* newNode = new Node(data);
    if(head == NULL){
       head = newNode;
       tail = newNode;
    }
    else{
        if(position == 1){
            insertAtHead(head,tail,data);
            return;
        }
        int len = getLength(head);
        if(position > len){
            insertAtTail(head,tail,data);
            return;
        }
        // insert at middle
        int i = 1;
        Node* prevNode = head;
        while(i<position-1){
            prevNode = prevNode->next;
            i++;
        }
        Node* curr = prevNode -> next;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        newNode->next = curr;
        curr->prev = newNode;
    }
}
void deleteFromPos(Node*& head,Node*& tail,int position){
  if(head == NULL){
    cout<<"Linked list is empty";
    return ;
  }
  if(head->next == NULL){
    Node* temp = head;
    head = NULL;
    tail = NULL;
    delete temp;
    return;
  }
  int len = getLength(head);
  if(position>len){
    cout<<"Please enter a valid position "<<endl;
  }
  if(position == 1){
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
    return ;
  }
  if(position == len){
    Node* temp = tail;
    tail = tail->prev;
    temp->prev = NULL;
    tail->next = NULL;
    delete temp;
    return;
  }
//   delete from middle of linked list
int i=1;
Node* left = head;
while(i<position-1){
    left = left->next;
    i++;
}
Node* curr = left->next;
Node* right = curr->next;
left->next = right;
right->prev = left;
curr->next = NULL;
curr->prev = NULL;
delete curr;
}

int main(){

    //     Node* first = new Node(10);
    //     Node* second = new Node(20);
    //     Node* third = new Node(30);
    //     Node* head = first;
    //     Node* tail = third;

    //     first -> next = second;
    //     second -> prev = first;

    //     second ->next = third;
    //     third->prev = second;

    //     print(first);
    //     cout << endl;
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail, 101);
    insertAtHead(head,tail, 201);
    insertAtTail(head,tail, 501);
    insertAtTail(head,tail, 601);
    insertAtPosition(head,tail, 40, 3);
    insertAtPosition(head,tail, 50, 3);
    cout<<endl;
    print(head);
    cout<<endl;
    deleteFromPos(head, tail, 1);
    deleteFromPos(head, tail, 5);
    cout<<endl;
    print(head);
    // it show segment fault.
    // deleteFromPos(head, tail, 10);
    // print(head);
}