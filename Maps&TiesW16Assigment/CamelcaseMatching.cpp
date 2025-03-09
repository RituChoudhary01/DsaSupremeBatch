// CamelCase Matching
// https://leetcode.com/problems/camelcase-matching/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class TrieNode {
public:
    char data;
    TrieNode *children[58]; 
    bool isTerminal;

    TrieNode(char ch) : data(ch), isTerminal(false) {
        for (int i = 0; i < 58; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode *root;

    void insertUtil(TrieNode *node, string &word, int i) {
        if (i >= word.size()) {
            node->isTerminal = true;
            return;
        }
        int index = word[i] - 'A'; 
        if (!node->children[index]) {
            node->children[index] = new TrieNode(word[i]);
        }

        insertUtil(node->children[index], word, i + 1);
    }

    bool searchUtil(TrieNode *node, string &word, int i) {
        if (i >= word.size()) {
            return node->isTerminal;
        }

        char ch = word[i];
        int index = ch - 'A';

        if (isupper(ch)) { 
            if (!node->children[index]) return false;
            return searchUtil(node->children[index], word, i + 1);
        } 
        else { 
            return searchUtil(node, word, i + 1) || 
                   (node->children[index] && searchUtil(node->children[index], word, i + 1));
        }
    }

public:
    Trie() {
        root = new TrieNode('\0'); // Root node with null character
    }
     void insert(string word) {
        insertUtil(root, word, 0);
    }
     bool search(string word) {
        return searchUtil(root, word, 0);
    }
};

vector<bool> camelMatch(vector<string> &queries, string pattern) {
    vector<bool> ans;
    Trie trie;
    trie.insert(pattern);

    for (auto &query : queries) {
        ans.push_back(trie.search(query));
    }
    return ans;
}

int main() {
    vector<string> queries;
    queries.push_back("FooBar");
    queries.push_back("FooBaz");
    queries.push_back("FooBaT");
    queries.push_back("FoBa");
    queries.push_back("FBar");
    string pattern = "FB";
    vector<bool> result = camelMatch(queries, pattern);
    for (bool res : result) {
        cout << (res ? "true" : "false") << " ";
    }
    return 0;
}
