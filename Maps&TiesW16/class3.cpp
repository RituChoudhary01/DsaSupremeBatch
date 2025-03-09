#include <iostream>
#include<vector>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char d) {
        this->data = d;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        this->isTerminal = false;
    }
};

// Function to insert a word in the Trie
void insertWord(TrieNode* root, string word) {
    if (word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    // If present, move to next node
    if (root->children[index] != NULL) {
        child = root->children[index];
    } else {
        // If not present, create a new node
        child = new TrieNode(ch);
        root->childCount++;
        root->children[index] = child;
    }

    // Recursive call for the remaining word
    insertWord(child, word.substr(1));
}

// Function to search for a word in the Trie
bool searchWord(TrieNode* root, string word) {
    if (word.length() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    // If present, move to next node
    if (root->children[index] != NULL) {
        child = root->children[index];
    } else {
        return false;
    }

    // Recursive call for the remaining word
    return searchWord(child, word.substr(1));
}
/*
// Q1.Longest Common Prefix.
// https://leetcode.com/problems/longest-common-prefix/description/

// Method 1.
 string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        //loop on first string
        for(int i=0; i<strs[0].length(); i++) {
            char ch = strs[0][i];
            bool match = true;

            //compare this charachter with all 
            //the remaining strings at the same index
            for(int j=1; j<strs.size(); j++  ) {
                //compare
                if(strs[j].size() < i || ch != strs[j][i]) {
                    match = false;
                    break;
                }
            }
            if(match == false)
                break;
            else
                ans.push_back(ch);
        }
        return ans;
    }
    
    //Method 2 using trie
     void findLCP(string first, string &ans, TrieNode* root) {
            if(root->isTerminal){
                    return;
            }
        for(int i=0; i<first.length(); i++) {
            char ch = first[i];

            if(root->childCount == 1) {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else
                break;
            
            if(root->isTerminal)
                break;
        }
    }
string longestCommonPrefix(vector<string>& strs){
TrieNode* root = new TrieNode('-');
//insert strings
for(int i=0; i<strs.size(); i++) {
insertWord(root, strs[i]);
}
        string ans="";
        string first = strs[0];
        findLCP(first, ans, root);
        return ans;
}

int main(){
    vector<string> strs;
   int n;
   cout<<"Enter nmber of string: "<<endl;
   cin>>n;
   for(int i=0;i<n;i++){
    string str;
    cin>>str;
    strs.push_back(str);
   }
   cout<<"Longest common prifix: "<<longestCommonPrefix(strs)<<endl;
     return 0;
}
*/
// Q2.
void storeSuggestions(TrieNode* curr, vector<string>& temp, string &prefix) {
	if(curr -> isTerminal)
	{
		temp.push_back(prefix);
	}

	//a to z tak choices dedo
	for(char ch ='a'; ch<='z'; ch++) {
		int index = ch-'a';

		TrieNode* next = curr->children[index];

		if(next != NULL) {
			//if child exists
			prefix.push_back(ch);
			storeSuggestions(next, temp, prefix);
			prefix.pop_back();
		}
	}
	
}

vector<vector<string> > getSuggestions(TrieNode* root, string input) {

	//var/DS
	TrieNode* prev = root;
	vector<vector<string> > output;
	string prefix="";
	
	for(int i=0; i<input.length(); i++) {
		char lastch = input[i];

		int index = lastch - 'a';
		TrieNode* curr = prev->children[index];

		if(curr == NULL)
			break;
		else {
			//iske andar main saare suggestion store krke launga
			vector<string> temp;
			prefix.push_back(lastch);
			storeSuggestions(curr, temp, prefix);
			output.push_back(temp);
			prev = curr;
		}
	}
	return output;
}
int main() {
	vector<string> v;
	v.push_back("love");
	v.push_back("lover");
	v.push_back("loving");
	v.push_back("last");
	v.push_back("lost");
	v.push_back("lane");
	v.push_back("lord");

	string input = "lovi";

	TrieNode* root = new TrieNode('-');
	for(int i=0; i<v.size(); i++) {
		insertWord(root, v[i]);
	}

	vector<vector<string> > ans  = getSuggestions(root, input);

	cout << "Printing the answer: " << endl;

	for(int i=0; i<ans.size(); i++) {

		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j]<<", ";
		}
		cout << endl;
	}
  return 0;
}