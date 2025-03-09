//Rotate List
//https://leetcode.com/problems/rotate-list/description/

#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
};

int getLength(ListNode* head){
    int len = 0;
    while(head){
        ++len;
        head = head->next;
    }
    return len;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;
        int len = getLength(head);
        int actualRotate(k%len);
        if(actualRotate==0) return head;
        int newLastNodePos = len-actualRotate-1;
        ListNode* newLastNode = head;
        for(int i=0;i<newLastNodePos;i++){
            newLastNode = newLastNode->next;
        }
        ListNode* newhead = newLastNode->next;
        newLastNode->next = 0;
        ListNode* it = newhead;
        while(it->next){
            it = it->next;
        }
        it->next = head;
        return newhead;
    }
    void printList(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
    }
    int main(){
    int numOfNodes;
    cout<<"Enter the length of linked list"<<endl;
    cin>>numOfNodes;
    ListNode* head = NULL;
    ListNode* tail = head;
    while(numOfNodes--){
        int data;
        cin>>data;
        if(head==NULL){
            head = new ListNode(data);
            tail = head;
        }
        else{
            tail->next = new ListNode(data);
            tail = tail->next;
        }
    }
    int K;
    cout<<"Enter the value of K"<<endl;
    cin>>K;
     ListNode* ans = rotateRight(head,K);
     printList(ans);

    return 0;
    }