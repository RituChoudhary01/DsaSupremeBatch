// Union of two Linked List.
// https://www.geeksforgeeks.org/problems/union-of-two-linked-list/1

#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

struct Node* makeUnion(struct Node*head1,struct Node* head2){
    map<int,Node*>mp;
    Node* curr = head1;
    while(curr){
        mp[curr->data]=curr;
        curr = curr->next;
    }
    curr = head2;
    while(curr){
        mp[curr->data]=curr;
        curr = curr->next;
    }
    Node* UL = NULL;
    curr = 0;
    for(auto it = mp.begin();it!=mp.end();it++){
     if(!UL){
        UL = it->second;
        curr = UL;
     }
     else{
        curr->next = it->second;
        curr = curr->next;
     }
    }
    curr->next = 0;
    return UL;
    }

    int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    insert(head1, 1);
    insert(head1, 2);
    insert(head1, 4);
    insert(head1, 6);

    insert(head2, 2);
    insert(head2, 5);
    insert(head2, 6);
    insert(head2, 8);

    cout << "First Linked List: ";
    printList(head1);

    cout << "Second Linked List: ";
    printList(head2);

    Node* unionList = makeUnion(head1, head2);

    cout << "Union of Linked Lists: ";
    printList(unionList);

    return 0;
}