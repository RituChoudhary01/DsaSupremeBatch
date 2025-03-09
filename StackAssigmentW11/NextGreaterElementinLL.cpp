// Next Greater Node In Linked List
// https://leetcode.com/problems/next-greater-node-in-linked-list/description/

#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
  };
vector<int> nextLargerNodes(ListNode* head){
  vector<int>ll;
  while(head){
    ll.push_back(head->val);
    head = head->next;
  }
  stack<int>st;
  for(int i=0;i<ll.size();++i){
   while(!st.empty() && ll[i]>ll[st.top()]){
    int kids = st.top();
    st.pop();
    ll[kids] = ll[i];
   } 
   st.push(i);
  }
  while(!st.empty()){
    ll[st.top()]=0;
    st.pop();
  }
  ll[ll.size()-1] = 0;
  return ll;
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
    vector<int>ans = nextLargerNodes(head);
    for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}