/*
Q1.Debug the code.
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Orange";

    int key = 3;
    if (myMap.find(key)) {
        std::cout << "Key " << key << " exists." << std::endl;
    } else {
        std::cout << "Key " << key << " does not exist." << std::endl;
    }

    return 0;
}
Ans:-
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Orange";

    int key = 3;
    if (myMap.find(key)) {
        std::cout << "Key " << key << " exists." << std::endl;
    } else {
        std::cout << "Key " << key << " does not exist." << std::endl;
    }

    return 0;
}


Q2.Debug the code.
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> myMap;
    myMap["One"] = 1;
    myMap["Two"] = 2;
    myMap["Three"] = 3;

    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it.first << ": " << it.second << std::endl;
    }

    return 0;
}
Ans:-
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> myMap;
    myMap["One"] = 1;
    myMap["Two"] = 2;
    myMap["Three"] = 3;

    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
Q3.Debug the code. Merge K sorted arrays.
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Orange";

    int key = 4;
    std::cout << "Value for key " << key << ": " << myMap.at(key) << std::endl;

    return 0;
}
Ans:-
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Orange";

    int key = 4;
    if(myMap.find(key) != myMap.end())
    std::cout << "Value for key " << key << ": " << myMap.at(key) << std::endl;

    return 0;
}

Q4.Debug the code. Median in a stream of integers (running integers).
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
        if (it->first == 2) {
            myMap.erase(it);
        }
    }

    return 0;
}
Ans:-
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    for (auto it = myMap.begin(); it != myMap.end(); // no increment here) 
    {
        std::cout << it->first << ": " << it->second << std::endl;
        if (it->first == 2) {
            it = myMap.erase(it);
        } else {
            ++it;
        }
    }

    return 0;
}
// Q5.Debug the code. Median in a stream of integers (running integers).
#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = nullptr;
    }

    void insert(const std::string& word) {
        if (root == nullptr) {
            root = new TrieNode();
        }
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current = current->children[c];
            }
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return current->isEndOfWord;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("carrot");

    std::cout << trie.search("apple") << std::endl;
    std::cout << trie.search("banana") << std::endl;
    std::cout << trie.search("carrot") << std::endl;
    std::cout << trie.search("grape") << std::endl;

    return 0;
}
Ans:-
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return current->isEndOfWord;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("carrot");

    std::cout << trie.search("apple") << std::endl;
    std::cout << trie.search("banana") << std::endl;
    std::cout << trie.search("carrot") << std::endl;
    std::cout << trie.search("grape") << std::endl;

    return 0;
}
*/