//Print the value of kth node from end.
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
void print(Node* head) {
        Node* temp = head;
        while(temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
        }
        cout << endl;
}
void fun(Node* head,int &position,int &ans){
    if(head == NULL) return;
    fun(head->next,position,ans);
    if(position == 1) ans = head->data;
    position--;
}
int getNode(Node* head,int position){
    int ans = 1;
    fun(head,position,ans);
    return ans;
}
int main() {
  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(2);
  Node* fourth = new Node(3);
  Node* fifth = new Node(5);
  Node* sixth = new Node(4);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  int position;
  cout<<"Enter the valid value of position: "<<endl;
  cin>>position;
  int ans = getNode(head,position);
  cout<<ans<<endl;
}