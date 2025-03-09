//Merge Nodes in Between Zeros
// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

#include<iostream>
using namespace std;
struct ListNode{
 int val;   
 ListNode *next;
 ListNode():val(0),next(nullptr){}
 ListNode(int x):val(x), next(nullptr){}
 ListNode(int x,ListNode *next):val(x),next(next){}
 };

ListNode* mergeNodes(ListNode* head){
     if(!head) return NULL;
     ListNode* slow = head,*fast = head->next;
     ListNode* newLastNode = NULL;
     int sum = 0;
     while(fast){
        if(fast->val!=0){
            sum+=fast->val;
        }
        else{
            slow->val = sum;
            newLastNode = slow;
            slow = slow->next;
            sum = 0;
        }
        fast = fast->next;
     }
     ListNode* temp = newLastNode->next;
     newLastNode->next = NULL;
     while(temp){
        ListNode* nxt = temp->next;
        delete temp;
        temp = nxt;
     }
     return head;
}

void printList(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
}    
int main(){
    ListNode* head = new ListNode(0);
    ListNode* first = new ListNode(3);
    ListNode* second = new ListNode(1);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    ListNode* sixth = new ListNode(2);
    ListNode* last = new ListNode(0);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = last;
    ListNode* ans = 
    mergeNodes(head);
    printList(ans);
    return 0;
}