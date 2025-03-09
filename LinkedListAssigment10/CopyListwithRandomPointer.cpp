//Copy List with Random Pointer
//https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* random;
    Node(int _val){
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// Approach 1 using hash map
Node* copyRandomList(Node* head){
if(!head) return nullptr;
unordered_map<Node* , Node*>mp;
Node* curr = head;
while(curr){
    mp[curr]=new Node(curr->val);
    curr = curr->next;
}
curr = head;
while(curr){
mp[curr]->next = mp[curr->next];
mp[curr]->random = mp[curr->random];
curr = curr->next;
}
return mp[head];
}

// Approach 2
    Node* copyRandomList2(Node* head) {
        if (!head) return nullptr;

        // Step 1: Clone each node and insert it right after the original node
        Node* it = head;
        while (it) {
            Node* cloneNode = new Node(it->val);
            cloneNode->next = it->next;
            it->next = cloneNode;
            it = cloneNode->next;
        }

        // Step 2: Assign random pointers for the cloned nodes
        it = head;
        while (it) {
            Node* cloneNode = it->next;
            cloneNode->random = it->random ? it->random->next : nullptr;
            it = cloneNode->next;
        }

        // Step 3: Detach the cloned nodes from the original list.
        it = head;
        Node* cloneHead = head->next;
        while (it) {
            Node* cloneNode = it->next;
            it->next = cloneNode->next;
            if (cloneNode->next) {
                cloneNode->next = cloneNode->next->next;
            }
            it = it->next;
        }

        return cloneHead;
    }

    void printList(Node* head){
    Node* it = head;
    while (it){
        cout << "Node val: " << it->val;
        if (it->random) {
            cout << ", Random val: " << it->random->val;
        } else {
            cout << ", Random val: null";
        }
        cout << endl;
        it = it->next;
    }
}

int main() {
    // Step 1: Create the original LL
    Node* node1 = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);

    // Set up the next pointers
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Set up the random pointers
    node1->random = nullptr;   
    node2->random = node1;      
    node3->random = node5;      
    node4->random = node3;      
    node5->random = node1;      

    // Print the original list
    cout << "Original list:" << endl;
    printList(node1);

    // Step 2: Copy the list
    
    Node* clonedHead = copyRandomList(node1);

    // Print the cloned list
    cout << "Cloned list:" << endl;
    printList(clonedHead);

    // Step 3: Clean up memory
    Node* it = node1;
    while (it) {
        Node* temp = it;
        it = it->next;
        delete temp;
    }

    it = clonedHead;
    while (it) {
        Node* temp = it;
        it = it->next;
        delete temp;
    }

    return 0;
}
