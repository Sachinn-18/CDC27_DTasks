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

int main() {
    TrieNode* root = new TrieNode();
    vector<string> words = {"hello", "world", "trie"};
    for (string word : words) {
        insert(root, word);
        cout << "Inserted: " << word << endl;
    }
    return 0;
}
