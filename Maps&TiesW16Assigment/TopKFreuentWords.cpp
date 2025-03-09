// Top k Frequent words
// https://leetcode.com/problems/top-k-frequent-words/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class comp {
public:
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        return a.first == b.first ? a<b : a.first > b.first;
    }
};

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int freq;

    TrieNode(char ch) : data(ch), isTerminal(false) {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
            freq = 0;
    }
};

class Trie {
    TrieNode* root;

    void insertUtil(TrieNode* root, string& word, int i) {
        if (i >= word.size()) {
            root->isTerminal = true;
            root->freq++;
            return;
        }
        int index = word[i] - 'a';
        if (!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        insertUtil(root->children[index], word, i + 1);
    }

    void traverseUtil(TrieNode* root, string& s, priority_queue<pair<int, string>, vector<pair<int, string> >, comp>& pq, int k) {
        if (!root) return;

        if (root->isTerminal) {
            if (pq.size() < k) {
                pq.push(make_pair(root->freq, s));
            } else if (pq.size() == k && root->freq > pq.top().first) {
                pq.pop();
                pq.push(make_pair(root->freq, s));
            }
        }

        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                s.push_back(i + 'a');
                traverseUtil(root->children[i], s, pq, k);
                s.pop_back();
            }
        }
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        insertUtil(root, word, 0);
    }

    void traverse(priority_queue<pair<int, string>, vector<pair<int, string> >, comp>& pq, int k) {
        string s;
        traverseUtil(root, s, pq, k);
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    Trie trie;
    vector<string> ans;

    for (auto word : words) {
        trie.insert(word);
    }

    priority_queue<pair<int, string>, vector<pair<int, string> >, comp> pq;
    trie.traverse(pq, k);

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        ans.push_back(top.second);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
// Method 2
struct comp1 {
    bool operator()(const pair<int, string> &a, const pair<int, string> &b) {
        if (a.first == b.first) {
            return a.second > b.second; 
        }
        return a.first < b.first; 

    }
};
vector<string> topKFrequent1(vector<string> &words, int k) {
    unordered_map<string, int> mp;
    for (auto &word : words) {
        mp[word]++;
    }

    priority_queue<pair<int, string>, vector<pair<int, string> >, comp1> pq;
    for (auto &[word, freq] : mp) {
        pq.push(make_pair(freq, word));
    }

    vector<string> ans;
    while (k-- && !pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}
int main() {
    vector<string> words;
    words.push_back("i");
    words.push_back("love");
    words.push_back("leetcode");
    words.push_back("i");
    words.push_back("love");
    words.push_back("coding");
    int k = 2;

    vector<string> result = topKFrequent1(words, k);
    cout << "Top " << k << " frequent words: ";
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
