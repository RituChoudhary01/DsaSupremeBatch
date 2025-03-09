/*
//Q1.Min Stack
// https://leetcode.com/problems/min-stack/description/
class MinStack {
public:
    vector<pair<int, int> > arr; // Space added between angle brackets
    MinStack() {
        // Constructor
    }
    void push(int val) {
        if (arr.empty()) {
            arr.push_back(make_pair(val, val));
        } else {
            int mini = min(val, arr.back().second);
            arr.push_back(make_pair(val, mini));
        }
    }

    void pop() {
        arr.pop_back();
    }

    int top() {
        return arr.back().first;
    }

    int getMin() {
        return arr.back().second;
    }
};
*/


/*
//Q2. longest Valid Parentheses
// https://leetcode.com/problems/longest-valid-parentheses/description/
#include<iostream>
#include<stack>
using namespace std;
int longestValidParentheses(string s){
    stack<int>st;
    st.push(-1);
    int maxLen = 0;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch == '('){
            st.push(i);
        }
        else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }
            else{
                int len = i-st.top();
                maxLen = max(len,maxLen);
            }
        }
    }
    return maxLen;
}
int main(){
    string input;
    cout<<"Enter the input:"<<endl;
    getline(cin,input);
    int ans = longestValidParentheses(input);
    cout<<" longest Valid Parentheses : "<<ans<<endl;
    return 0;
}
*/

/*
// Q3.Next Smaller element and prev Smaller element
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> prevSmallerElement(vector<int>& input){
    stack<int>s;
    s.push(-1);
    vector<int> ans(input.size());
    for(int i=0;i<input.size();i++){
        int curr = input[i];
        while(s.top() >= curr){
        s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}

vector<int> nextSmallerElement(vector<int>& input){
    stack<int>s;
    s.push(-1);
    vector<int> ans(input.size());
    for(int i = input.size()-1;i>=0;i--){
        int curr = input[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}

  int main(){
  vector<int> input;
  input.push_back(2);
  input.push_back(1);
  input.push_back(4);
  input.push_back(3);
  vector<int> ans1 = nextSmallerElement(input);

  cout << "Printing ans1" << endl;
  for(int i=0; i<input.size(); i++){
          cout << ans1[i] << " ";
  }
  cout << endl;

  vector<int> ans2 = prevSmallerElement(input);
  cout << "Printing ans2 " << endl;
  for(int i=0; i<input.size(); i++) {
          cout << ans2[i] << " ";
  }
  cout << endl;
  return 0;
}   
*/

// Q4.Largest Rectangular Area in a Histogram
#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;
vector<int> prevSmallerElement(vector<int>& input){
    stack<int>s;
    s.push(-1);
    vector<int>ans(input.size());
    for(int i=0;i<input.size();i++){
        int curr = input[i];
        while(s.top()!= -1 && input[s.top()]>= curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int>nextSmallerElement(vector<int>& input){
stack<int> s;
s.push(-1);
vector<int> ans(input.size());
for(int i=input.size()-1; i>=0; i--) {
          int curr = input[i]; 
while(s.top() != -1 && input[s.top()] >= curr){
      s.pop();
 }
    ans[i] = s.top();
    s.push(i);
  }
  return ans;    
}
int getRectangularAreaHistogram(vector<int>& height){
    vector<int>prev = prevSmallerElement(height);
    vector<int>next = nextSmallerElement(height);
    int maxArea = INT_MIN;
    int size = height.size();
    for(int i=0;i<height.size();i++){
        int length = height[i];
        if(next[i] == -1){
            next[i] = size;
        }
        int width = next[i]-prev[i]-1;
        int area = length * width;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}
int main(){
    vector<int>v;
    v.push_back(2);
  v.push_back(1);
  v.push_back(5);
  v.push_back(6);
  v.push_back(2);
  v.push_back(3);

  cout << "Ans is: " << getRectangularAreaHistogram(v) << endl;
  return 0;
}

