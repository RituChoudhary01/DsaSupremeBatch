// Replace Words
// https://leetcode.com/problems/replace-words/
#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch) : data(ch), isTerminal(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
    TrieNode *root;

    void insertUtil(TrieNode *root, string &word, int i) {
        if (i >= word.size()) {
            root->isTerminal = true;
            return;
        }
        int index = word[i] - 'a';
        if (!root->children[index]) {
            root->children[index] = new TrieNode(word[i]);
        }
        insertUtil(root->children[index], word, i + 1);
    }

    bool searchUtil(TrieNode *root, string &word, int i, int &matchedLength) {
        if (root->isTerminal) return true;
        if (i >= word.size()) return root->isTerminal;

        int index = word[i] - 'a';
        if (root->children[index]) {
            matchedLength = i + 1;
            return searchUtil(root->children[index], word, i + 1, matchedLength);
        }
        return false;
    }

    bool startWithUtil(TrieNode *root, string &word, int i) {
        if (i >= word.size()) return true;

        int index = word[i] - 'a';
        if (root->children[index]) {
            return startWithUtil(root->children[index], word, i + 1);
        }
        return false;
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        insertUtil(root, word, 0);
    }

    int search(string word) {
        int matchedLength = -1;
        if (searchUtil(root, word, 0, matchedLength)) {
            return matchedLength;
        }
        return -1;
    }

    bool startWith(string prefix) {
        return startWithUtil(root, prefix, 0);
    }

    string replaceWords(vector<string> &dictionary, string sentence) {
        string ans;
        Trie trie;

        // Insert dictionary words into Trie
        for (auto &rootWord : dictionary) {
            trie.insert(rootWord);
        }

        int start = 0, end = 0;
        while (end < sentence.size()) {
            if (sentence[end] == ' ' || end == sentence.size() - 1) {
                int len = (end == sentence.size() - 1) ? sentence.size() - start : end - start;
                string word = sentence.substr(start, len);

                int trieMatchIndex = trie.search(word);
                ans += (trieMatchIndex != -1) ? word.substr(0, trieMatchIndex) : word;

                if (sentence[end] == ' ') {
                    ans += " ";
                }
                start = end + 1;
            }
            end++;
        }
        return ans;
    }
};

// Driver Code
int main() {
    Trie trie;
    vector<string> dictionary;
    dictionary.push_back("cat");
    dictionary.push_back("rat");
    dictionary.push_back("bat");
    string sentence = "the cattle was rattled by the battery";

    cout << "Replaced Sentence: " << trie.replaceWords(dictionary, sentence) << endl;

    return 0;
}