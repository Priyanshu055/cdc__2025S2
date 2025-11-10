#include <bits/stdc++.h>
using namespace std;

// Trie Node representation
class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

// Trie class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the trie
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    // Count the number of words in the trie
    int countWords() {
        return countWordsHelper(root);
    }

private:
    int countWordsHelper(TrieNode* node) {
        if (node == nullptr) return 0;

        int count = 0;
        if (node->isEndOfWord) {
            count++;
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                count += countWordsHelper(node->children[i]);
            }
        }

        return count;
    }
};

// Main function for testing
int main() {
    Trie trie;

    // Insert words
    trie.insert("hello");
    trie.insert("world");
    trie.insert("trie");
    trie.insert("hell");
    trie.insert("help");

    // Count words
    cout << "Total words in trie: " << trie.countWords() << endl;

    // Search for words
    cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'world': " << (trie.search("world") ? "Found" : "Not Found") << endl;
    cout << "Search 'trie': " << (trie.search("trie") ? "Found" : "Not Found") << endl;
    cout << "Search 'hell': " << (trie.search("hell") ? "Found" : "Not Found") << endl;
    cout << "Search 'help': " << (trie.search("help") ? "Found" : "Not Found") << endl;

    return 0;
}
