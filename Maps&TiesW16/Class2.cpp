#include <iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d) {
        this->data = d;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
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
    } 
    else {
        // If not present, create a new node
        child = new TrieNode(ch);
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
    } 
    else {
        return false;
    }

    // Recursive call for the remaining word
    return searchWord(child, word.substr(1));
}

// Function to check if a node has children
bool hasChildren(TrieNode* node) {
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != NULL)
            return true;
    }
    return false;
}

// Function to delete a word from the Trie
bool deleteWord(TrieNode* root, string word){
    if (word.length() == 0){
        // If word exists, mark it as non-terminal
        if (root->isTerminal) {
            root->isTerminal = false;
            return !hasChildren(root); // Return true if node has no children (can be deleted)
        }
        return false; // Word not found
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child = root->children[index];

    if (child == NULL) {
        return false; // Word not found
    }

    bool shouldDeleteChild = deleteWord(child, word.substr(1));

    if (shouldDeleteChild) {
        delete child;
        root->children[index] = NULL;

        // Return true if root itself has no children and is not terminal
        return !hasChildren(root) && !root->isTerminal;
    }

    return false;
}

int main() {
    TrieNode* root = new TrieNode('-');

    // Insert words
    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babu");
    insertWord(root, "shona");

    // Searching words
    cout << "Searching 'cod': " << (searchWord(root, "cod") ? "Present" : "Absent") << endl;
    cout << "Searching 'coding': " << (searchWord(root, "coding") ? "Present" : "Absent") << endl;

    // Deleting words
    cout << "Deleting 'code': " << (deleteWord(root, "code") ? "Deleted" : "Not Found") << endl;
    cout << "Searching 'code': " << (searchWord(root, "code") ? "Present" : "Absent") << endl;

    cout << "Deleting 'coding': " << (deleteWord(root, "coding") ? "Deleted" : "Not Found") << endl;
    cout << "Searching 'coding': " << (searchWord(root, "coding") ? "Present" : "Absent") << endl;

    return 0;
}
