#include <bits/stdc++.h>
using namespace std;

// Huffman Tree Node
struct Node {
    char data;
    Node *left, *right;
    Node(char data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to rebuild Huffman tree from codes
Node* rebuildTree(map<char, string>& codes) {
    Node* root = new Node('\0');
    for (auto& p : codes) {
        Node* current = root;
        for (char bit : p.second) {
            if (bit == '0') {
                if (!current->left) current->left = new Node('\0');
                current = current->left;
            } else {
                if (!current->right) current->right = new Node('\0');
                current = current->right;
            }
        }
        current->data = p.first;
    }
    return root;
}

// Function to decompress the string
string decompress(string& compressed, Node* root) {
    string result = "";
    Node* current = root;
    for (char bit : compressed) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->left == nullptr && current->right == nullptr) {
            result += current->data;
            current = root;
        }
    }
    return result;
}

int main() {
    // Read codes
    map<char, string> codes;
    string line;
    cout << "Enter Huffman codes (one per line, format: char:code, end with empty line):" << endl;
    while (getline(cin, line)) {
        if (line.empty()) break;
        size_t colon = line.find(':');
        if (colon != string::npos) {
            char ch = line[0];
            string code = line.substr(colon + 1);
            codes[ch] = code;
        }
    }

    // Read compressed string
    string compressed;
    cout << "Enter the compressed string: ";
    getline(cin, compressed);

    // Rebuild tree
    Node* root = rebuildTree(codes);

    // Decompress
    string original = decompress(compressed, root);

    // Output
    cout << "Decompressed string: " << original << endl;

    // Clean up memory (optional)

    return 0;
}
