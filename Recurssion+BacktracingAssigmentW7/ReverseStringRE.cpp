// reverse a string RE
#include<iostream>
using namespace std;
void reverse(string& s,int start, int end){
    // BC
    if(start>=end)
        return;
    //1 case solve kr do
    swap(s[start],s[end]);
    // baki resurssion smabal lega.
    reverse(s,start+1,end-1);
}
int main(){
     string s;
     cin>>s;
     reverse(s,0,s.size()-1);
     cout<<s<<endl;
     return 0;
}