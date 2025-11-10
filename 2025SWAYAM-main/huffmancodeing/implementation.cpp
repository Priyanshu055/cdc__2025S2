#include <bits/stdc++.h>
using namespace std;

// Huffman Node structure
struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Custom comparator for priority queue (min-heap)
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

// Function to build frequency map
map<char, int> buildFreqMap(const string& text) {
    map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }
    return freq;
}

// Function to build Huffman tree
HuffmanNode* buildHuffmanTree(const map<char, int>& freq) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    // Create leaf nodes and add to priority queue
    for (auto& pair : freq) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Build the tree
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        HuffmanNode* internal = new HuffmanNode('\0', left->freq + right->freq);
        internal->left = left;
        internal->right = right;

        pq.push(internal);
    }

    return pq.top();
}

// Function to generate Huffman codes
void generateCodes(HuffmanNode* root, string code, map<char, string>& codes) {
    if (!root) return;

    if (!root->left && !root->right) {
        codes[root->data] = code;
        return;
    }

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// Function to encode the input string
string encode(const string& text, const map<char, string>& codes) {
    string encoded = "";
    for (char ch : text) {
        encoded += codes.at(ch);
    }
    return encoded;
}

// Function to decode the encoded string
string decode(const string& encoded, HuffmanNode* root) {
    string decoded = "";
    HuffmanNode* current = root;

    for (char bit : encoded) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (!current->left && !current->right) {
            decoded += current->data;
            current = root;
        }
    }

    return decoded;
}

// Function to delete the Huffman tree (memory cleanup)
void deleteTree(HuffmanNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string text = "huffman coding is fun";

    // Build frequency map
    map<char, int> freq = buildFreqMap(text);

    // Build Huffman tree
    HuffmanNode* root = buildHuffmanTree(freq);

    // Generate Huffman codes
    map<char, string> codes;
    generateCodes(root, "", codes);

    // Print Huffman codes
    cout << "Huffman Codes:" << endl;
    for (auto& pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Encode the text
    string encoded = encode(text, codes);
    cout << "\nOriginal text: " << text << endl;
    cout << "Encoded text: " << encoded << endl;

    // Decode the encoded text
    string decoded = decode(encoded, root);
    cout << "Decoded text: " << decoded << endl;

    // Check if decoding is correct
    if (text == decoded) {
        cout << "\nEncoding and decoding successful!" << endl;
    } else {
        cout << "\nError in encoding/decoding!" << endl;
    }

    // Clean up memory
    deleteTree(root);

    return 0;
}
