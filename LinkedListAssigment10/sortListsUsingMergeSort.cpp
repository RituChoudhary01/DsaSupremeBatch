//sort Lists using merge sort
//https://leetcode.com/problems/sort-list/description/
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
// find middle node
ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;
    }
    return slow;
}
// merge two list
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
// print linked list
void print(ListNode* head) {
        ListNode* temp = head;
        while(temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
        }
        cout << endl;
}

    ListNode* SortList(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode* mid = findMid(head);
    ListNode* head1 = head;
    ListNode* head2 = mid->next;
    mid->next = NULL;
    head1 = SortList(head1);
    head2 = SortList(head2);
    ListNode* mergedLL = mergeTwoList(head1,head2);
    return mergedLL;
}

int main(){
   ListNode* head = new ListNode(1);
  ListNode* second = new ListNode(13);
  ListNode* third = new ListNode(5);
  ListNode* fourth = new ListNode(131);
  ListNode* fifth = new ListNode(55);
  ListNode* sixth = new ListNode(43);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  ListNode* sortedll = SortList(head);
  print(sortedll);
}