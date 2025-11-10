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

    // Delete a word from the trie
    bool deleteWord(string word) {
        return deleteHelper(root, word, 0);
    }

private:
    bool deleteHelper(TrieNode* node, string& word, int index) {
        if (index == word.size()) {
            if (!node->isEndOfWord) return false;
            node->isEndOfWord = false;
            // Check if this node can be deleted (no children)
            bool hasChildren = false;
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    hasChildren = true;
                    break;
                }
            }
            return !hasChildren;
        }

        int idx = word[index] - 'a';
        if (node->children[idx] == nullptr) return false;

        bool canDeleteChild = deleteHelper(node->children[idx], word, index + 1);

        if (canDeleteChild) {
            delete node->children[idx];
            node->children[idx] = nullptr;
        }

        // Check if current node can be deleted
        bool hasChildren = false;
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                hasChildren = true;
                break;
            }
        }
        return !hasChildren && !node->isEndOfWord;
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

    // Search before delete
    cout << "Before delete:" << endl;
    cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'hell': " << (trie.search("hell") ? "Found" : "Not Found") << endl;
    cout << "Search 'world': " << (trie.search("world") ? "Found" : "Not Found") << endl;
    cout << "Search 'trie': " << (trie.search("trie") ? "Found" : "Not Found") << endl;

    // Delete "hello"
    trie.deleteWord("hello");

    // Search after delete
    cout << "\nAfter deleting 'hello':" << endl;
    cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'hell': " << (trie.search("hell") ? "Found" : "Not Found") << endl;
    cout << "Search 'world': " << (trie.search("world") ? "Found" : "Not Found") << endl;
    cout << "Search 'trie': " << (trie.search("trie") ? "Found" : "Not Found") << endl;

    // Delete "hell"
    trie.deleteWord("hell");

    // Search after delete
    cout << "\nAfter deleting 'hell':" << endl;
    cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'hell': " << (trie.search("hell") ? "Found" : "Not Found") << endl;
    cout << "Search 'world': " << (trie.search("world") ? "Found" : "Not Found") << endl;
    cout << "Search 'trie': " << (trie.search("trie") ? "Found" : "Not Found") << endl;

    return 0;
}
