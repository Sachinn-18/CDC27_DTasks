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

void collectWords(TrieNode* node, string prefix, vector<string>& words) {
    if (node->isEnd) {
        words.push_back(prefix);
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            collectWords(node->children[i], prefix + char('a' + i), words);
        }
    }
}

vector<string> getWordsWithPrefix(TrieNode* root, string prefix) {
    TrieNode* node = root;
    vector<string> words;
    for (char ch : prefix) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return words; // No words with this prefix
        }
        node = node->children[index];
    }
    collectWords(node, prefix, words);
    return words;
}

int main() {
    TrieNode* root = new TrieNode();
    vector<string> words = {"apple", "app", "application", "bat", "ball", "cat"};
    for (string word : words) {
        insert(root, word);
        cout << "Inserted : " << word << endl;
    }

    string prefix = "app";
    vector<string> result = getWordsWithPrefix(root, prefix);
    cout << "Words with prefix '" << prefix << "': ";
    for (string word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
