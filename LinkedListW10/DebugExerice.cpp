/*
Q1.Debug the code. Expected Output for the code is 1 2 3.
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* head;

void insert(int x) {
  Node* temp = new Node;
  temp->data = x;
  temp->next = head;
  head = temp;
}

void print() {
  Node* temp = head;
  cout << "List: ";
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  head = NULL;
  insert(1);
  insert(2);
  insert(3);
  print();
  return 0;
}
// update the insert function
Ans:- void insert(int x) {
  Node* temp = new Node;
  temp->data = x;
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
  } else {
    Node* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = temp;
  }
}

Q2.Debug the code.
ListNode* middleNode(ListNode* head) {
        ListNode* last = head;
        ListNode* first = head;

        while (first->next != NULL && last != NULL) {
            last = last->next;
            first = first->next->next;
        }
    
        return last;
    }
 Ans:-
 ListNode* middleNode(ListNode* head) {
        ListNode* last = head;
        ListNode* first = head;

        while (first != NULL && first->next != NULL) { //Fix
            last = last->next;
            first = first->next->next;
        }
       return last;
    }

 Q3.Debug the code.
   class Solution {
     public:
    bool hasCycle(ListNode *head){
        if(head == NULL)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(slow != NULL && fast ->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow->next)
                return true;
        }
        
        return false;
    }
}; 
Ans:-
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow)
                return true;
        }
        return false;
    }
};

Q4.Debug the code. Task is to rotate the linked list counter-clockwise by k nodes.

void rotate(Node* head, int k){
    if (k == 0)
        return;
    Node* current = head;
    int count = 1;
    while (count < k && current != NULL){
        current = current->next;
        count++;
    }
    Node* kthNode = current;
    while (current->next != NULL)
        current = current->next;
    current->next = head;
    head = kthNode->next;
    kthNode->next = NULL;
}
Ans:-
void rotate(Node* head, int k)
{
    if (k == 0)
        return;
    Node* current = head;
  
    int count = 1;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }
  
    if (current == NULL)
        return;
  
    Node* kthNode = current;
    while (current->next != NULL)
        current = current->next;
  
    current->next = head;
    head = kthNode->next;
    kthNode->next = NULL;
}

Q5.Debug the code.
ListNode* deleteMiddle(ListNode* head) {
        if (head -> next == NULL && head == NULL)
            return NULL;
        
        ListNode *slow = head, *fast = head -> next -> next;
        
        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = fast;
        return head;
    }

Ans:-
ListNode* deleteMiddle(ListNode* head) {
        if (head -> next == NULL && head == NULL)
            return NULL;
        
        ListNode *slow = head, *fast = head -> next -> next;
        
        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
*/