//Flatten Linked List 
//
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* bottom;
    Node(int data){
     this->data = data;
     next = NULL;
     bottom = NULL;
    }
};
Node* merge(Node* a,Node* b){
    if(!a) return b;
    if(!b) return a;
    Node* ans = NULL;
    if(a->data < b->data){
        ans = a;
        a->bottom = merge(a->bottom,b);
    }
    else{
        ans = b;
        b->bottom = merge(a,b->bottom);
    }
    return ans;
}
Node* flatten(Node* root){
    if(!root) return NULL;
    Node* mergeLL = merge(root,flatten(root->next));
    return mergeLL;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;
}


int main(){
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);

    head = flatten(head);

    printList(head);
    return 0;
}