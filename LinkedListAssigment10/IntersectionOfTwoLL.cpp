//intersection of linked list leetcode question
//https://leetcode.com/problems/intersection-of-two-linked-lists/description/

#include<iostream>
using namespace std;
class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};
void print(ListNode* head) {
        ListNode* temp = head;
        while(temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
        }
        cout << endl;
}
ListNode* getIntersectionNode(ListNode* headA,ListNode* headB){
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;
    while(temp1->next && temp2->next){
        if(temp1 == temp2) return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(temp1->next == NULL && temp2->next == NULL && temp1 != temp2) return NULL;
    if(temp1->next == NULL){
        int blen = 0;
        while(temp2->next){
            blen++;
            temp2 = temp2->next;
        }
        while(blen--){
            headB = headB->next;
        }
        }
        else{
            int alen = 0;
             while(temp1->next){
            alen++;
            temp1 = temp1->next;
        }
        while(alen--){
            headA = headA->next;
        }
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
}
int main() {
  ListNode* head = new ListNode(1);
  ListNode* second = new ListNode(2);
  ListNode* third = new ListNode(2);
  ListNode* fourth = new ListNode(3);
  ListNode* fifth = new ListNode(5);
  ListNode* sixth = new ListNode(4);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;

  ListNode* head2 = new ListNode(4);
  head2->next = fifth;

  ListNode* ans = getIntersectionNode(head,head2);
  cout<< ans->data <<endl;

}