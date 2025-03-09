// WildCard Matching
// https://leetcode.com/problems/wildcard-matching/
#include<iostream>
using namespace std;
bool isMatchHelper(string &s,int si,string &p,int pi){
    // base case
    if(si==s.size()&&pi==p.size()) return true;
    if(si==s.size()&&pi<p.size()){
        while(pi<p.size()){
            if(p[pi]!='*') return false;
        }
        return true;
    }
    // single char matching
    if(s[si]==p[pi]||'?'==p[pi]){
        return isMatchHelper(s,si+1,p,pi+1);
    }
    if(p[pi]=='*'){
        // treat '*' as empty or null
        bool caseA = isMatchHelper(s,si,p,pi+1);
        // let * consume one char
        bool caseB = isMatchHelper(s,si+1,p,pi);
       return caseA||caseB; 
    }
    // char doesnot match
    return false;
}
bool isMatch(string s,string p){
   int si = 0;//pointer index for s string
   int pi = 0;//pointer index for p string
   return isMatchHelper(s,si,p,pi);
}
int main(){
    string s,p;
    cin>>s>>p;
    if(isMatch(s,p)) {
        cout<<"Both string are matching."<<endl;
    }
    else{
       cout<<"Both string are not matching."<<endl;  
    }
    return 0;
}
