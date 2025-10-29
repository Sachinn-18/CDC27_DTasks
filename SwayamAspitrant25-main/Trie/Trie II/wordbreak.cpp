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

bool wordBreakHelper(string s, int start, TrieNode* root, vector<bool>& dp) {
    if (start == s.size()) {
        return true;
    }
    if (dp[start] != -1) {
        return dp[start];
    }
    TrieNode* node = root;
    for (int i = start; i < s.size(); i++) {
        int index = s[i] - 'a';
        if (node->children[index] == nullptr) {
            break;
        }
        node = node->children[index];
        if (node->isEnd && wordBreakHelper(s, i + 1, root, dp)) {
            return dp[start] = true;
        }
    }
    return dp[start] = false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    TrieNode* root = new TrieNode();
    for (string word : wordDict) {
        insert(root, word);
    }
    vector<bool> dp(s.size(), -1);
    return wordBreakHelper(s, 0, root, dp);
}

int main() {
    vector<string> wordDict = {"leet", "code"};
    string s = "leetcode";
    bool result = wordBreak(s, wordDict);
    cout << "Can '" << s << "' be segmented? " << (result ? "Yes" : "No") << endl;

    s = "applepenapple";
    wordDict = {"apple", "pen"};
    result = wordBreak(s, wordDict);
    cout << "Can '" << s << "' be segmented? " << (result ? "Yes" : "No") << endl;

    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    result = wordBreak(s, wordDict);
    cout << "Can '" << s << "' be segmented? " << (result ? "Yes" : "No") << endl;

    return 0;
}
