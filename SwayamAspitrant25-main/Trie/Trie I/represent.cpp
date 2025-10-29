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

int main() {
    TrieNode* root = new TrieNode();
    cout << "TrieNode created successfully." << endl;
    return 0;
}
