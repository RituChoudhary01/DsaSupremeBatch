// Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/description/
#include<iostream>
#include<vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs){
int i=0;
string ans="";
while(true){
    char curr_ch = 0;
    for(int j=0;j<strs.size();j++){
        if(i>=strs[j].size()){
            // out of bound
            curr_ch = 0;
            break;
        }
        // just start
        if(curr_ch == 0){
            curr_ch = strs[j][i];
        }
        else if(strs[j][i]!= curr_ch){
            curr_ch = 0;
            break;
        }
    }
    if(curr_ch == 0)
    break;
    ans.push_back(curr_ch);
    i++;
}
return ans;
}
int main(){
vector<string> strs ={"flower","flow","flight"};
 string ans = longestCommonPrefix(strs);
 cout<<ans<<endl;
}
