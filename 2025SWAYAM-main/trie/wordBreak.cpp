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
};

// Word Break function using Trie and DP
bool wordBreak(string s, vector<string>& wordDict) {
    Trie trie;
    for (auto& word : wordDict) {
        trie.insert(word);
    }
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && trie.search(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

// Main function for testing
int main() {
    vector<string> wordDict = {"leet", "code"};
    string s = "leetcode";
    cout << "Can '" << s << "' be broken? " << (wordBreak(s, wordDict) ? "Yes" : "No") << endl;

    s = "applepenapple";
    wordDict = {"apple", "pen"};
    cout << "Can '" << s << "' be broken? " << (wordBreak(s, wordDict) ? "Yes" : "No") << endl;

    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    cout << "Can '" << s << "' be broken? " << (wordBreak(s, wordDict) ? "Yes" : "No") << endl;

    return 0;
}
