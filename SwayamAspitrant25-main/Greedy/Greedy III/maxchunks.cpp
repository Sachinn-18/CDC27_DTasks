#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int chunks = 0, maxVal = 0;
    for (int i = 0; i < arr.size(); i++) {
        maxVal = max(maxVal, arr[i]);
        if (maxVal == i) chunks++;  // All elements till i can form a chunk
    }
    return chunks;
}

/*
Logic: For permutation of [0..n-1], a chunk can end at i if 
all elements till i are ≤ i (maxVal == i).
Greedy one-pass O(n).
*/
int main() {
    vector<int> arr = {1, 0, 2, 3, 4};
    cout << "Max Chunks: " << maxChunksToSorted(arr) << endl; // Output: 4
    return 0;
}