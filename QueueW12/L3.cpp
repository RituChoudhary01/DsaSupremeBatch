/*
// Q1.first non-repeating character in a stream
#include <iostream>
#include<queue>
using namespace std;
  string nonRepeating(string str) {
  int freq[26] = {0};
  queue<char> q;
  string ans = "";
  for(int i=0; i<str.length(); i++) {
      char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);
        while(!q.empty()){
            if(freq[q.front() - 'a'] > 1) {
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
                }
        }
        if(q.empty()){
            ans.push_back('#');
        }
  }
  return ans;
}
int main() {
string str = "zarcaazrd";
cout << " Final ans is: " << nonRepeating(str)<< endl;
return 0;
}
*/

/*
// Q2.Gas Station
// https://leetcode.com/problems/gas-station/description/

#include <iostream>
#include<queue>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int balance = 0;
        int start = 0;//circuit kaha se start krre ho
           for(int i=0; i<gas.size(); i++){
            balance += gas[i] - cost[i];
            if(balance < 0 ) {
                deficit += abs(balance);
                start = i+1;
                balance = 0;
            }
        }
        if(balance >= deficit ) {
            return start;
        }
        else {
            return -1;
        }
}
int main(){
    int n;
    cout<<"Enter number of gas station:"<<endl;
    cin>>n;
    vector<int>gas,cost;
    cout<<"Enter the amount of gas for every station:"<<endl;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        gas.push_back(input);
    }
    cout<<"Enter the amount of cost to reach next station:"<<endl;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        cost.push_back(input);
    }
    cout<<"which gas station i will start to complete my route: "<<canCompleteCircuit(gas,cost)<<endl;
    return 0;
}
*/

// Q3.sliding window maximum
// https://leetcode.com/problems/sliding-window-maximum/description/

#include <iostream>
#include<queue>
using namespace std;
 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<k; i++){
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        for(int i=k; i<nums.size(); i++) {
            if(!dq.empty() && i-dq.front() >= k) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
    int main(){
        int n;
    cout<<"Enter size of vector: "<<endl;
    cin>>n;
    vector<int>nums;
    cout<<"Enter the values in nums:"<<endl;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        nums.push_back(input);
    } 
    int k;
    cout<<"Enter the value of K"<<endl;
    cin>>k;
    vector<int>ans =  maxSlidingWindow(nums,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
    }