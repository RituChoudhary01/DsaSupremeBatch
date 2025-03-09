// Palindrome Pairs
// https://leetcode.com/problems/palindrome-pairs/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TrieNode {
public:
    TrieNode *children[26];
    int stringNumber;
    bool isTerminal;

    TrieNode() : stringNumber(-1), isTerminal(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode *root;

    void insertUtil(TrieNode *node, string &word, int index, int stringNumber) {
        if (index >= word.size()) {
            node->isTerminal = true;
            node->stringNumber = stringNumber;
            return;
        }
        int charIndex = word[index] - 'a';
        if (!node->children[charIndex]) {
            node->children[charIndex] = new TrieNode();
        }
        insertUtil(node->children[charIndex], word, index + 1, stringNumber);
    }

    bool isPalindrome(string &s, int low, int high) {
        while (low <= high) {
            if (s[low] != s[high]) return false;
            low++, high--;
        }
        return true;
    }

    void searchCase2(TrieNode *node, vector<int> &myPalindrome, string s) {
        if (node->isTerminal) {
            if (isPalindrome(s, 0, s.size() - 1)) {
                myPalindrome.push_back(node->stringNumber);
            }
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                s.push_back(i + 'a');
                searchCase2(node->children[i], myPalindrome, s);
                s.pop_back();
            }
        }
    }

    void searchUtil(TrieNode *node, string &word, vector<int> &myPalindrome) {
        TrieNode *curr = node;

        // Case 1: When a prefix of 'word' exactly matches a word in the Trie
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (curr->stringNumber != -1) {
                if (isPalindrome(word, i, word.size() - 1)) {
                    myPalindrome.push_back(curr->stringNumber);
                }
            }
            if (!curr->children[index]) return;
            curr = curr->children[index];
        }

        // Case 2: 'word' is a prefix of a word in the Trie
        searchCase2(curr, myPalindrome, "");
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word, int stringNumber) {
        insertUtil(root, word, 0, stringNumber);
    }

    void search(string word, vector<int> &myPalindrome) {
        searchUtil(root, word, myPalindrome);
    }
};

vector<vector<int> > palindromePairs(vector<string> &words) {
    vector<vector<int> > ans;
    Trie trie;

    // Insert all words in reverse order into Trie
    for (int i = 0; i < words.size(); i++) {
        string reverseWord = words[i];
        reverse(reverseWord.begin(), reverseWord.end());
        trie.insert(reverseWord, i);
    }

    // Find palindrome pairs for each word
    for (int i = 0; i < words.size(); i++) {
        vector<int> myPalindrome;
        trie.search(words[i], myPalindrome);

        for (auto it : myPalindrome) {
            if (it != i) {
                vector<int> temp;  
                temp.push_back(i);
                temp.push_back(it);
                ans.push_back(temp);
            }
        }
    }

    return ans;
}

int main() {
    vector<string> words;
    words.push_back("bat");
    words.push_back("tab");
    words.push_back("cat"); 
    vector<vector<int> > result = palindromePairs(words);

    for (auto &pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "]\n";
    }

    return 0;
}
