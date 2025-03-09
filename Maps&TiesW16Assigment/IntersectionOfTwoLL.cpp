// Intersection of two Linked List
// https://www.geeksforgeeks.org/problems/intersection-of-two-linked-list/1

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
Node* findIntersection(Node* head1,Node* head2){
    unordered_map<int,int>map;
    Node* curr = head2;
    while (curr) {
        map[curr->data]++;
        curr = curr->next;
    }
    Node* IL = NULL;
    Node* tail = NULL;
    curr = head1;

    while (curr) {
        if(map.find(curr->data)!=map.end()){
         if(!IL){
            IL = curr;
            tail = IL;
         }
         else{
            if(map[curr->data]>0){
                tail->next = curr;
                tail = tail->next;
                map[curr->data]--;
            }
         }
        }
        curr = curr->next;
    }
    tail->next = NULL;
    return IL;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    insert(head1, 8);
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

    Node* IntersectionList = findIntersection(head1, head2);

    cout << "Intersection of Linked Lists: ";
    printList(IntersectionList);

    return 0;
}