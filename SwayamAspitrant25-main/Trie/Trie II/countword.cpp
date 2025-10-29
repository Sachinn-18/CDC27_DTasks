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

int countWords(TrieNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int count = node->isEnd ? 1 : 0;
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            count += countWords(node->children[i]);
        }
    }
    return count;
}

int main() {
    TrieNode* root = new TrieNode();
    vector<string> words = {"hello", "world", "trie", "hell", "heaven", "heavy"};
    for (string word : words) {
        insert(root, word);
        cout << "Inserted: " << word << endl;
    }

    int totalWords = countWords(root);
    cout << "Total number of words in trie: " << totalWords << endl;

    return 0;
}
