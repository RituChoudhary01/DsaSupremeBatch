//Count the Reversals
// https://www.geeksforgeeks.org/problems/count-the-reversals0401/1

#include<iostream>
#include<stack>
using namespace std;
int countRev(string s){
    int ans = 0;
    // if odd sized string then impossible to make pair
    if(s.size()&1) return -1;
    stack<char>st;
    for(char ch:s){
        if(ch=='{') st.push(ch);
        else{
            if(!st.empty()&& st.top()=='{') st.pop();
            else st.push(ch);
        }
    }
    // if stack is still not empty,let's count reversals
    while(!st.empty()){
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();
        if(a==b) ans+=1;
         else ans+=2;
    }
    return ans;
}
int main(){
    string str = "}{{}}{{{";
    cout<<countRev(str)<<endl;
    return 0;
}