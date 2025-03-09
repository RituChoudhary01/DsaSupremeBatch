// decode string
// https://leetcode.com/problems/decode-string/description/
#include<iostream>
#include<stack>
using namespace std;
string decodeString(string s) {
   stack<string>st;
   for(int i=0;i<s.size();i++){
    char ch = s[i];
   if(ch==']'){
    string stringToRepeat = "";
    while(!st.empty() && st.top()!="["){
     string top = st.top();
     stringToRepeat+=top;
     st.pop();
    }
    st.pop();
    string numericTimes="";
    while(!st.empty()&&isdigit(st.top()[0])){
        numericTimes+=st.top();
        st.pop();
    }
    reverse(numericTimes.begin(),numericTimes.end());
    int n = stoi(numericTimes);
    // final decoding
    string currentdeCode = "";
    while(n--){
        currentdeCode+=stringToRepeat;
    }
    st.push(currentdeCode);
   } 
   else{
    string temp(1,ch);
    st.push(temp);
   }
   }
   string ans;
   while(!st.empty()){
    ans+=st.top();
    st.pop();
   }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string s ="2[abc]3[cd]ef";
    cout<<decodeString(s);
    return 0;
}