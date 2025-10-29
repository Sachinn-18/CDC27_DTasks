#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

void insert(TrieNode* root, string word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEnd = true;
}

bool search(TrieNode* root, string word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }
        node = node->children[index];
    }
    return node->isEnd;
}

int main() {
    TrieNode* root = new TrieNode();
    vector<string> words = {"hello", "world", "trie"};
    for (string word : words) {
        insert(root, word);
    }
    vector<string> searchWords = {"hello", "world", "Trie", "notpresent"};
    for (string word : searchWords) {
        bool found = search(root, word);
        cout << "Search for '" << word << "': " << (found ? "Found" : "Not Found") << endl;
    }
    return 0;
}
