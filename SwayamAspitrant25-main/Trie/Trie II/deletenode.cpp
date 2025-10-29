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

bool isEmpty(TrieNode* node) {
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            return false;
        }
    }
    return true;
}

TrieNode* deleteHelper(TrieNode* node, string word, int depth) {
    if (node == nullptr) {
        return nullptr;
    }

    if (depth == word.size()) {
        if (node->isEnd) {
            node->isEnd = false;
        }
        if (isEmpty(node)) {
            delete node;
            node = nullptr;
        }
        return node;
    }

    int index = word[depth] - 'a';
    node->children[index] = deleteHelper(node->children[index], word, depth + 1);

    if (isEmpty(node) && !node->isEnd) {
        delete node;
        node = nullptr;
    }

    return node;
}

void deleteWord(TrieNode*& root, string word) {
    root = deleteHelper(root, word, 0);
}

int main() {
    TrieNode* root = new TrieNode();
    vector<string> words = {"hello", "world", "trie", "hell"};
    for (string word : words) {
        insert(root, word);
        cout << "Inserted: " << word << endl;
    }

    cout << "Before deletion:" << endl;
    cout << "Search 'hello': " << (search(root, "hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'hell': " << (search(root, "hell") ? "Found" : "Not Found") << endl;

    deleteWord(root, "hello");

    cout << "After deleting 'hello':" << endl;
    cout << "Search 'hello': " << (search(root, "hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'hell': " << (search(root, "hell") ? "Found" : "Not Found") << endl;

    return 0;
}
