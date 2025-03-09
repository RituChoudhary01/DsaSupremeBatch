//Delete N nodes after M nodes of a linked list
//https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1

#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

    Node* linkdelete(Node* head,int m,int n){
    Node* node = head;
    while(node){
        Node* prev = NULL;
        // skip m nodes
        for(int i=0;i<m && node!=NULL;i++){
            prev = node;
            node = node->next;
        }
        // delete n nodes
        for(int i=0;i<n&&node!=NULL;i++){
            Node* temp = node;
            node = node->next;
            delete temp;
        }
        prev->next = node;
    }
     return head;
    }

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    int n,m;
    cout<<"Enter the value of m and n"<<endl;
    cin>>m>>n;
    int numOfNodes;
    cout<<"Enter the length of linked list"<<endl;
    cin>>numOfNodes;
    Node* head = NULL;
    Node* tail = head;
    while(numOfNodes--){
        int data;
        cin>>data;
        if(head==NULL){
            head = new Node(data);
            tail = head;
        }
        else{
            tail->next = new Node(data);
            tail = tail->next;
        }
    }
    Node* ans =linkdelete(head,m,n);
    printList(ans);

    return 0;
}