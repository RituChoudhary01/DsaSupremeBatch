//Remove all adjacent Duplicates in string.
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

#include<iostream>
#include<stack>
using namespace std;
string removeDuplicates(string s) {
    stack<char>st;
    for(int i=0;i<s.length();i++){
    if(s.empty()) st.push(s[i]);
    else if(!st.empty() && st.top()== s[i]){
        st.pop();
    }
    else{
        st.push(s[i]);
    }
    }
    string  ans;
    while(!st.empty()){
    ans+=st.top();
    st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;

}
int main(){
    string str = "abbaca";
    string ans = removeDuplicates(str);
    cout<<ans<<endl;
    return 0;
}