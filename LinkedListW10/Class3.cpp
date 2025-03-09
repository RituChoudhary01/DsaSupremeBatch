//Q1.Find the middle of linked list.
//Q2.Reverse a linked list in K group.
// Q3.Check whether the linked list is circular or not.
// Q4.Dected and delete a loop in linked list.

#include<iostream>
using namespace std;
 class Node{
        public:
        int data;
        Node* next;

        Node(int data) {
                this -> data = data;
                this -> next = NULL;
        }
};
//print the linked list
void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
// find length of linked list.
int findLen(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}
//Q1.Navie Approach
   Node* findMidNavie(Node* head){
    if(head == NULL){
                cout << "LL is empty" << endl;
                return head;
        }
        if(head -> next == NULL) {
            //only 1 node in LL
           return head;
        }
    // LL have > 1 node  
    int len = findLen(head);
    int midNodeIndex = len/2;
    Node* temp = head;
    while(midNodeIndex && temp){
        temp = temp->next;
        midNodeIndex--;
    }
    return temp;
   }
//Slow and Fast pointer Approach
   Node* getMiddle(Node* &head){
        if(head == NULL){
            cout << "LL is empty" << endl;
            return head;
        }
        if(head -> next == NULL) {
                //only 1 node in LL
                return head;
        }
        // LL have > 1 node
        Node* slow = head;
        Node* fast = head;

        while(slow != NULL && fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }
        }
        return slow;
    }
 //Reverse a LL in K group
 Node* reverseK(Node*& head, int k) {
    if (head == NULL) {
        cout << "LL is empty." << endl;
        return NULL;
    }
    int len = findLen(head);
    if (k > len || k <= 1) return head; // No need to reverse if k > length or k <= 1

    // Reverse the first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* nxt = NULL; // Initialize nxt properly
    int count = 0;

    // Reverse the first k nodes
    while (curr != NULL && count < k) { // Ensure we don't access NULL pointer
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
   // Recursive call for the next part of the list
    if (nxt != NULL) {
        head->next = reverseK(nxt, k);
         }
    // Return the new head of the reversed list
    return prev;
}

// Check cycle is present or not
bool checkForLoop(Node* &head) {
    if(head == NULL) {
        cout << "LL is empty "<< endl;
        return false;
    }
        Node* slow = head;
        Node* fast = head;
         while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL) {
                fast = fast -> next;
                slow = slow -> next;
                }
            if(slow == fast) {
                //loop present
                return true;
            }
        }
        //fast NULL hogya
        return false;
}
// find starting point of loop
Node* startingPointLoop(Node* &head) {
    if(head == NULL) {
        cout << "LL is empty "<< endl;
        return NULL;
    }
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

           if (slow == fast) { // Loop detected
            slow = head; // Reset slow to head

            // Find the starting point of the loop
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
           return slow; // Starting point of the loop
        }
    }
    return NULL;
}
// remove loop from LL
Node* removeLoop(Node* &head) {
        if(head == NULL) {
            cout << "LL is empty "<< endl;
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
        }
        if(fast==NULL || fast->next==NULL) return head;
           slow = head;
            while (fast != slow){
                fast = fast->next;
                slow = slow->next;
            }
            while(fast!= slow->next){
                slow = slow->next;
            }

        slow->next = NULL;
        return head;
     }
int main(){
  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(40);
  Node* fifth = new Node(50);
  Node* sixth = new Node(60);
  Node* seventh = new Node(70);
  Node* eighth = new Node(80);
  Node* ninth = new Node(90);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  sixth -> next = seventh;
  seventh -> next = eighth;
  eighth -> next = ninth;
  ninth -> next = fourth;

//   printLL(head);
//   cout<<endl;
//   Node* rev = reverseK(head, 1);
//   printLL(rev);
//   cout << "Middle Node is: " << getMiddle(head) -> data << endl;

  cout << "Loop is Present or not " << checkForLoop(head) << endl;
  //if return NULL then show segment fault due to access of NULL->data
  cout << "Starting Point of Loop is: " << startingPointLoop(head) -> data << endl;
  removeLoop(head);
  printLL(head);
  cout<<endl;
  cout << "Loop is Present or not " << checkForLoop(head) << endl;
  return 0;
}
