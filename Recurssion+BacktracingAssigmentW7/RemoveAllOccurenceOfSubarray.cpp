// Remove all occurences of a subarray
//https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
#include<iostream>
#include<string>
using namespace std;
void removeOCCRE(string &s,string &part){
    int found = s.find(part);
    if(found!=string::npos){
    //part string has been located please remove it
    string left_part = s.substr(0,found);
    string right_part = s.substr(found+part.size(),s.size());
    s=left_part+right_part;
    removeOCCRE(s,part); 
    }
    else{
        // base case all the occurences of part has been removed from s
        return;
    }
}
string removeOccurence(string s,string part){
   removeOCCRE(s,part);
   return s; 
}
int main(){
    string s,part;
    cin>>s>>part;
    cout<<removeOccurence(s,part)<<endl;
    return 0;
}