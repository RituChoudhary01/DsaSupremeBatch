// Word Break II
// https://leetcode.com/problems/word-break-ii/description/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string>solve(string& s,unordered_map<string,bool>& dict,int i){
    if (i == s.size()) return {""};
    vector<string>ans;
    string word;
    for(int j=i;j<s.size();j++){
        word.push_back(s[j]);
        if(dict.find(word)==dict.end()) continue;
        // found a valid word
        vector<string> rightParts = solve(s, dict, j + 1);
        for (const string& rightPart : rightParts) {
            string endPart = (rightPart.empty()) ? "" : " " + rightPart;
            ans.push_back(word + endPart);
        }
    }
    return ans;
}

unordered_map<int,vector<string> >dp;
vector<string> solveTD(string& s, unordered_map<string, bool>& dict, int i) {
    if (i == s.size()) return {""};  
   if (dp.find(i) != dp.end()) return dp[i]; 
   vector<string> ans;
    string word;

    for (int j = i; j < s.size(); j++) {
        word.push_back(s[j]);
        if (dict.find(word) == dict.end()) continue; 

        // Recursively process the right part of the sentence
        vector<string> rightParts = solveTD(s, dict, j + 1);
        for (const string& rightPart : rightParts) {
            string endPart = (rightPart.empty()) ? "" : " " + rightPart;
            ans.push_back(word + endPart);
        }
    }

    return dp[i] = ans;  

}

void wordBreak(string s,vector<string>& wordDict){
    unordered_map<string,bool>dict;
    for(auto word:wordDict) dict;
    vector<string>sentences =  solve(s,dict,0);
    // vector<string>sentences =  solveTD(s,dict,0);
    cout << "Possible sentences:\n";
    for (const string& sentence : sentences) {
        cout << sentence << endl;
    }
}
int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int n;
    cout << "Enter dictionary size: ";
    cin >> n;

    vector<string> dict;
    cout << "Enter dictionary words:\n";
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
    }
    wordBreak(s, dict);
    return 0;
}