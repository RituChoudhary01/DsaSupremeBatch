#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// generate a number of valid paranthesis
 void solve(vector<string> &ans, int n,int used_open, int used_close, int rem_open, int rem_close, string output) {
        //base case 
        if(rem_open == 0 && rem_close == 0) {
            ans.push_back(output);
            return;
        }
        //include open bracket
        if(rem_open > 0 ){
            // output.push_back('(');
            solve(ans, n, used_open+1, used_close, rem_open-1, rem_close, output + '(' );
            //backtrack
            // output.pop_back();
        }

        //include close bracket
        if(used_open > used_close) {
            // output.push_back(')');
            solve(ans, n , used_open, used_close+1, rem_open, rem_close-1 ,output + ')');
            //backtrack
            // output.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int used_open = 0;
        int used_close = 0;
        int rem_open = n;
        int rem_close = n;
        string output = "";
        solve(ans, n, used_open, used_close, rem_open,rem_close, output);
        return ans;
    }

    // Q2. Keypad problem
     void solve(vector<string> &ans,int index, string output, string digits,vector<string> &mapping) {
        //base case
        if(index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        //1 case solve, baaki recursion
        char digitCharacter = digits[index];

        int digitInteger = digitCharacter -'0';

        string value = mapping[digitInteger];

        for(int i=0; i<value.length(); i++) {
            char ch = value[i];

            //include
            //output.push_back(ch);
            //recursive call
            solve(ans, index+1, output + ch, digits, mapping);
            //backtrack
           // output.pop_back();
        }

    }
 
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        //empty string k liye answer empty array hoga 
        if(digits.length() == 0)
            return ans;
        
        int index = 0;
        string output = "";
        vector<string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        // unordered_map<int, string> mapping;
        // mapping[2] = "abc";
        // mapping[3] = "def";
        // mapping[4] = "ghi";
        // mapping[5] = "jkl";
        // mapping[6] = "mno";
        // mapping[7] = "pqrs";
        // mapping[8] = "tuv";
        // mapping[9] = "wxyz";

        solve(ans, index, output, digits, mapping);

        return ans;

        
    }
