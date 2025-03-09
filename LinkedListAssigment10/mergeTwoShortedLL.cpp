//Merge Two Sorted Lists Leetcode Question
//https://leetcode.com/problems/merge-two-sorted-lists/description/
#include<iostream>
#include<algorithm>
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
ListNode* mergeTwoList(ListNode* head1,ListNode* head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    ListNode* ans = new ListNode(-1);
    ListNode* tail = ans;
    while(head1 && head2){
        if(head1->data <= head2->data){
          tail->next = head1;
          head1 = head1->next;
          tail = tail->next;
          tail->next = NULL;
        }
        else{
           tail->next = head2;
          head2 = head2->next;
          tail = tail->next;
          tail->next = NULL; 
        }
    }
    if(head1){
         tail->next = head1; 
    }
    if(head2){
        tail->next = head2;
    }
    return ans->next;
}

void print(ListNode* head) {
        ListNode* temp = head;
        while(temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
        }
        cout << endl;
}
int main(){
  ListNode* head1 = new ListNode(1);
  ListNode* second = new ListNode(3);
  ListNode* third = new ListNode(5);
  ListNode* fourth = new ListNode(13);
  ListNode* fifth = new ListNode(55);
  ListNode* sixth = new ListNode(43);
  head1 -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;

  ListNode* head2 = new ListNode(2);
  ListNode* second2 = new ListNode(4);
  ListNode* third2 = new ListNode(5);
  ListNode* fourth2 = new ListNode(3);
  ListNode* fifth2 = new ListNode(15);
  ListNode* sixth2 = new ListNode(-4);
  head2 -> next = second2;
  second2 -> next = third2;
  third2 -> next = fourth2;
  fourth2 -> next = fifth2;
  fifth2 -> next = sixth2;
  ListNode* ans = mergeTwoList(head1,head2);
  print(ans);
}