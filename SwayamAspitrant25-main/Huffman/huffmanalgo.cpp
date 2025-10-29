#include <bits/stdc++.h>
using namespace std;

// Huffman Tree Node
struct Node {
    char data;
    int freq;
    Node *left, *right;
    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Custom comparator for priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to build Huffman tree
Node* buildHuffmanTree(map<char, int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& p : freq) {
        pq.push(new Node(p.first, p.second));
    }
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    return pq.top();
}

// Function to generate Huffman codes
void generateCodes(Node* root, string code, map<char, string>& codes) {
    if (!root) return;
    if (root->data != '\0') {
        codes[root->data] = code;
        return;
    }
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// Function to compress the string
string compress(string& input, map<char, string>& codes) {
    string compressed = "";
    for (char c : input) {
        compressed += codes[c];
    }
    return compressed;
}

int main() {
    string input;
    cout << "Enter the string to compress: ";
    getline(cin, input);

    // Compute frequency
    map<char, int> freq;
    for (char c : input) {
        freq[c]++;
    }

    // Build Huffman tree
    Node* root = buildHuffmanTree(freq);

    // Generate codes
    map<char, string> codes;
    generateCodes(root, "", codes);

    // Compress
    string compressed = compress(input, codes);

    // Output
    cout << "Huffman Codes:" << endl;
    for (auto& p : codes) {
        cout << p.first << ": " << p.second << endl;
    }
    cout << "Compressed string: " << compressed << endl;

    // Clean up memory (optional, but good practice)
    // Note: In a real implementation, you'd need a proper tree deletion

    return 0;
}
