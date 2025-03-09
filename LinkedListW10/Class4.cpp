// Q1.Check a linked list is palindrome
//Q2.remove duplicate form the linked list.
//Q3.Sort 0/1/2 in a linked list.
//Q4.Add two linked list.


#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node(int data){
   this->data = data;
   this->next = NULL;
  }
};
// print LL
void print(Node* head) {
        Node* temp = head;
        while(temp != NULL) {
         cout << temp -> data << " ";
         temp = temp -> next;
        }
        cout << endl;
}
// reverse LL
Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = curr -> next;
        while(curr != NULL) {
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
        }
        return prev;
}
/* Q1.Check a linked list is palindrom
bool checkPalindrome(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty" << endl;
                return true;
        }
        if(head -> next == NULL) {
                //only 1 node
                return true;
        }
        // >1 node in LL
        //StepA: find the middle node;
        Node* slow = head;
        Node* fast = head -> next;
        while(fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }
        }
        //slow pointer is pointing to the middle node

        //Step B: reverse LL after middle/slow node
        Node* reverseLLKaHead = reverse(slow -> next);
        //join the reversed LL into the left part
        slow -> next = reverseLLKaHead;

        //Step C: start comparison
        Node* temp1 = head;
        Node* temp2 = reverseLLKaHead;
        while(temp2 != NULL){
                if(temp1 -> data != temp2 -> data) {
                        // not a palindome
                        return false;
                }
                else {
                        //if data is equal, then aage badh jao
                        temp1 = temp1 -> next;
                        temp2 = temp2 -> next;
                }
        }
        return true;
}
int main() {
  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(20);
  Node* fourth = new Node(30);
  Node* fifth = new Node(20);
  Node* sixth = new Node(10);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  bool isPalindrome = checkPalindrome(head);
  if(isPalindrome) {
          cout << "LL is a valid palindrome" << endl;
  }
  else {
          cout << "LL is not a palindrome" << endl;
  }
  return 0;
  }
*/
/*
// Q2.remove duplicate form the linked list.

void removeDuplicates(Node* &head) {
        if( head == NULL) {
                cout << "LL is empty" << endl;
                return;
        }
        if(head -> next == NULL) {
                cout << "Single Node in LL" << endl;
                return ;
        }
        // >1 node in LL
        Node* curr = head;
        while(curr != NULL) {
            if((curr -> next != NULL) && (curr -> data == curr -> next -> data) ){
                        //equal
                        Node* temp = curr -> next;
                        curr -> next = curr -> next -> next;
                        //delete node
                        temp -> next = NULL;
                        delete temp;
                }
                else {
                        // not equal
                        curr = curr -> next;
                }
        }
}

int main() {
  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(2);
  Node* fourth = new Node(3);
  Node* fifth = new Node(4);
  Node* sixth = new Node(4);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  cout << "input LL: ";
  print(head);
  removeDuplicates(head);
  cout << "output LL: " ;
  print(head);
  return 0;
}
*/ 
/*
//Q3.Sort 0/1/2 in a linked list.
// Approach 1 Native Approach
    void sortZeroOneTwo(Node*& head) {
        //step1: find count of zeroes, ones and twos
        int zero = 0;
        int one = 0;
        int two = 0;

        Node* temp = head;
        while(temp != NULL) {
                if(temp -> data == 0)
                        zero++;
                else if(temp -> data == 1)
                        one++;
                else if(temp -> data == 2)
                        two++;
                temp = temp -> next;
        }
        //step2: fill 0, 1 and 2s in the original ll
        temp = head;
                // fill zeroes
                while(zero--) {
                        temp -> data = 0;
                        temp = temp -> next;
                }
                //fill ones
                while(one--) {
                        temp -> data = 1;
                        temp = temp -> next;
                }
                //fill 2s
                while(two--) {
                        temp -> data = 2;
                        temp = temp -> next;
                }
    }
    //Approach 2 by chinging links 
    Node* sort2(Node* &head){
        if(head == NULL) {
                cout << "LL is empty " << endl;
                return NULL;
        }
        if(head -> next == NULL) {
                //sngle node in LL
                return head;
        }
        //create dummy nodes
        Node* zeroHead = new Node(-101);
        Node* zeroTail = zeroHead; 

        Node* oneHead = new Node(-101);
        Node* oneTail = oneHead; 

        Node* twoHead = new Node(-101);
        Node* twoTail = twoHead; 

        //traverse the original LL
        Node* curr = head;
        while(curr != NULL) {

                if(curr -> data == 0) {
                        //take out the zero wali node
                        Node* temp = curr;
                        curr = curr -> next;
                        temp -> next = NULL;

                        //append the zero node in zeroHead LL
                        zeroTail -> next = temp;
                        zeroTail = temp;

                }
                else if(curr -> data == 1) {
                        //take out the one wali node
                        Node* temp = curr;
                        curr = curr -> next;
                        temp -> next = NULL;

                        //append the zero node in zeroHead LL
                        oneTail -> next = temp;
                        oneTail = temp;

                }
                else if(curr -> data == 2) {
                        //take out the zero wali node
                        Node* temp = curr;
                        curr = curr -> next;
                        temp -> next = NULL;

                        //append the zero node in zeroHead LL
                        twoTail -> next = temp;
                        twoTail = temp;

                }
        }
       //modify one wali list
        Node* temp = oneHead;
        oneHead = oneHead -> next;
        temp -> next = NULL;
        delete temp;

        //modify two wali list
        temp = twoHead;
        twoHead = twoHead -> next;
        temp -> next = NULL;
        delete temp;

        //join list
        if(oneHead != NULL) { 
                zeroTail -> next = oneHead;
                if(twoHead != NULL)
                        oneTail -> next = twoHead;
        }
        else{
                //one wali list is empty
                if(twoHead != NULL)
                    zeroTail -> next = twoHead;
        }

        //remove zerohead dummy Node
        temp = zeroHead;
        zeroHead = zeroHead -> next;
        temp -> next = NULL;
        delete temp;
        
        //return head of the modified linked list
        return zeroHead;

}
 int main() {
  Node* head = new Node(0);
  Node* second = new Node(0);
  Node* third = new Node(2);
  Node* fourth = new Node(2);
  Node* fifth = new Node(0);
  Node* sixth = new Node(0);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;

  cout << "input LL: ";
  print(head);

  sortZeroOneTwo(head);
  print(head);
  
  cout << "printing the sorted list " << endl;
  Node* temp = NULL;
  head = sort2(head);
  //cout << "Came out of sort function" << endl;
  print(head);

  return 0;
}
*/

//Q4.Add two linked list.
Node* addLL(Node* &head1, Node* &head2) {
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1; 
        //step1 : reverse both linked list
        head1 = reverse(head1);
        head2 = reverse(head2);

        //step2: add both linked list
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        int carry = 0;

        while(head1 != NULL && head2 != NULL) {
                //calculate sum
                int sum = carry + head1 -> data + head2 -> data;
                //find digit to create node for
                int digit = sum % 10;
                //calculate carry
                carry = sum / 10;

                //create a new Node for the digit
                Node* newNode = new Node(digit);
                //attach the newNode into the answer wali linked list
                if(ansHead == NULL) {
                        //first node insert krre ho
                        ansHead = newNode;
                        ansTail = newNode;
                }
                else {
                        ansTail -> next = newNode;
                        ansTail = newNode;
                }
                head1 = head1 -> next;
                head2 = head2 -> next;
        }

        //jab head1 list ki length head2 list se jada hogi
        while(head1 != NULL) {
                int sum = carry + head1 -> data;
                int digit = sum % 10;
                carry = sum / 10;
                Node* newNode = new Node(digit);
                ansTail -> next = newNode;
                ansTail = newNode;
                head1 = head1 -> next;
        }

        //jab head2 list ki length head1 list se jada hogi
        while(head2 != NULL) {
                int sum = carry + head2 -> data;
                int digit = sum % 10;
                carry = sum / 10;
                Node* newNode = new Node(digit);
                ansTail -> next = newNode;
                ansTail = newNode;
                head2 = head2 -> next;
        }

        //handle carry ko alag se
        while(carry != 0) {
                int sum = carry;
                int digit = sum % 10;
                carry = sum / 10;
                Node* newNode = new Node(digit);
                ansTail -> next = newNode;
                ansTail = newNode;
        }
    //step3: reverse the ans linked list
        ansHead = reverse(ansHead);
        return ansHead;
}
int main() {
        Node* head1 = new Node(4);
        Node* second1 = new Node(9);
        head1 -> next = second1;

        Node* head2 = new Node(7);
        Node* second2 = new Node(9);
        Node* third2 = new Node(6);
        Node* fourth2 = new Node(9);
        // Node* third2 = new Node(4);
        head2 -> next = second2;
        second2->next = third2;
        third2->next = fourth2;
       // second2 -> next = third2;
       Node* ans = addLL(head1, head2);
       print(ans);
       return 0;
}
