#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
// Q1.Remove Stones to minimize the total
// https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;

        for(int i=0; i<piles.size(); i++) {
            maxHeap.push(piles[i]);
        }

        while(k--) {
            int maxElement = maxHeap.top();
            maxHeap.pop();
            maxElement = maxElement - floor(maxElement/2);
            maxHeap.push(maxElement);
        }

        int sum = 0;
        while(!maxHeap.empty()) {
            int temp = maxHeap.top();
            maxHeap.pop();
            sum += temp;
        }
        return sum;
    }
    int main(){
        int n;
        cout<<"Enter size of vector: "<<endl;
        cin>>n;
        vector<int>piles;
        cout<<"Enter element of vector: "<<endl;
        for(int i=0;i<n;i++){
            int input;
            cin>>input;
            piles.push_back(input);
        }
        int k;
        cout<<"Enter number of operations: "<<endl;
        cin>>k;
        cout<<"minimum total number of stones: "<<minStoneSum(piles,k)<<endl;
        return 0;
    }
    */
   /*
    // Q2.Recoganize String
    // https://leetcode.com/problems/reorganize-string/description/
     
    class node{
    public:
    char data;
    int count;

    node(char d, int c){
        data = d;
        count = c;
    }
};

class compare{
    public:
    bool operator()(node a, node b){
        return a.count < b.count;
    }
};
    string reorganizeString(string s){

        //create mapping
        int freq[26] = {0};

        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            freq[ch-'a']++;
        }

        priority_queue<node, vector<node>, compare> maxHeap;
        for(int i=0; i<26; i++){
            if(freq[i] != 0) {
                node temp(i+'a', freq[i]);
                maxHeap.push(temp);
            }
        }
        string ans = "";
        while(maxHeap.size() > 1) {
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();

            ans += first.data;
            ans += second.data;

            first.count--;
            second.count--;

            if(first.count != 0) {
                maxHeap.push(first);
            } 

            if(second.count != 0) {
                maxHeap.push(second);
            } 
        }
        if(maxHeap.size() == 1) {
            node temp = maxHeap.top();
            maxHeap.pop();
            if(temp.count == 1) 
                ans += temp.data;
            else
                return "";
        }
        return ans;
    }
    int main(){
        string s;
        cin>>s;
        cout<< reorganizeString(s)<<endl;
        cout<<endl;
    }
     */
     
     /*
    // Q3.Longest Happy String
    // https://leetcode.com/problems/longest-happy-string/description/

    class node {
    public:
    char data;
    int count;

    node(char d, int c) {
        data = d;
        count = c;
    }
};

class compare {
    public:
    bool operator()(node a, node b){
        return a.count < b.count;
    }
};
    string longestDiverseString(int a, int b, int c) {
        priority_queue<node, vector<node>, compare> maxHeap;
        if(a > 0){
            node temp('a', a);
            maxHeap.push(temp);
        }
        if(b > 0){
            node temp('b', b);
            maxHeap.push(temp);
        }
         if(c > 0) {
            node temp('c', c);
            maxHeap.push(temp);
        }
        string ans = "";
        while(maxHeap.size() > 1) {
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();

            if(first.count >= 2) {
                ans += first.data;
                ans += first.data;
                first.count -= 2;
            }
            else {
                ans += first.data;
                first.count--;
            }

            if(second.count >= 2 && second.count >= first.count) {
                ans += second.data;
                ans += second.data;
                second.count -= 2;
            }
            else {
                ans += second.data;
                second.count--;
            }

            if(first.count > 0) {
                maxHeap.push(first);
            }

            if(second.count > 0) {
                maxHeap.push(second);
            }
        }

        if(maxHeap.size() == 1) {
            node temp = maxHeap.top();
            maxHeap.pop();

            if(temp.count >= 2) {
                ans += temp.data;
                ans += temp.data;
                temp.count -= 2;
            }
            else {
                ans += temp.data;
                temp.count--;
            }
        }
        return ans;
    }
    int main(){
        int a,b,c;
        cout<<"Enter number of a: ";
        cin>>a;
        cout<<"Enter number of b: ";
        cin>>b;
        cout<<"Enter number of a: ";
        cin>>c;
        cout<<"longest possible happy string: "<<longestDiverseString(a,b,c)<<endl;
    }
    */

    //Q4.Median in a Stream
    int signum(int a , int b){
        if(a == b) 
                return 0;
        if(a > b )
                return 1;
        if(a < b)
                return -1;
     }
void callMedian(double &median, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int> >& minHeap, int element) {
        switch(signum(minHeap.size(), maxHeap.size())){
                case 0:if(element > median){
                        minHeap.push(element);
                        median = minHeap.top();
                        }
                        else{
                        maxHeap.push(element);
                        median = maxHeap.top();
                       }
                        break;
                case 1: if(element > median ){
                        int minTop = minHeap.top();
                        minHeap.pop();
                        maxHeap.push(minTop);
                        minHeap.push(element);
                        median = (minHeap.top() + maxHeap.top())/2.0;
                        }
                        else{
                        maxHeap.push(element);
                        median = (minHeap.top() + maxHeap.top())/2.0;
                        }
                        break;
                case -1: if(element > median){
                        minHeap.push(element);
                        median = (minHeap.top() + maxHeap.top())/2.0;
                         }
                         else{
                        int maxTop = maxHeap.top();
                        maxHeap.pop();
                        minHeap.push(maxTop);
                        maxHeap.push(element);
                        median = (minHeap.top() + maxHeap.top())/2.0;
                        }
                        break;
                     }
}

int main() {
        int arr[12] = {5,15,1,3,2,8,7,9,10,6,11,4};
        int n = 12;

        //5 6 5 6 5 6
        double median = 0;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int> > minHeap;
        for(int i=0; i<n; i++) {
                int element = arr[i];
                callMedian(median, maxHeap,minHeap, element);
                cout << "arr[i]->median:  " << median << endl;
        }
        cout << endl;
        return 0;
}