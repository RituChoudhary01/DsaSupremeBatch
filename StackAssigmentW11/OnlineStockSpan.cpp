// Online Stock Span
//https://leetcode.com/problems/online-stock-span/description/
#include<iostream>
#include<stack>
using namespace std;
stack<pair<int,int> >st;
int next(int price){
    int span = 1;
    while(!st.empty() && st.top().first<=price){
        span+=st.top().second;
        st.pop();
    }
    st.push(make_pair(price,span));
    return span;
}
int main(){
    cout<<next(100)<<" ";
    cout<<next(80)<<" ";
    cout<<next(60)<<" ";
    cout<<next(70)<<" ";
    cout<<next(60)<<" ";
    cout<<next(75)<<" ";
    cout<<next(85)<<" ";
    return 0;
}
