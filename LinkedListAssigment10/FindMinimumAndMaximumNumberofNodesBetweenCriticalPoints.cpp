//Find the Minimum and Maximum Number of Between Critical Points
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/

#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};
vector<int>nodesBetweenCriticalPoints(ListNode* head){
    vector<int> ans(2, -1);
    ListNode* prev = head;
    if(!prev) return ans;
    ListNode* curr = head->next;
    if(!curr) return ans;
    ListNode* nxt = head->next->next;
    if(!nxt) return ans;
    int firstCp = -1;
    int lastCp = -1;
    int minDist = INT_MAX;
    int i=1;
    while(nxt){
        bool isCp = ((curr->val>prev->val && curr->val>nxt->val)||(curr->val<prev->val && curr->val<nxt->val))? true:false;
        if(isCp && firstCp == -1){
            firstCp = i;
            lastCp = i;
        }
        else if(isCp){
            minDist = min(minDist,i-lastCp);
            lastCp = i;
        }
        ++i;
        prev = prev->next;
        curr = curr->next;
        nxt = nxt->next;
    }
    if(lastCp == firstCp) return ans;
    else{
        ans[0]=minDist;
        ans[1]=lastCp-firstCp;
    }
    return ans;
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
    vector<int>ans = nodesBetweenCriticalPoints(head);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
 }