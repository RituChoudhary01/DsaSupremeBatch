#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
// Q1. merge k sorted array.
class info {
        public:
        int data;
        int row;
        int col;

        info(int val, int r, int c) {
                data = val;
                row = r;
                col = c;
        }  
};

class compare {
        public:
        bool operator()(info* a, info* b) {
                return a->data > b->data;
        }
};
vector<int> mergeKSortedArrays(int arr[][4], int k, int n) {
        priority_queue<info*,vector<info*>, compare > minHeap;
        //hr array ka first element insert karo 
        for(int i=0; i<k; i++) {
                info* temp = new info(arr[i][0], i, 0);
                minHeap.push(temp);
        }
             vector<int> ans;
             while(!minHeap.empty()) {
                info* temp = minHeap.top();
                int topElement = temp->data;
                int topRow = temp->row;
                int topCol = temp->col;
                minHeap.pop();
                ans.push_back(topElement);
                if(topCol + 1 < n) {
                        info* newInfo = new info(arr[topRow][topCol+1], topRow, topCol+1);
                        minHeap.push(newInfo);
                }
        }
        return ans;
}

int main() {
        int arr[][4] = { {2,4,6,8}, 
                        {1,3,5,7}, 
                        {0,9,10,11}};
        int k = 3;
        int n = 4;
        vector<int> ans  = mergeKSortedArrays(arr, k, n);
        for(auto i:ans) {
                cout << i << " ";
        }cout << endl;
  return 0;
}
*/

/*
Q2.Merge K sorted lists
// https://leetcode.com/problems/merge-k-sorted-lists/description/
*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class compare {
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();
        if(k == 0) return NULL;

        //first element of every blinked list ko insert krdo heap me 
        for(int i=0; i<k; i++) {
            if(lists[i] != NULL ) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()) {
            ListNode* temp = minHeap.top();
            minHeap.pop();

            //temp may or may not be the first element of answer linked list 
            if(head == NULL) {
                //temp -> first element of ans LL
                head = temp;
                tail = temp;
                if(tail->next != NULL) {
                    minHeap.push(tail->next);
                }

            }
            else {
                //temp isnnot the first element of LL
                tail->next = temp;
                tail = temp;
                if(tail->next != NULL) {
                    minHeap.push(tail->next);
                }
            }
        }
    return head;
    }
};
ListNode* createList() {
    int n;
    cout << "Enter the number of elements in the linked list (-1 to stop):\n ";
    cin >> n;
    
    if (n == -1) return NULL;

    ListNode* head = NULL;
    ListNode* tail = NULL;
    
    while (n != -1) {
        ListNode* newNode = new ListNode(n);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> n;  // Read next element
    }

    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int k;
    cout << "Enter the number of linked lists: ";
    cin >> k;

    vector<ListNode*> lists;

    // Taking input for each linked list
    for (int i = 0; i < k; i++) {
        cout << "Enter elements for linked list " << i + 1 << " (terminate with -1):" << endl;
        lists.push_back(createList());
    }

    Solution sol;
    ListNode* mergedHead = sol.mergeKLists(lists);

    // Printing the merged linked list
    cout << "Merged Sorted Linked List: ";
    printList(mergedHead);

    return 0;
}

/*
// Q3.Smallest Range Covering From K Lists
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

class Node {
public:
    int data;
    int row;
    int col;

    Node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

// Custom comparator for min-heap
class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

// Function to find the smallest range that includes at least one number from each of the k lists
vector<int> smallestRange(vector<vector<int> >& nums) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    int k = nums.size();

    // Initialize the min-heap with the first element from each row
    for (int i = 0; i < k; i++) {
        int element = nums[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        minHeap.push(new Node(element, i, 0));
    }

    int ansStart = mini;
    int ansEnd = maxi;

    // Process the heap until we can't pick from all lists
    while (!minHeap.empty()) {
        Node* top = minHeap.top();
        minHeap.pop();

        mini = top->data; // Update mini

        // Check if we found a smaller range
        if (maxi - mini < ansEnd - ansStart) {
            ansStart = mini;
            ansEnd = maxi;
        }

        // Check for a new element in the same row
        if (top->col + 1 < nums[top->row].size()) {
            int newData = nums[top->row][top->col + 1];
            maxi = max(maxi, newData);
            minHeap.push(new Node(newData, top->row, top->col + 1));
        } else {
            // If there are no more elements in this row, break (as we can't take from all lists)
            delete top; // Free memory
            break;
        }
        delete top; 
    }

    // Clean up remaining nodes in the heap
    while (!minHeap.empty()) {
        delete minHeap.top();
        minHeap.pop();
    }

        vector<int> ans ;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
}

int main() {
    int row, col;
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;

    vector<vector<int> > nums(row); // Initialize rows
    cout << "Enter the elements of the vector: " << endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int input;
            cin >> input;
            nums[i].push_back(input);
        }
    }

    vector<int> ans = smallestRange(nums);
    cout << "Smallest Range is: [ " << ans[0] << ", " << ans[1] << " ]" << endl;

    return 0;
}
*/
