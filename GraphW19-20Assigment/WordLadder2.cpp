// Word Ladder II
// https://www.geeksforgeeks.org/problems/word-ladder-ii/1

#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        queue<pair<vector<string>, int>> q;
        q.push({{beginWord}, 0});
        unordered_set<string> st(wordList.begin(), wordList.end());
        int preLevel = 0;
        vector<string> toBeRemoved;

        while (!q.empty()) {
            auto fNode = q.front();
            q.pop();
            vector<string> currSeq = fNode.first;
            string currString = currSeq.back();
            int currLevel = fNode.second;

            // If we reach a new level, remove used words from set
            if (currLevel != preLevel) {
                for (auto s : toBeRemoved) st.erase(s);
                toBeRemoved.clear();
                preLevel = currLevel;
            }

            // If we reach the endWord, store the sequence
            if (currString == endWord) {
                ans.push_back(currSeq);
                continue;
            }

            // Generate all possible next words
            for (int index = 0; index < currString.length(); index++) {
                char originalCharacter = currString[index];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == originalCharacter) continue;
                    string newWord = currString;
                    newWord[index] = ch;

                    // If the transformed word is in wordList
                    if (st.find(newWord) != st.end()) {
                        vector<string> temp = currSeq;
                        temp.push_back(newWord);
                        q.push({temp, currLevel + 1});
                        toBeRemoved.push_back(newWord);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit", endWord = "cog";

    Solution obj;
    vector<vector<string>> sequences = obj.findSequences(beginWord, endWord, wordList);

    cout << "Shortest Transformation Sequences: " << endl;
    for (auto& seq : sequences) {
        for (auto& word : seq) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
